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
'*  short description : save and load passworded files
'*
'\******************************************************************************

testcase tFiledlgPasswords()
    
    dim workfile as string
    dim workpath as string
        workpath = hGetWorkPath()

    dim filetype as string
    dim filetypeID as string
    dim cMsg as string
        
    dim iCurrentDocumentType as integer
    dim iCurrentFileFormat as integer
        

    for iCurrentDocumentType = 1 to 6
    
        printlog( "Document Type: " & hNumericDocType( iCurrentDocumentType ) )
    
        for iCurrentFileFormat = 1 to 2
        
            select case iCurrentFileFormat
            case 1 : filetypeID = "645"
            case 2 : filetypeID = "current"
            end select
            
            hCreateDocument()
            
            kontext "Navigator"
            hCloseDialog( Navigator, "close,optional" )

            call hChangeDoc()

            printlog( "Open file-save dialog" )
            if ( gApplication = "IMPRESS" ) then
                printlog( "   IMPRESS is slower than other apps, delaying for 2 sec." )
                sleep( 2 )
            endif
            
            FileSave

            Kontext "SpeichernDlg"
            if ( SpeichernDlg.exists( 2 ) ) then

                filetype = hGetFilter( filetypeID )
                hSelectUIFilter( filetype )
                
                workfile = "password" & hGetSuffix( filetypeID )
                DateiName.setText( workpath & workfile )
                
                printlog( "Using fileformat: " & filetype )
                printlog( "Using filename..: " & workfile )

                printlog( "Check password" )
                if ( passwort.isEnabled() ) then
                    Passwort.check()
                else
                    warnlog( "#i36663# Password checkbox is disabled" )
                endif

                printlog( "Save the file" )
                Speichern.click()

                kontext "active"
                if ( active.exists( 2 ) ) then
                   printlog( "Handle overwrite warning (if any)" )
                   active.yes()
                endif
                

                Kontext "PasswordFileSave"
                printlog( "Enter the name of the file as password and confirm" )
                if ( passwordFileSave.exists() ) then
                    Password.settext( workfile )
                    PasswordConfirm.settext( workfile )
                    PasswordFileSave.ok()
                else
                    warnlog( "No password dialog is displayed" )
                endif
                
                kontext "AlienWarning"
                if ( AlienWarning.exists( 2 ) ) then
                    if ( FileTypeID <> "current" ) then
                        printlog( "Handle alienwarning (expected)" )
                        AlienWarning.ok()
                    else
                        warnlog( "Handle alienwarning (unexpected)" )
                        AlienWarning.ok()
                     endif         
                endif    

                hDestroyDocument()

                printlog( "Open the file via file-open" )
                FileOpen

                Kontext "OeffnenDlg"
                if ( OeffnenDlg.exists( 2 ) ) then
                    Dateiname.settext( workfile )

                    Oeffnen.click()

                    Kontext "PasswordFileOpen"
                    printlog( "Enter the filename as password" )
                    if ( PasswordFileOpen.exists( 4 ) ) then
                        PasswortName.settext( workfile )
                        PasswordFileOpen.ok()
                    else
                        kontext "Active"
                        if ( Active.exists( 2 ) ) then
                            cMsg = active.getText()
                            cMsg = hRemoveLineBreaks( cMsg )
                            printlog( cMsg )
	                        warnlog( "#i65889# - CWS Warnings01: Cannot read password protected files" )
                            active.ok()
                            goto endsub
                        else
                            warnlog( "No password dialog is displayed" )
                        endif
                    endif

                    printlog( "Verify that the document is loaded" )
                    hFileWait( FALSE )

                    Kontext "Navigator"
                    if ( Navigator.exists( 1 ) ) then
            	        qaerrorlog( "Navigator should not be visible - setting not saved?" )
            	    endif
	            else
	                warnlog( "Second file open failed" )
                endif
            else
                warnlog( "File Open dislog did not come up" )
            endif

            kontext "Navigator"
            hCloseDialog( Navigator, "close,optional" )

            hDestroyDocument()

            hDeleteFile( workpath & workfile )

            kontext "Navigator"
            hCloseDialog( Navigator, "close,optional" )
            
        next iCurrentFileFormat
        
    next iCurrentDocumentType



endcase
