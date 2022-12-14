'encoding UTF-8  Do not remove or change this line!
'*************************************************************************
'
'  Licensed to the Apache Software Foundation (ASF) under one
'  or more contributor license agreements.  See the NOTICE file
'  distributed with this work for additional information
'  regarding copyright ownership.  The ASF licenses this file
'  to you under the Apache License, Version 2.0 (the
'  "License"); you may not use this file except in compliance
'  with the License.  You may obtain a copy of the License at
'  
'    http://www.apache.org/licenses/LICENSE-2.0
'  
'  Unless required by applicable law or agreed to in writing,
'  software distributed under the License is distributed on an
'  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
'  KIND, either express or implied.  See the License for the
'  specific language governing permissions and limitations
'  under the License.
'
'*************************************************************************
'*
'* short description : Global resource tests for the menu: Help
'*
'*************************************************************************
'*
' #1 tHelpCheckForUpdates
'*
'\************************************************************************

testcase tHelpCheckForUpdates
    dim sTemp as string
    dim sIniFile as string
    dim i,a as integer
    dim bProxy as boolean
    dim bOnceAgain as boolean
    dim sProxyFile as string
    dim iOldProxy as integer

    bProxy = FALSE
    bOnceAgain = TRUE

    '/// open application ///'
    Call hNewDocument

    if gPlatGroup = "unx" then
        sIniFile = convertPath(gNetzOfficePath+"program/versionrc")
    else
        sIniFile = convertPath(gNetzOfficePath+"program\version.ini")
    endif
    sTemp = GetIniValue (sIniFile, "Version", "UpdateURL")
    if (sTemp <> "" AND NOT gOOO) then
        '/// choose Help -> Check for Updates... ///'
        while (bOnceAgain)
            if bProxy AND bOnceAgain then
                bOnceAgain = FALSE
            endif
            try
                HelpCheckForUpdates
            catch
                bOnceAgain = FALSE
                if (gtplatform = "sol") OR (gtplatform = "x86") or gOOO then
                    printlog "This could be a (patched) installation on Solaris Sparc/Intel or OOo - No Online Update Feature available."
                    hCloseDocument
                else
                    warnlog "Help->Check for Updates failed"
                    hCloseDocument
                endif
                goto endsub
            endcatch
            ' The dialog has to come up: 'Check for Updates'
            Kontext "CheckForUpdates"
            '            if CheckForUpdates.exists(10) then ' id not in build for dialog workaround: ' not working due to i 80859
            if Status.exists(10) then
                if sTemp <> "" then
                    printlog "'Check for Updates' came up"
                else
                    warnlog "'Check for Updates' came up, but the feature is disabled and the dialog hasn't to come up"
                    bOnceAgain = FALSE
                endif
                'dialogTest(CheckForUpdates) ' not working due to i 80859
                '/// A messagebox comes up with either CANCEL and/or OK -> press CANCEL or the only available button. ///'
                ' And will be overlayed soon by an 'active'
                Kontext
                if active.exists(6) then
                    printlog "Active text: '" + active.getText + "'"
                    try
                        active.cancel
                        printlog "Pressed CANCEL"
                    catch
                        active.ok
                        printlog "Pressed OK"
                    endcatch
                    bOnceAgain = FALSE
                else
                    bOnceAgain = FALSE
                    Kontext "CheckForUpdates"
                    try
                        CheckForUpdates.cancel
                    catch
                        'cancel button is no more availabale
                        printlog "cancel wasnt possible"
                        try
                            'CheckForUpdates.close
                            ' close method doesn't work
                            printlog "1:"+status.gettext
                            printlog "2:"+description.gettext
                            closebtn.click
                        catch
                            printlog "close wasnt possible"
                            ' last fallback
                            'printlog resetapplication
                            'hNewDocument
                            printlog "1:"+status.gettext
                            printlog "2:"+description.gettext
                            cancel.click
                        endcatch
                    endcatch
                endif
            else
                bOnceAgain = FALSE
                if sTemp <> "" then
                    if (gtplatform = "sol") OR (gtplatform = "x86") or gOOO then
                        printlog "This could be a (patched) installation on Solaris Sparc/Intel or OOo - No Online Update Feature available."
                    else
                        warnlog "Dialog didn't came up: 'Check for Updates'; URL that was called is: '" + sTemp + "'"
                    endif
                else
                    warnlog "Online Update Feature isn't available in this build, but calling Help -> Check for Updates is possible? (no 'UpdateURL' in file: '"+sIniFile+"')"
                endif
            endif
            ' Set proxy to get connection to update server
            if bProxy then
                ToolsOptions
                hToolsOptions("INTERNET","PROXY")
                Kontext "TabProxyServer"
                a = ProxyServer.getItemCount
                for i = 1 to a
                    printlog "(" + i + "/" + a + "): '" + ProxyServer.getItemText(i) + "'"
                next i
                ProxyServer.select(a) ' should be always manual
                if HttpProxy.isEnabled AND (privateProxyServer <> "") then
                    HttpProxy.setText privateProxyServer
                    HttpPort.setText cStr(privateProxyPort)
                    if bOnceAgain then
                        iOldProxy = ProxyServer.getSelIndex
                    else
                        ProxyServer.select(iOldProxy)
                    endif
                    Kontext "OptionenDlg"
                    OptionenDlg.OK
                else
                    if privateProxyServer <> "" then
                        warnLog "Wrong assumption that last entry is 'manual'! " + ProxyServer.getItemText(a)
                    else
                        qaErrorLog "Maybe you need to use a proxy server to connect to the internet."
                    endif
                    Kontext "OptionenDlg"
                    OptionenDlg.Cancel
                    bOnceAgain = FALSE
                endif
            endif
            bOnceAgain = FALSE
        wend
    else
        qaErrorlog "Test disabled, because it is OOo build and UpdateURL is empty and calling the slot would succeed"
    endif
    '/// close application ///'
    Call hCloseDocument
endcase

