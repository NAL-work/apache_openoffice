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
'*  short description : Options for extensions
'*
'\******************************************************************************

testcase tExtensionOptions1

    '///<h3>Options for extensions</h3>
    '///<ul>

    const EXTENSION_NAME = "leaf1.oxt" 
    const OPTIONS_ITEM   = "Writer leaf1 en-US"
    const ITEM_POS_1       = 2
    const ITEM_POS_2       = 35
    const ITEM_POS_2_ASIAN = 38
    
    dim cExtensionName as string

    dim cExtensionPath as string
        cExtensionPath = gTesttoolPath & "extensions\optional\input\options\"

    dim cExtensionFile as string
        cExtensionFile = convertpath( cExtensionPath & EXTENSION_NAME )
        
    dim irc as integer
    dim brc as boolean

    '///+<li>Create one single writer document, the node will be merged into it</li>
    do while ( getDocumentCount > 0 ) 
        hCloseDocument()
    loop
    gApplication = "WRITER"
    hNewDocument()
    kontext "DocumentWriter"
    DocumentWriter.typeKeys( "tExtensionOptions1" )
    
    
    '///+<li>Open the Extension Manager, click Add</li>
    '///+<li>Load the sample extension &quot;leaf1.oxt&quot;</li>    
    '///+<li>Close the Extension Manager</li>
    printlog( "Add sample extension" )
    hExtensionAddGUI( cExtensionFile, "verbose,InstallForUser" )

    '///+<li>Reopen the Extension Manager</li>
    printlog( "Reopen the Extension Manager" )
    ToolsPackageManager
    kontext "PackageManager"

    '///+<li>Select the extension by name</li>
    printlog( "Move from the top node to the sample extension" )
    BrowsePackages.select( EXTENSION_NAME )

    '///+<li>Test some control states for leaf1.oxt node</li>
    printlog( "Verify control states" )
    '///<ul>
    '///+<li>Add... (enabled)</li>
    if ( not Add.isEnabled() ) then  
        warnlog( "Add button should be enabled" )
    endif    
    
    '///+<li>Remove (enabled)</li>
    if ( not Remove.isEnabled() ) then
        warnlog( "Remove button should be enabled" )
    endif

    '///+<li>Enable (hidden)</li>
    if ( Enable.exists() ) then  
        warnlog( "Enable button should be hidden" )
    endif    

    '///+<li>Disable (enabled)</li>
    if ( not Disable.isEnabled() ) then
        warnlog( "Disable button should be enabled" )
    endif

    '///+<li>Updates... (enabled)</li>
    if ( not Updates.isEnabled() ) then
        warnlog( "Updates button should be enabled" )
    endif

    '///+<li>Options... (enabled)</li>
    if ( not Options.isEnabled() ) then
        warnlog( "Options button should be enabled" )
    endif
    '///</ul>

    '///+<li>Click on the Options... button</li>
    printlog( "Open Options dialog from Extension Manager" )
    kontext "PackageManager" 
    if ( options.exists() ) then
        options.click()
        
        '///+<li>Verify that the node &quot;leaf1&quot; is at pos 2 (absolute)</li>
        printlog( "Verify presence and position of the leaf node" )
        irc = hSelectOptionsItem( OPTIONS_ITEM , ITEM_POS_1 )
        if ( irc > 0 ) then
            warnlog( "Test failed" )
        endif
        
        '///+<li>Close Options dialog (cancel)
        printlog( "Cancel Options dialog to get back to the Extension Manager" )
        OptionenDlg.cancel()
        
    else
        warnlog( "Options button does not exist/implemented in CWS jl61" )
    endif

    '///+<li>Close the Extension Manager</li>
    kontext "PackageManager"
    printlog( "Close the Extension Manager" )
    PackageManager.close()
    
    '///+<li>Open Tools/Options</li>
    printlog( "From the document open Tools/Options" )
    ToolsOptions
    
    printlog( "Verify presence and position of the leaf node" )
    if ( bAsianLan ) then
        irc = hSelectOptionsItem( OPTIONS_ITEM , ITEM_POS_2_ASIAN )
    else
        irc = hSelectOptionsItem( OPTIONS_ITEM , ITEM_POS_2 )
    endif
    if ( irc > 1 ) then
        warnlog( "Node <" & OPTIONS_ITEM & "> was not found in Tools/Options" )
    else
        printlog( "Node is present. Good." )
    endif
    
    Kontext "OptionenDlg"
    printlog( "Cancel Tools/Options to get back to the document" )
    OptionenDlg.cancel()

    '///+<li>Cleanup: Remove the sample extension</li>
    printlog( "Remove sample extension" )
    hExtensionRemoveGUI( EXTENSION_NAME )
    
    '///+<li>Cleanup: Close document</li>
    do while ( getDocumentCount > 0 ) 
        hCloseDocument()
    loop

    '///<ul>
endcase

