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
'*  short description : Update test for the dialog export feature
'*
'\******************************************************************************

testcase tUpdtDialogExport

    printlog( "Update test for the dialog export feature" )

    dim brc as boolean
    dim cMsg as string
    
    dim cDlgName as string
        cDlgName = hGetWorkPath() & "DialogTest"
        
    const DLG_SUFFIX = ".xdl"
    
    hCreateDocument()

    printlog( "Test init: Setting up environment" )
    brc = hInitFormControls( "DialogExport" )
    if ( not brc ) then
        warnlog( "Failed to initialize BAIC IDE/Dialog editor, aborting" )
        goto endsub
    endif
    
    printlog( "Test begin" )
    kontext "DialogBar"
    if ( not DialogBar.exists() ) then
        warnlog( "DialogBar does not exist, aborting" )
        hClosebasicIDE()
        hDestroyDocument()
        goto endsub
    endif
    sleep(1)
    printlog( "Click the Export button on the DialogBar" )
    kontext "DialogBar"
    Export.click()
    
    kontext "ExportierenDlg"
    if ( not ExportierenDlg.exists( 1 ) ) then
        warnlog( "Export dialog is not open, aborting" )
        hCloseBasicIDE()
        hDestroyDocument()
        goto endsub
    endif
    
    printlog( "Export dialog is open. Good." )
    
    kontext "ExportierenDlg"
    DateiName.setText( cDlgName )
    Speichern.click()
    
    kontext "Active"
    if ( Active.exists() ) then
        cMsg = active.getText()
        cMsg = hRemoveLineBreaks( cMsg )
        printlog( "File appears to exist, overwriting: " & cMsg )
        Active.Yes()
    endif
    
    kontext "DialogBar"
    if ( not DialogBar.exists() ) then
        warnlog( "DialogBar is not visible, please check." )
    endif
    
    printlog( "Back on the Basic IDE / Dialog Editor. Good." )
        
    cDlgName = cDlgName & DLG_SUFFIX
    if ( dir( cDlgName ) = "" ) then
        warnlog( "The dialog was not saved to the expected location" )
    else
        hDeleteFile( cDlgName )
        printlog( "Dialog was exported and deleted. Good." )
    endif
    
    printlog( "Test end. Cleanup" )
    hCloseBasicIDE()
    hDestroyDocument()    

endcase

