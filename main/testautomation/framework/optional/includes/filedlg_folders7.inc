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
'* short description : check the internal file dialog ( 1. part )
'*
'\*****************************************************************************

testcase tUpOneLevel4


    dim iCurrentItem as Integer      ' increment variable
    dim iCurrentItemCount as Integer ' actual number of entries in dropdown menu
    
    
    ' The directory that we want to start in so we know how many steps we have
    ' to the filesystem root (cStartDir is always good for at least 8 steps)
    dim cStartDir as string
        cStartDir = gTesttoolPath & "framework\optional\input\filetest\level1\level2\level3"
        cStartDir = convertpath( cStartDir )
        
    ' This is the threshold of the directory defined above. Usually we will have 
    ' 9 as the expected number of directories but depending on the mountpoint
    ' of the testtool workdirectory the number may vary.
    dim iExpectedItemCount as Integer
        iExpectedItemCount = hGetDirTreeLevel( cStartDir )
        
        ' Windows has one more level (Drives)
        if ( gPlatGroup = "w95" ) then
            iExpectedItemCount = iExpectedItemCount + 1
        endif
        
    printlog( "Test context menu of the Level Up button on the FileOpen dialog" )
    printlog( "Current threshold: " & iExpectedItemCount )
    
    FileOpen
    
    Kontext "OeffnenDlg"
    Dateiname.SetText( cStartDir )
    Oeffnen.Click()
    
    UebergeordneterOrdner.Open()
    
    iCurrentItemCount = hMenuItemGetCount()
    Printlog( "Current itemcount: " & iCurrentItemCount )
    
    if ( iCurrentItemCount < iExpectedItemCount ) then
        warnlog( "Items missing in the menu." )
        printlog( "On Windows the node 'My Computer' might be missing" )
        printlog( "On UNIX filesystem root might be missing" )
    endif
    
    if ( iCurrentItemCount = iExpectedItemCount ) then
        printlog( "The number of entries in the context menu is correct" )
    endif
    
    if ( iCurrentItemCount > iExpectedItemCount ) then
        warnlog( "Found more menu-items than expected: " &  iCurrentItemCount)
    endif
    
    for iCurrentItem = 1 to iCurrentItemCount - 1
        
        iExpectedItemCount = iCurrentItemCount - iCurrentItem
        
        hMenuSelectNr ( 1 )
        
        kontext "OeffnenDlg"
        UebergeordneterOrdner.Open()
        
        if ( hMenuItemGetCount < iExpectedItemCount )  then
            printlog( "The number of entries is correct" )
        endif
        
        if ( hMenuItemGetCount > iExpectedItemCount )  then
            printlog( "The number of entries is correct" )
        endif
        
    next iCurrentItem
    
    hMenuSelectNr ( 1 )
    
    if ( iCurrentItemCount = 8 ) then
    
        kontext "OeffnenDlg"
        UebergeordneterOrdner.Click()

    endif
    
    kontext "OeffnenDlg"
    if ( UebergeordneterOrdner.isEnabled() ) then
        warnlog( "Level-Up is enabled, it should be disabled at filesystem root" )
        
    else
        printlog( "Good, button is disabled" )
    endif
    
    kontext "OeffnenDlg"
    OeffnenDlg.Cancel()
    
endcase


