'encoding UTF-8  Do not remove or change this line!
'**************************************************************
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
'**************************************************************
'*
'* short description : Resource Test for chart2 main menus
'*
'**************************************************************************************************
'*
' #1 tMainMenu          'Checking the count of menu entries in each menu
'*
'\*************************************************************************************************

testcase tMainMenu
    dim iCount as integer ' the numbers of the items in the menu.

    dim iMainMenuItemCount as integer
        iMainMenuItemCount = 21 : if ( gPlatform = "osx" ) then iMainMenuItemCount = 20

    dim iHelpMenuItemCount as integer
        iHelpMenuItemCount = 5  : if ( gPlatform = "osx" ) then iHelpMenuItemCount = 4
    
    dim iToolsMenuItemCount as integer
        iToolsMenuItemCount = 4  : if ( gPlatform = "osx" ) then iToolsMenuItemCount = 3
        'Options entry is called Preferences and resides in application MacOS X menu
    
    printlog "Close all document windows (File / Close)"
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop            
    printlog "File / New / Spreadsheet"    
    call hNewDocument
        
    printlog "insert a Chart Object"
    if fInsertOLE = FALSE then
        warnlog "It was not possible to insert a chart as OLE."
        Call hCloseDocument
    else
        Kontext "DocumentCalc"
        DocumentCalc.UseMenu        
        printlog "check if there are 21 items in the FILE menu."
        hMenuSelectNr(1) ' FILE        
        iCount = hMenuItemGetCount()        
        if (iCount <> iMainMenuItemCount ) then
            warnlog "There should be 20 or 21 items in the file menu but there are " + iCount + " items."
        end if        
        call hMenuClose() ' close the FILE menu

        printlog "check if there are 12 items in the FILE/NEW menu."
        DocumentCalc.UseMenu
        hMenuSelectNr(1) ' FILE
        hMenuSelectNr(1) ' NEW        
        iCount = hMenuItemGetCount()        
        if (iCount <> 12) then
            warnlog "There should 12 items in the FILE/NEW menu but there are " + iCount + " items."
        end if        
        call hMenuClose() ' close the FILE menu
                
        printlog "check if there are 8 items in the FILE/AUTOPILOT menu."        
        DocumentCalc.UseMenu        
        hMenuSelectNr(1) ' FILE
        hMenuSelectNr(4) ' AUTOPILOT        
        iCount = hMenuItemGetCount()
        if (iCount <> 8) then
            warnlog "There should 8 items in the FILE/AUTOPILOTS menu but there are " + iCount + " items."
        end if
        call hMenuClose()
                
        printlog "check if there are 5 items in the EDIT menu."
        DocumentCalc.UseMenu 
        hMenuSelectNr(2)        
        iCount = hMenuItemGetCount()
        if (iCount <> 5) then
            warnlog "There should 5 items in the edit menu but there are " + iCount + " items."
        end if
        call hMenuClose()
        
        printlog "check if there are 4 items in the VIEW menu."
        DocumentCalc.UseMenu 
        hMenuSelectNr(3)        
        iCount = hMenuItemGetCount()
        if (iCount <> 4) then
            warnlog "There should 4 items in the view menu but there are " + iCount + " items."
        end if
        call hMenuClose()
               
        printlog "check if there are 5 items in the VIEW/TOOLBAR menu."        
        DocumentCalc.UseMenu 
        hMenuSelectNr(3) ' VIEW        
        hMenuSelectNr(1) ' TOOLBAR
        iCount = hMenuItemGetCount()
        if (iCount <> 5) then
            warnlog "There should 5 items in the VIEW/TOOLBAR menu but there are " + iCount + " items."
        end if
        call hMenuClose()
        
        printlog "check if there are 9 items in the INSERT menu."
        DocumentCalc.UseMenu 
        hMenuSelectNr(4) 'INSERT       
        iCount = hMenuItemGetCount()
        if (iCount <> 9) then
            warnlog "There should 9 items in the INSERT menu but there are " + iCount + " items."
        end if
        call hMenuClose()
 
        printlog "check if there are 13 items in the FORMAT menu."
        DocumentCalc.UseMenu
        hMenuSelectNr(5) ' FORMAT        
        iCount = hMenuItemGetCount()        
        if (iCount <> 13) then
            warnlog "There should 13 items in the FORMAT menu but there are " + iCount + " items."
        end if

        printlog "check if there are 2 items in the FORMAT/ARRANGEMENT menu."
        DocumentCalc.UseMenu
        hMenuSelectNr(5) ' FORMAT
        hMenuSelectNr(3) ' ARRANGEMENT        
        iCount = hMenuItemGetCount()        
        if (iCount <> 2) then
            warnlog "There should 2 items in the FORMAT/ARRANGEMENT menu but there are " + iCount + " items."
        end if
        
        printlog "check if there are 6 items in the FORMAT/AXIS menu."
        DocumentCalc.UseMenu
        hMenuSelectNr(5) ' FORMAT
        hMenuSelectNr(6) ' AXIS        
        iCount = hMenuItemGetCount()        
        if (iCount <> 6) then
            warnlog "There should 6 items in the FORMAT/AXIS menu but there are " + iCount + " items."
        end if

        printlog "check if there are 7 items in the FORMAT/GRID menu."
        DocumentCalc.UseMenu
        hMenuSelectNr(5) ' FORMAT
        hMenuSelectNr(7) ' GRID        
        iCount = hMenuItemGetCount()        
        if (iCount <> 7) then
            warnlog "There should 7 items in the FORMAT/GRID menu but there are " + iCount + " items."
        end if
        
        printlog "check if there are 6 items in the FORMAT/Title menu."
        DocumentCalc.UseMenu
        hMenuSelectNr(5) ' FORMAT
        hMenuSelectNr(4) ' TITLE        
        iCount = hMenuItemGetCount()        
        if (iCount <> 8) then
            warnlog "There should 8 items in the FORMAT/Title menu but there are " + iCount + " items."
        end if

        printlog "check if there are " + iToolsMenuItemCount + " items in the TOOLS menu."        
        DocumentCalc.UseMenu 
        hMenuSelectNr(6)        
        iCount = hMenuItemGetCount()
        if (iCount <> iToolsMenuItemCount) then
            warnlog "There should " + iToolsMenuItemCount + " items in the tools menu but there are " + iCount + " items."
        end if
        call hMenuClose()
        
        printlog "check if there are 4 items in the TOOLS/MACRO menu."        
        DocumentCalc.UseMenu 
        hMenuSelectNr(6)
        hMenuSelectNr(1)        
        iCount = hMenuItemGetCount()
        if (iCount <> 4) then
            warnlog "There should 4 items in the TOOLS/MACRO menu but there are " + iCount + " items."
        end if
        call hMenuClose()
        
        printlog "check if there are 5 items in the WINDOW menu."        
        DocumentCalc.UseMenu 
        hMenuSelectNr(7)        
        iCount = hMenuItemGetCount()
        if (iCount <> 5) then
            warnlog "There should 5 items in the WINDOW menu but there are " + iCount + " items."
        end if
        call hMenuClose()
 
        printlog "check if there are 5 or 6 items in the HELP menu. Depends on if it's a patched version"        
        DocumentCalc.UseMenu 
        hMenuSelectNr(8)        
        iCount = hMenuItemGetCount()
        if (iCount <> ( iHelpMenuItemCount + 1 ) AND iCount <> iHelpMenuItemCount ) then
            warnlog "There should 5 OR 6 items in the HELP menu but there are " + iCount + " items."
        end if
        call hMenuClose()        
        call hCloseDocument
    end if
endcase


