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
'*  short description : Alternative ways to open file-dialogs / slot availablilty
'*
'\******************************************************************************

testcase tDialogTriggers


    
    dim cAcceleratorFileOpen as string
    dim cAcceleratorFileSave as string
    dim cAcceleratorFileSaveAs as string
    
    do while ( getDocumentCount > 0 ) 
        call hCloseDocument()
    loop
    
    cAcceleratorFileOpen   = hGetAccel( "FileOpen" )
    cAcceleratorFileSave   = hGetAccel( "FileSave" )
    cAcceleratorFileSaveAs = hGetAccel( "FileSaveAs" )


    printlog( "Test case 1: FileOpen should be possible from backing window (accelerator)" )

    kontext "DocumentBackground"
    if ( DocumentBackground.exists( 1 ) ) then
    
        DocumentBackground.typeKeys( cAcceleratorFileOpen )
        
        kontext "OeffnenDlg"
        if ( OeffnenDlg.exists( 1 ) ) then
            printlog( "File Open dialog is open. Good." )
            OeffnenDlg.cancel()
        else
            warnlog( "File Open dialog did not open." )
        endif
    else
        warnlog( "Backing window not found" )
    endif
    
    
    
    printlog( "Test case 2: File Save should not work from backing window (accelerator)" )

    kontext "DocumentBackground"
    if ( DocumentBackground.exists( 1 ) ) then
    
        DocumentBackground.typeKeys( cAcceleratorFileSave )
        
        kontext "SpeichernDlg"
        if ( SpeichernDlg.exists( 1 ) ) then
            warnlog( "File Save dialog should not open." )
            SpeichernDlg.cancel()
        else
            printlog( "File Open dialog is not open. Good." )
        endif
    else
        warnlog( "Backing window not found" )
    endif
    
    
    
    printlog( "Test case 3: File Save As should not work from backing window (accelerator)" )
    
    kontext "DocumentBackground"
    if ( DocumentBackground.exists( 1 ) ) then
    
        DocumentBackground.typeKeys( cAcceleratorFileSaveAs )
        
        kontext "SpeichernDlg"
        if ( SpeichernDlg.exists( 1 ) ) then
            warnlog( "File Save dialog should not open." )
            SpeichernDlg.cancel()
        else
            printlog( "File Open dialog is not open. Good." )
        endif
    else
        warnlog( "Backing window not found" )
    endif
    
    
    printlog( "Test case 4: FileOpen should be possible from backing window (slot)" )

    kontext "DocumentBackground"
    if ( DocumentBackground.exists( 1 ) ) then
    
        FileOpen
        
        kontext "OeffnenDlg"
        if ( OeffnenDlg.exists( 1 ) ) then
            printlog( "File Open dialog is open. Good." )
            OeffnenDlg.cancel()
        else
            warnlog( "File Open dialog did not open." )
        endif
    else
        warnlog( "Backing window not found" )
    endif
    
    
    
    printlog( "Test case 5: File Save should not work from backing window (slot)" )

    kontext "DocumentBackground"
    if ( DocumentBackground.exists( 1 ) ) then
    
        try
            FileSave
        
            kontext "SpeichernDlg"
            if ( SpeichernDlg.exists( 1 ) ) then
                warnlog( "File Save dialog should not open." )
                SpeichernDlg.cancel()
            else
                printlog( "File Open dialog is not open. Good." )
            endif
        catch
            printlog( "Slot blocked, good" )
        endcatch

    else
        warnlog( "Backing window not found" )
    endif
    
    
    
    printlog( "Test case 6: File Save As should not work from backing window (slot)" )
    
    kontext "DocumentBackground"
    if ( DocumentBackground.exists( 1 ) ) then
    
        try
            FileSaveAs
        
            kontext "SpeichernDlg"
            if ( SpeichernDlg.exists( 1 ) ) then
                warnlog( "File Save dialog should not open." )
                SpeichernDlg.cancel()
            else
                printlog( "File Open dialog is not open. Good." )
            endif
        catch
            printlog( "Slot blocked, good" )
        endcatch

    else
        warnlog( "Backing window not found" )
    endif
    
    


    
    gApplication = "WRITER"
    
    call hNewDocument()
    
    printlog( "Test case 7: File Save should not work from unmodified documents (accelerator)" )

    kontext "DocumentWriter"
    if ( DocumentWriter.exists( 1 ) ) then
    
        DocumentWriter.typeKeys( cAcceleratorFileSave )
        
        kontext "SpeichernDlg"
        if ( SpeichernDlg.exists( 1 ) ) then
            warnlog( "File Save dialog should not open." )
            SpeichernDlg.cancel()
        else
            printlog( "File Open dialog is not open. Good." )
        endif
    else
        warnlog( "Writer document not not found" )
    endif
    
    
    
    printlog( "Test case 8: File Save As should work from unmodified documents (accelerator)" )

    kontext "DocumentWriter"
    if ( DocumentWriter.exists( 1 ) ) then
    
        DocumentWriter.typeKeys( cAcceleratorFileSaveAs )
        
        kontext "SpeichernDlg"
        if ( SpeichernDlg.exists( 1 ) ) then
            printlog( "File Save dialog is open. Good." )
            SpeichernDlg.cancel()
        else
            warnlog( "File Open dialog is not open." )
        endif
    else
        warnlog( "Writer document not not found" )
    endif


    printlog( "Test case 9: File Save should not work from unmodified documents (slot)" )

    kontext "DocumentWriter"
    if ( DocumentWriter.exists( 1 ) ) then
    
        try
            FileSave
        
            kontext "SpeichernDlg"
            if ( SpeichernDlg.exists( 1 ) ) then
                warnlog( "File Save dialog should not open." )
                SpeichernDlg.cancel()
            else
                printlog( "File Save dialog is not open. Good." )
            endif
        catch
            printlog( "Slot blocked, good" )
        endcatch
    else
        warnlog( "Writer document not not found" )
    endif
    
    
    
    printlog( "Test case 10: File Save As should work from unmodified documents (slot)" )

    kontext "DocumentWriter"
    if ( DocumentWriter.exists( 1 ) ) then
    
        try
            FileSaveAs
        
            kontext "SpeichernDlg"
            if ( SpeichernDlg.exists( 1 ) ) then
                printlog( "File Save dialog is open. Good." )
                SpeichernDlg.cancel()
            else
                warnlog( "File Save dialog should open." )
            endif
        catch
            warnlog( "Slot blocked" )
        endcatch
    else
        warnlog( "Writer document not not found" )
    endif
    
    call hCloseDocument()

endcase

