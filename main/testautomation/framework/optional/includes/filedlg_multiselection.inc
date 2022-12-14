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
'*  short description : Select a huge number of documents and load
'*
'\******************************************************************************

testcase tFiledlgMultiselection1()

    printlog( "Stress test: Load a great number of documents simultaneously" )
    
    GLOBAL_USE_NEW_SLEEP = true
    
    ' This is a test requested by framework development to be used in multi-
    ' user environments like Terminal Servers. It is used to quickly create
    ' a certain load. Furthermore issues (mostly unconfirmed) have been reported
    ' that loading files using multiselection might lead to a crash.

    dim cWorkPath as string : cWorkPath = hGetWorkPath() & "multiselection"
    dim cMsg as string
        
    dim iCurrentFile as integer
    dim iOpenDocuments as integer
    dim lTime as long
    dim lWait as long
    dim lTimeSum as long
    dim iCurrentTime as long
    
    
    dim iDocType as integer
    dim iDocument as integer
    dim cFilter( 4 ) as string
        cFilter( 1 ) = "writer8"
        cFilter( 2 ) = "calc8"
        cFilter( 3 ) = "impress8"
        cFilter( 4 ) = "draw8"
        
    dim cFile as string
        
    dim brc as boolean
    
    const TESTFILE_COUNT = 60 ' the number of documents in cWorkPath
    const TESTFILE_TIMEOUT = 480000

    ' Minimum cleanup
    while( getDocumentCount > 0 ) 
        hCloseDocument()
    wend

    ' create the workdirectory
    mkdir( cWorkPath )
    
    ' dynamically create a bulk of files to be written to the work directory
    lTimeSum = 0
    
    for iDocType = 1 to 4
        hNumericDocType( iDocType )
        hNewDocument()
        hChangeDoc()
        lWait = 0
        for iDocument = 1 to 15
            cFile = cWorkPath & "\" & "test_" & cFilter( iDocType ) & iDocument
            lTime = getSystemTicks
            hFileSaveAsWithFilterKill( cFile, cFilter( iDocType ) )
            lWait = lWait + getSystemTicks - lTime
        next iDocument
        hCloseDocument()
        printlog( "Total time for saving 15 documents: " & lWait & " ms" )
        lTimeSum = lTimeSum + lWait
    next iDocType
    
    if ( getDocumentCount > 0 ) then
        warnlog( "Not all files were saved and closed" )
        goto endsub
    endif
    
    printlog( "Time for saving 60 documents: " & lTimeSum & " ms" )
    printlog( "Average time per document...: " & lTimeSum / TESTFILE_COUNT & " ms" )
            
    printlog( "FileOpen" )
    FileOpen

    printlog( "Go to the workdirectory: " & cWorkPath )
    kontext "OeffnenDlg"
    if ( OeffnenDlg.exists( 1 ) ) then
    
        DateiName.typeKeys( cWorkPath )
        Oeffnen.click()
        
        kontext "Active"
        if ( active.exists( 2 ) ) then
        	cMsg = active.getText()
        	cMsg = hRemoveLineBreaks( cMsg )
        	warnlog( "Unexpected messagebox: " & cMsg )
        	active.ok()
        	kontext "OeffnenDlg"
        	if ( OeffnenDlg.exists() ) then
            	OeffnenDlg.cancel()
            else
                warnlog( "File Open dialog is not visible" )
            endif
        	goto endsub
        endif
        
        printlog( "Select all documents and load them simultaneously" )
        kontext "OeffnenDlg"
        if ( OeffnenDlg.exists() ) then
        
            DateiAuswahl.typeKeys( "<HOME>" )
            DateiAuswahl.typeKeys( "<SHIFT END>" )
            Oeffnen.Click()
         
            lTime = GetSystemTicks
            iOpenDocuments = 0   
            while ( iOpenDocuments < TESTFILE_COUNT )
                iOpenDocuments = getDocumentCount()
                iCurrentTime = getSystemTicks - lTime
                
                ' exit the hard way
                if ( iCurrentTime > TESTFILE_TIMEOUT ) then
                    warnlog( "Loading files max wait time exceed (" & _
                              TESTFILE_TIMEOUT/1000 & "), aborting" )
                    goto endsub
                endif
            wend
            
            if ( iCurrentTime > 120000 ) then
                'Closed issue: qaerrorlog( "#i105289# Slow loading of files, should be less than 120 seconds on all platforms" )
                printlog( "Slow file loading (exceeds 120 seconds)" )
            endif
            lWait = getSystemTicks - lTime ' time diff

            printlog( "All documents loaded in " & lWait & " ms" )
            sleep()
            
            printlog( "Starting to close all documents" )
            for iCurrentFile = 1 to TESTFILE_COUNT
                FileClose
                sleep()
            next iCurrentFile
            printlog( "Finished closing documents" )
            
            if ( getDocumentCount > 0 ) then
            	warnlog( "Not all documents were closed." )
            	iOpenDocuments = getDocumentCount
            	for iCurrentFile = 1 to iOpenDocuments - 1
            		hCloseDocument()
                next iCurrentFile
            else
                printlog( "All documents have been closed. Test succeeded." )
            endif
            
            printlog( "Deleting work files..." )
            for iDocType = 1 to 4
                hNumericDocType( iDocType )
                for iDocument = 1 to 15
                    cFile = cWorkPath & "\" & "test_" & cFilter( iDocType ) & iDocument 
                    hDeleteFile( cFile )
                next iDocument
            next iDocType

            printlog( "Removing temporary work directory" )
            rmdir( cWorkPath )    
        else
            warnlog( "File Open dialog is not visible" )
        endif
    else
        warnlog( "File Open dialog did not open." )
    endif

endcase
