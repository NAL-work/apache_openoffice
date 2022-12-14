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
'* short description : Testcases to test the Help-Menu.
'*
'\******************************************************************************
sub id_009

    printLog Chr(13) + "---------    id_009    ----------"

    call tCheckIfTheHelpExists
    Call tmHelpContents
    Call tmHelpHelpAgent
    Call tmHelpTips
    Call tmHelpExtendedTips
    Call tmHelpAboutStarOffice

end sub
'------------------------------------------------------------------------------

testcase tmHelpHelpAgent
    Call hNewDocument
    hTBOtypeInDoc
    HelpHelpAgent         ' it's just a switch
    sleep 2
    HelpHelpAgent
    Call hCloseDocument
endcase 'tmHelpHelpAgent

'------------------------------------------------------------------------------

testcase tmHelpTips
   Call hNewDocument
   hTBOtypeInDoc
   HelpTips
   Sleep 2
   HelpTips
   Call hCloseDocument
endcase 'tmHelpTips

'------------------------------------------------------------------------------

testcase tmHelpExtendedTips
   Call hNewDocument
   hTBOtypeInDoc
   HelpEntendedHelp
   Sleep (2)
   HelpEntendedHelp
   Call hCloseDocument
endcase 'tmHelpExtendedTips

'------------------------------------------------------------------------------

testcase tmHelpAboutStarOffice
   Call hNewDocument
   hTBOtypeInDoc
   HelpAboutStarOffice
   Kontext "UeberStarMath"
   DialogTest (UeberStarMath)
   UeberStarMath.OK
   Call hCloseDocument
endcase 'tmHelpAboutStarOffice

'------------------------------------------------------------------------------

testcase tmHelpContents
    dim i as integer

    printlog "open application"
    Call hNewDocument
    printlog "Help->Contents"
    HelpContents
    sleep(8)
    kontext "StarOfficeHelp"
    if Not StarOfficeHelp.Exists then
        Warnlog "Help is not up!"
    else
        printlog "get the number of entries in the listbox 'select Help modul'"
        Printlog "HelpAbout: '" + HelpAbout.GetItemCount +"'"
        printlog "on the left half of the dialog:"
        printlog "change to the tabpage 'Contents'"
        TabControl.SetPage ContentPage
        printlog "get the number of entries in the listbox 'MAin help themes'"
        Printlog "SearchContent: '" + SearchContent.GetItemCount + "'"
        printlog "change to the tabpage 'Index'"
        TabControl.SetPage IndexPage
        printlog "get the number of entries in the listbox 'Search term'"
        Printlog "SearchIndex: '" + SearchIndex.GetItemCount + "'"
        sleep 5
        printlog "click on button 'Display'"
        DisplayIndex.Click
        sleep 5
        printlog "change to the tabpage 'Find'"
        TabControl.SetPage FindPage
        printlog "get the number of entries in the listbox 'Search term'"
        Printlog "SearchFind: '" + SearchFind.GetItemCount + "'"
        printlog "If the Search-Text-Field is empty - Check that the Find-button is deactivated"
        if SearchFind.GetSelText = "" then
            if FindButton.IsEnabled then
                warnlog "   The Find-Button should have been inactive, but was active."
            endif
        else
            warnlog "   The Search-Text-Field shouldn't contain any text. But contained: " + SearchFind.GetSelText
        endif
        printlog "Insert some irrelevant text to get 0 results from the search."
        SearchFind.SetText "Doobbidedooo"
        printlog "click on button 'Find'"
        FindButton.Click
        kontext
        printlog "Messagebox comes up about: 'No topics found.' say OK"
        if (active.exists (2) )then
            Printlog "active came up: '" + active.gettext + "'"
            active.ok
        endif
        kontext "StarOfficeHelp"
        printlog "check checkbox 'Complete words only' "
        FindFullWords.Check
        printlog "check checkbox 'Find in headings only' "
        FindInHeadingsOnly.Check
        printlog "get the number of entries in the listbox 'List of headings'"
        Printlog "Result: '" + Result.GetItemCount + "'"
        printlog "click on button 'Display'"
        DisplayFind.Click
        printlog "change to the tabpage 'Bookmarks'"
        TabControl.SetPage BookmarksPage
        printlog "get the number of entries in the listbox 'Bookmark list'"
        Printlog "Bookmarks: '" + Bookmarks.GetItemCount + "'"
        printlog "click on button 'Display'"
        DisplayBookmarks.Click
        printlog "on the right half of teh dialog:"
        Kontext "TB_Help"
        printlog "click on button 'Hide/Show Navigation Pane'"
        Index.Click
        sleep 1
        printlog "click on button 'Hide/Show Navigation Pane'"
        Index.Click
        sleep 1
        printlog "click on button 'First Page'"
        GoToStart.Click
        sleep 1
        printlog "click on button 'Previous Page'"
        Backward.Click
        sleep 1
        printlog "click on button 'Next Page'"
        Forward.Click
        sleep 1
        printlog "click on button 'Print ...'"
        PrintButton.Click
        sleep (1)
        kontext "Active"
        if Active.Exists( 2 ) then
            qaerrorlog "No default printer defined: " & Active.GetText
            Active.Ok
        end if
        kontext "Printing"
        if Printing.Exists( 2 ) then
            printlog "In the dialog 'Print' press the button 'Cancel'"
            Printing.cancel
        else
            warnlog "the Print-Dialogue didnt appear."
        end if
        Kontext "TB_Help"
        printlog "click on button 'Add to Bookmarks ...'"
        sleep 1
        SetBookmarks.Click
        sleep 1
        Kontext "AddBookmark"
        printlog "on the dialog 'Add to Bookmarks ...' get the text from the editfield 'Bookmark' and press button 'Cancel'"
        Printlog "Bookmarkname: '" + Bookmarkname.GetText + "'"
        AddBookmark.Cancel
        sleep 1
        '################ help display ################
        kontext "HelpContent"
        printlog "open the Context Menu of the Frame 'Help Content' and count the entries"
        HelpContent.OpenContextMenu
        sleep 1
        Printlog " i: " + hMenuItemGetCount
        hMenuClose()
        '################ right scroolbar ################
        kontext "HelpContent"
        printlog "click on button 'Previous Page'"
        if HelpContentUP.IsVisible then
            HelpContentUP.Click
            sleep 1
        endif
        printlog "click on button 'Navigation'"
        if HelpContentNAVIGATION.IsVisible then
            HelpContentNAVIGATION.Click
            sleep 1
        endif
        kontext "NavigationsFenster"
        printlog "on the toolbox 'Navigation' press the window close button 'X'"
        NavigationsFenster.Close
        sleep 1
        kontext "HelpContent"
        printlog "click on button 'Next Page'"
        if HelpContentDOWN.IsVisible then
            HelpContentDOWN.Click
            sleep 1
        endif
        kontext "StarOfficeHelp"
        printlog "close the help with the keys [strg]+[F4]"
        Printlog "trying to close the help now"
        try
            StarOfficeHelp.TypeKeys "<Mod1 F4>" ' strg F4   supported since bug  #103586#
        catch
            Warnlog "failed to close the help window :-("
        endcatch
        kontext "StarOfficeHelp"
        if StarOfficeHelp.Exists then
            warnlog "Help still up!"
        endif
    endif
    printlog "close application"
    Call hCloseDocument
endcase 'tmHelpContents

'------------------------------------------------------------------------------

testcase tCheckIfTheHelpExists
    printlog "open application"
    Call hNewDocument
    printlog "Bring up the help-window"
    HelpContents
    kontext "HelpContent"
    sleep (5)
    printlog "Press CTRL A and CTRL C to select all and then copy it."
    HelpContent.TypeKeys "<MOD1 A>"
    sleep (1)
    HelpContent.TypeKeys "<MOD1 C>"
    printlog "If the clipboard now is empty, then nothing were copied, which means we have a bug."
    if GetClipBoard = "" then
        Warnlog "No content in the Help-Content -view."
    else
        Printlog "The Help-Content -view contained content. Good."
    endif
    kontext "StarOfficeHelp"
    printlog "Press CTRL F4 to close the help-window."
    try
        StarOfficeHelp.TypeKeys "<MOD1 F4>"
    catch
        Warnlog "   Failed to close the help window :-("
    endcatch
    kontext "StarOfficeHelp"
    if StarOfficeHelp.Exists then
        warnlog "Help was still visible!"
    endif
    printlog "And a dot into the main window. Making sure kontext and focus is right."
    hTypeKeys "."
    printlog "Close Application"
    Call hCloseDocument
endcase 'tCheckIfTheHelpExists

'------------------------------------------------------------------------------
