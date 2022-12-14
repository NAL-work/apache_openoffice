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
'* short description : Display each help topic
'*
'\******************************************************************************

testcase tHelpRessourceTest( iCurrentAboutItem as integer )

    printlog( "Resource test for help topics - display all topics" )

    dim iTopicCount as integer
    dim iCurrentTopic as integer
    dim cCurrentTopic as string
    dim cPreviousTopic as string
    dim cCurrentAboutItem as string
    dim brc as boolean
   
    brc = hOpenHelp()
    if ( not brc ) then
        warnlog( "Help not open, aborting test" )
        goto endsub
    endif

    brc = hSelectHelpTab( "index" )
    if ( not brc ) then
        warnlog( "There was a problem switching to the index tabpage" )
    endif

    Kontext "IndexPage"
    HelpAbout.select( iCurrentAboutItem )
    sleep( 3 )

    cCurrentAboutItem = HelpAbout.getSelText()
    printlog( " " )
    printlog( " * Current Application: " & cCurrentAboutItem )

    iTopicCount = SearchIndex.getItemcount()
    printlog( "For this application " & iTopicCount & " pages will be loaded." )
    printlog( " " )

    cPreviousTopic = "<not yet set>"
    for iCurrentTopic = 1 to iTopicCount 

        try
            SearchIndex.Select( iCurrentTopic )
            cCurrentTopic = SearchIndex.getSelText() 
        catch
            warnlog( "Failed to select entry at " & iCurrentTopic )
            printlog( "Previous entry: " & cPreviousTopic )
            exit for
        endcatch

        try
            DisplayIndex.click()
            WaitSlot( 5000 )
        catch
            warnlog( "#i105476# - Failed to display index item (fatal):" )
            printlog( " - Index...........: " & iCurrentTopic  )
            printlog( " - Topic (current).: " & cCurrentTopic  )
            printlog( " - Topic (previous): " & cPreviousTopic )
            call ExitRestartTheOffice()
            goto endsub
        endcatch
       
        cPreviousTopic = cCurrentTopic

    next iCurrentTopic

    brc =  hCloseHelp()
    if ( not brc ) then
        warnlog( "There was a problem closing the help viewer" )
    endif
   
    call ExitRestartTheOffice()
   
endcase


