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
'*  short description : Autocompletion feature
'*
'\******************************************************************************

testcase tAutocomplete

    printlog( "Autocompletion in the OpenOffice.org file picker" )
    
    ' IMPORTANT NOTE: Autocompletion is asynchronous. This means that no rule 
    '                 exists when exactly it is going to strike. If you are
    '                 using a networked environment you have to make sure that
    '                 all network ressources deliver a decent performance as 
    '                 this seriously influences the speed of the autocompletion.

    ' Assemble a work directory path        
    const WORKDIR = "autocomplete"
    dim cBasePath as string : cBasePath = hGetWorkPath()
    dim cWorkDir as string : cWorkDir = cBasePath & WORKDIR
        
    ' These are the files we create in the users homedirectory
    dim aWorkFile( 3 ) as string
        aWorkFile( 1 ) = "autocomplete_a.odt"
        aWorkFile( 2 ) = "autocomplete_b.odt"
        aWorkFile( 3 ) = "autocomplete_bb.odt"
        
    ' These are the full paths to the files
    dim aFullPath( 3 ) as string
        
    ' These are the wildcarded filter strings
    dim aWildCard( 3 )
        aWildCard( 1 ) = "autocomplete_?.odt"
        aWildCard( 2 ) = "autocomplete_b?.odt"
        aWildCard( 3 ) = "autocomplete_*.odt"
        
    dim cCurrentPath as string
    dim cAutocomplete as string
    
    dim iCurrentDocument as integer
            
    dim cLeft as string
    dim iLeft as integer
        iLeft = 4
        
    dim cEFString as string
    
    dim slot
        
    printlog( "Close all open documents" )
    hFileCloseAll()
    
    printlog( "Assemble 3 filenames for workfiles" )
    aFullPath( 1 ) = cWorkDir & gPathSigne & aWorkFile( 1 )
    aFullPath( 2 ) = cWorkDir & gPathSigne & aWorkFile( 2 )
    aFullPath( 3 ) = cWorkDir & gPathSigne & aWorkFile( 3 )
    
    printlog( "Delete the 3 workfiles if they exist" )
    hDeleteFile( aFullPath( 1 ) )
    hDeleteFile( aFullPath( 2 ) )
    hDeleteFile( aFullPath( 3 ) )
    
    printlog( "Try to remove conflicting work directories" )
    if ( dir( cBasePath & WORKDIR ) <> "" ) then
        rmdir( cWorkDir )
    endif
        
    printlog( "Create workdirectory: " & cWorkDir )
    mkdir( cWorkDir )
    if ( NOT FileExists( cWorkDir ) ) then
        warnlog( "Failed to create work directory, aborting" )
        goto endsub
    endif
    
    gApplication = "WRITER"
    printlog( "Create the workfiles - 3 writer files with minimum content" )
    for iCurrentDocument = 1 to 3
        call hCreateDocument()
        kontext "DocumentWriter"
        DocumentWriter.typeKeys( aWorkFile( iCurrentDocument ) )
        hFileSaveAs( aFullPath( iCurrentDocument ) )
        hUseAsyncSlot( "FileClose" )
    next iCurrentDocument
    
    printlog( "Open the File Open dialog" )
    hUseAsyncSlot( "FileOpen" )

    kontext "OeffnenDlg"
    printlog( "Click the <Standard> button to get to the default work directory" )
    Standard.click()
    
    cLeft     = left( WORKDIR, iLeft )
    cEFString = convertpath( WORKDIR & "/" )
    printlog( "Type """ & cLeft & """ into the filename entryfield" )
    DateiName.typeKeys( cLeft )
    
    printlog( "Press the <END> key and wait for two seconds" )
    DateiName.typeKeys( "<END>" )
    sleep( 1 ) ' Required, do not remove
    
    cAutocomplete = DateiName.getSelText()
    if ( cEFString = cAutocomplete ) then
        printlog( "Autocompletion succeeded for workdirectory" )
    else
        warnlog( "Autocompletion failed" )
        printlog( "Expected: " & cEFString )
        printlog( "Found...: " & cAutocomplete )
    endif
    
    printlog( "Press <RETURN> on the file open dialog -> Open"
    kontext "OeffnenDlg"
    OeffnenDlg.typeKeys( "<RETURN>" )
    
    printlog( "Type "" auto "" into the entryfield" )
    cLeft = left( aWorkFile( 1 ), 4 )
    DateiName.typeKeys( cLeft )
    sleep( 1 )
    
    cAutocomplete = DateiName.getSelText()
    if ( aWorkFile( 1 ) = cAutocomplete ) then
        printlog( "Autocompletion succeeded for first file" )
    else
        warnlog( "Autocompletion failed" )
        printlog( "Expected: " & cEFString )
        printlog( "Found...: " & cAutocomplete )
    endif   

    printlog( "Press down key in entry field" )
    DateiName.typeKeys( "<DOWN>" ) 
    sleep( 1 )
    
    cAutocomplete = DateiName.getSelText()
    if ( aWorkFile( 2 ) = cAutocomplete ) then
        printlog( "Autocompletion succeeded for second file" )
    else
        warnlog( "Autocompletion failed" )
        printlog( "Expected: " & cEFString )
        printlog( "Found...: " & cAutocomplete )
    endif

    printlog( "Enter autocomplete_?.odt -> 2 matches expected" )
    Dateiname.setText( aWildCard( 1 ) )
    Oeffnen.click()
    if ( DateiAuswahl.getItemCount() <> 2 ) then
        warnlog( "Incorrect number of files displayed, 2 expected" )
    else
        printlog( "Correct number of files listed in files-list" )
    endif
    
    printlog( "Enter autocomplete_b?.odt -> 1 match expected" )
    Dateiname.setText( aWildCard( 2 ) )
    Oeffnen.click()
    if ( DateiAuswahl.getItemCount() <> 1 ) then
        warnlog( "Incorrect number of files displayed, 1 expected" )
    else
        printlog( "Correct number of files listed in files-list" )
    endif
    
    printlog( "Enter autocomplete_*.odt -> 3 matches expected" )
    Dateiname.setText( aWildCard( 3 ) )
    Oeffnen.click()
    if ( DateiAuswahl.getItemCount() <> 3 ) then
        warnlog( "Incorrect number of files displayed, 3 expected" )
    else
        printlog( "Correct number of files listed in files-list" )
    endif
    
    
    printlog( "Close File Open dialog" )
    kontext "OeffnenDlg"
    OeffnenDlg.cancel()
    
    printlog( "Delete workfiles and -directory" )
    hDeleteFile( aFullPath( 1 ) )
    hDeleteFile( aFullPath( 2 ) )
    hDeleteFile( aFullPath( 3 ) )
    rmdir( cBasePath & WORKDIR )

endcase

