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
'* short description : test the Main Query Application Window
'*
'************************************************************************
'*
' #1 tMainMenuBar
' #1 tExecute
' #1 tClearQuery
' #1 tAddTable
' #1 tSwitchDesign
' #1 tNativeSQL
' #1 tFunctions
' #1 tTableName
' #1 tAliasName
' #1 tDistinctvalues
' #1 tEdit    
' #1 tCut
' #1 tCopy    
' #1 tPaste
' #1 tUndo    
'*
'\***********************************************************************************
sub Query

    printlog "------------------ Query.inc ---------------------"
    
    printlog "-------------------- main menu -------------------------"
    call tMainMenuBar
    
    printlog "--------------------- toolbar --------------------------"
    call tExecute
    call tClearQuery
    call tAddTable
    call tSwitchDesign
    call tNativeSQL
    call tFunctions
    call tTableName
    call tAliasName
    call tDistinctvalues
    call tEdit    
    call tCut
    call tCopy    
    call tPaste
    call tUndo
    
end sub
'-------------------------------------------------------------------------
testcase tClearQuery
   
    dim sTableName as String
    
    initQueryDesign
    
    Kontext "AddTables"
        if not AddTables.Exists(5) then
            warnlog "The Add Table dialog doesn't appear."
            goto endsub
        end if
        sTableName = TableName.GetSelText
        printlog "- Add 'biblio' table to query design"
        if sTableName <> "biblio" then
            warnlog "It should be the 'biblio'-database table but it is the '" + sTableName  + "' database table?!"
            goto endsub
        else
            AddTable.Click
            sleep(2)
        end if
        Kontext "Toolbar"
            printlog "- Deleting query"
            ClearQuery.Click
            sleep(5)
        Kontext "Toolbar"
            if ClearQuery.IsEnabled = TRUE then
                warnlog "'Delete Query' button should be disabled after using it!"
            end if
        
        call fCloseQueryDesign
        call fCloseDatabase
        
endcase
'-------------------------------------------------------------------------
testcase tNativeSQL

    dim sTableName as String
    
    initQueryDesign
    
    Kontext "AddTables"
        '/// close the add table dialog
        printlog "close the add table dialog"        
        if AddTables.Exists(5) then
            CloseDlg.Click
        end if    
        '/// switch to the SQL View and turn on the native SQL mode
        printlog "switch to the SQL View and turn on the native SQL mode"    
        Kontext "Toolbar"
            sleep(1)
            DesignView.Click
            sleep(1)
        Kontext "Sqlobjectbar"
            NativeSQL.Click
            '/// check if the design view icon is disabled
        Kontext "Toolbar"        
            if DesignView.isEnabled then
                warnlog "The designview icon is enabled, but in Native SQL it mustn't"
            end if
            sleep(2)       

        Kontext "Sqlobjectbar"
            NativeSQL.Click
            
        Kontext "Toolbar"            
            DesignView.Click
                        
        call fCloseQueryDesign
        call fCloseDatabase

endcase
'-------------------------------------------------------------------------
testcase tSwitchDesign

    dim sTableName as String
    
    call initQueryDesign
    
    Kontext "AddTables"
        if AddTables.Exists(5) then
            sTableName = TableName.GetSelText
            printlog "- Add 'biblio' table to query design"
            if sTableName <> "biblio" then
                warnlog "It should be the 'biblio'-database table but it is the '" & sTableName  & "' database table?!"
                goto endsub
            else
                AddTable.Click
                sleep(2)
            end if
            Kontext "Toolbar"
                printlog "- Design view clicked"
                DesignView.Click
                sleep(5)
            Kontext "QueryEditWindow"
                if QueryEditWindow.IsVisible = FALSE then
                    warnlog "The design window has not been disabled by clicking 'Design view' button!"
                else
                    Kontext "Toolbar"
                    printlog "- Design view cliecked to switch back"
                    DesignView.Click
                    Kontext "QueryDesignTable"
                    if QueryDesignTable.IsVisible = FALSE then
                        warnlog "Switching back to 'design view' failed!"
                    end if
                end if
        end if
        
        call fCloseQueryDesign
        call fCloseDatabase
        
endcase
'-------------------------------------------------------------------------
testcase tTableName

    call initQueryDesign
    
    Kontext "AddTables"
        if AddTables.Exists(5) then
            TableName.Select 1
            AddTable.Click
        else
        	warnlog "AddTables doesn't exists"
        end if
    sleep(1)
    Kontext "QueryDesignCriterion"
        QueryDesignCriterion.TypeKeys "<MOD1 PAGEUP>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "Type" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<DOWN>" , 6 , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "test" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<DOWN>" , true
        sleep(1)        
    '/// turn off the table name field
    printlog "turn off the table name field"        
    Kontext "Designobjectbar"    
        if Designobjectbar.exists(1) then
            DBViewTableNames.Click
            sleep(1)
        else
            warnlog "The Designobjectbar toolbar isn't visible."
        end if    
    '/// check if the table field still there
    printlog "check if the table field still there" 
    sleep(1)       
    Kontext "QueryDesignCriterion"
        QueryDesignCriterion.TypeKeys "<MOD1 PAGEUP>" , true
        sleep(1)        
        QueryDesignCriterion.TypeKeys "<DOWN>" , 6 , true        
        sleep(1)        
        QueryDesignCriterion.TypeKeys "<HOME>" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<SHIFT END>" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<MOD1 C>" , true
        sleep(1)            
        if getClipboard = "'test'" then
            warnlog "TableName still there but I have switch them off"
        end if

    call fCloseQueryDesign
    call fCloseDatabase

endcase
'-------------------------------------------------------------------------
'-------------------------------------------------------------------------
testcase tExecute
   
    dim sTableName as String

    call initQueryDesign
    
    Kontext "AddTables"
        if AddTables.Exists(5) then
            '/// Adding biblio table to query design.
            printlog "Adding biblio table to query design."
            sTableName = TableName.GetSelText
            printlog "- Add 'biblio' table to query design"
            if sTableName <> "biblio" then
                warnlog "It should be the 'biblio'-database table but it is the '" + sTableName  + "' database table?!"
                goto endsub
            else
                AddTable.Click
                sleep(2)
            end if
        end if
    Kontext "QueryDesignTable"
        printlog "- Changing window"
        '/// Switching with <b>&lt;F6&gt;</b> to <i>criterion</i> window (<a href="http://so-web4.germany.sun.com/eis/servlet/qa.FeatureEditServlet?Id=1168">feature 1168</a>)  .
        QueryDesignTable.TypeKeys "<F6>" , TRUE
    Kontext "QueryDesignCriterion"
        printlog "- Selecting 'field' as criteria"
        '/// Selecting field as criteria.
        sleep( 1 )
        Field.Select(2)
        sleep(1)
        '/// Typing <b>&lt;TAB&gt;</b> to switch to the <i>tool bar</i>.
        QueryDesignCriterion.TypeKeys "<TAB>" , TRUE
        sleep(1)
    Kontext "Toolbar"
        printlog "- Executing query"
        '/// Ececuting query. 
        ExecuteBtn.Click
        sleep(5)
    Kontext "TableView"
        '/// Verifying that <i>database beamer</i> (=result) is available.
        if NOT TableView.Exists(3) then
            warnlog "Execution of a query failed!"
        end if
    
    call fCloseQueryDesign
    call fCloseDatabase
    
endcase
'-------------------------------------------------------------------------
testcase tAddTable
   
    dim sTableName as String
    
    call initQueryDesign
    
    '/// close the add table dialog
    printlog "close the add table dialog"
    Kontext "AddTables"
    if AddTables.Exists(5) then
        CloseDlg.Click
    end if    
    '/// click on the add table icon in the toolbar of the query design
    printlog "click on the add table icon in the toolbar of the query design"
    Kontext "Designobjectbar"
        sleep(1)
        if Designobjectbar.exists(1) then
            AddTables.Click
            sleep(1)
        else
            warnlog "The Designobjectbar toolbar isn't visible."
        end if
        '/// check if the dialog opens
        printlog "check if the dialog opens"
    Kontext "AddTables"
    if AddTables.Exists(5) then
        CloseDlg.Click
    else
        warnlog "The AddTable dialog doesn't open" 
    end if        
    
    call fCloseQueryDesign
    call fCloseDatabase
    
endcase
'-------------------------------------------------------------------------
testcase tFunctions

    initQueryDesign
    
    Kontext "AddTables"
        if AddTables.Exists(5) then
            TableName.Select 1
            AddTable.Click
        end if
        sleep(1)
    Kontext "QueryDesignCriterion"
        QueryDesignCriterion.TypeKeys "<MOD1 PAGEUP>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "Type" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<DOWN>" , 6 , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "test" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<DOWN>" , true
        sleep(1)        
        '/// turn off the function field
        printlog "turn off the function field"    
    Kontext "Designobjectbar"
        if Designobjectbar.exists(1) then
            DBViewFunctions.Click
            sleep(1)
        else
            warnlog "The Designobjectbar toolbar isn't visible."
        end if
        
        sleep(1)
        '/// check if the function field still there
        printlog "check if the function field still there" 
        sleep(1)
    Kontext "QueryDesignCriterion"
        QueryDesignCriterion.TypeKeys "<MOD1 PAGEUP>" , true
        sleep(1)        
        QueryDesignCriterion.TypeKeys "<DOWN>" , 6 , true        
        sleep(1)        
        QueryDesignCriterion.TypeKeys "<HOME>" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<SHIFT END>" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<MOD1 C>" , true
        sleep(1)            
        if getClipboard = "'test'" then
            warnlog "Functions still there but I have switch them off"
        end if        

    call fCloseQueryDesign
    call fCloseDatabase        
        
endcase
'-------------------------------------------------------------------------
testcase tAliasName

    initQueryDesign
    
    Kontext "AddTables"
        if AddTables.Exists(5) then
            CloseDlg.Click
        end if
    '/// insert any aliasname into the alias field
    printlog "insert any aliasname into the alias field"
    sleep(1)
    Kontext "QueryDesignCriterion"
        QueryDesignCriterion.TypeKeys "<MOD1 PAGEUP>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "<DOWN>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "test" , true
        sleep(1)
    '/// turn off the alias field
    printlog "turn off the alias field"
    Kontext "Designobjectbar"
        if Designobjectbar.exists(1) then
            DBViewAliases.Click
            sleep(1)
        else
            warnlog "The Designobjectbar toolbar isn't visible."
        end if
        sleep(1)
    '/// check if the alias field still there
    printlog "check if the alias field still there"
    sleep(1)
    Kontext "QueryDesignCriterion"
        QueryDesignCriterion.TypeKeys "<MOD1 PAGEUP>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "<DOWN>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "<HOME>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "<SHIFT END>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "<MOD1 C>" , true
        sleep(1)            
        if getClipboard = "test" then
            warnlog "Alias still there but I have switch them off"
        end if        
    
    call fCloseQueryDesign
    call fCloseDatabase 
endcase
'-------------------------------------------------------------------------
testcase tDistinctValues

    initQueryDesign
    
    Kontext "AddTables"
        if AddTables.Exists(5) then
            CloseDlg.Click
        end if
    '/// turn on the distinct vales
    printlog "turn on the distinct vales"    
    Kontext "Designobjectbar"
        sleep(1)
        if Designobjectbar.exists(1) then
            DBDistinctValues.Click
            sleep(1)          
            DBDistinctValues.Click
            sleep(1)
        else
            warnlog "The Designobjectbar toolbar isn't visible."
        end if
    call fCloseQueryDesign
    call fCloseDatabase
    
endcase
'-------------------------------------------------------------------------
testcase tEdit

    initQueryDesign    

    Kontext "AddTables"
        if AddTables.Exists(5) then
            CloseDlg.Click
        end if
    '/// turn off the edit mode
    printlog "turn off the edit mode"        
    Kontext "Toolbar"
        sleep(1)        
        Edit.Click
        sleep(1)
    Kontext "Designobjectbar"
        if Designobjectbar.exists(1) then
            if DBDistinctValues.isEnabled then warnlog "DistincValues icon is enable, but when Edit is turn off, it mustn't."
            if AddTables.isEnabled then warnlog "AddTables icon is enable, but when Edit is turn off, it mustn't."
        else
            warnlog "The Designobjectbar toolbar isn't visible."
        end if
        
    Kontext "Toolbar"        
        if ClearQuery.isEnabled  then warnlog "ClearQuery icon is enable, but when Edit is turn off, it mustn't."
    
    call fCloseQueryDesign
    call fCloseDatabase
    
endcase
'-------------------------------------------------------------------------
testcase tCut

    initQueryDesign
    
    '/// add any table ans select any field
    printlog "add any table ans select any field"
    Kontext "AddTables"
        if AddTables.Exists(5) then
            TableName.Select 1
            AddTable.Click
        end if
    Kontext "Toolbar"
        sleep(1)
        if Cut.isenabled then warnlog "The cut icon is enabled but it is nothing selected."
    '/// select the fieldname and check if the cut button works
    printlog "select the fieldname and check if the cut button works"
    sleep(1)
    Kontext "QueryDesignCriterion"
        QueryDesignCriterion.TypeKeys "<MOD1 PAGEUP>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "Type" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<DOWN>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "<UP>" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<SHIFT END>" , true
        sleep(1)
                
    Kontext "Toolbar"
        if Cut.isenabled then
            Cut.Click
        else
            warnlog "The Cut icon is not enabled but I have select something"
            DatabaseClose
            Kontext "Messagebox"
                if Messagebox.Exists(3) then
                    Messagebox.No
                else
                    warnlog "There should be a message box because the query has been changed!"
                end if
            sleep(1)
            call hCloseDocument
            goto endsub
        endif    
            
        sleep(1)
        '/// check if the text is in the clipboard
        printlog "check if the text is in the clipboard"                
        if getClipboard <> "Type" then
            warnlog "The Cut button doesn't work"
        end if        
       
    call fCloseQueryDesign
    call fCloseDatabase   
        
endcase
'-------------------------------------------------------------------------
testcase tCopy

    initQueryDesign
    
    '/// add any table ans select any field
    printlog "add any table ans select any field"
    Kontext "AddTables"
        if AddTables.Exists(5) then
            TableName.Select 1
            AddTable.Click
        end if
    Kontext "Toolbar"
        sleep(1)
        if Copy.isenabled then warnlog "The copy icon is enabled but it is nothing selected.Bug 107845"
    '/// select the fieldname and check if the copy button works
    printlog "select the fieldname and check if the copy button works"
    sleep(1)
    Kontext "QueryDesignCriterion"
        QueryDesignCriterion.TypeKeys "<MOD1 PAGEUP>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "Type" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<DOWN>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "<UP>" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<SHIFT END>" , true
        sleep(1)
                
    Kontext "Toolbar"
        if Copy.isenabled then
            Copy.Click
        else
            warnlog "The Copy icon is not enabled but I have select something"
            DatabaseClose
            Kontext "Messagebox"
                if Messagebox.Exists(3) then
                    Messagebox.No
                else
                    warnlog "There should be a message box because the query has been changed!"
                end if
            sleep(1)
            call hCloseDocument
            goto endsub
        endif    
            
        sleep(1)
        '/// check if the text is in the clipboard
        printlog "check if the text is in the clipboard"                
        if getClipboard <> "Type" then
            warnlog "The Cut button doesn't work"
        end if        
        
    call fCloseQueryDesign
    call fCloseDatabase   
        
endcase
'-------------------------------------------------------------------------
testcase tPaste

    initQueryDesign    
    
    '/// add any table and select any field
    printlog "add any table and select any field"
    Kontext "AddTables"
        if AddTables.Exists(5) then
            TableName.Select 1
            AddTable.Click            
        else
            warnlog "The AddTable dialog doesn't appear."
            printlog "TEST STOPPED"
            call fCloseQueryDesign
            call fCloseDatabase
            goto endsub
        end if    
    '/// select the fieldname and check if the paste button works
    printlog "select the fieldname and check if the paste button works"
    sleep(1)    
    Kontext "QueryDesignCriterion"
        QueryDesignCriterion.TypeKeys "<MOD1 PAGEUP>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "Type" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<DOWN>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "<UP>" , true        
        sleep(1)
        QueryDesignCriterion.TypeKeys "<SHIFT END>" , true
        sleep(1)
                
    Kontext "Toolbar"
        if Copy.isenabled then
            Copy.Click            
        else
            warnlog "The Copy icon is not enabled but I have select something"
            printlog "TEST STOPPED"
            call fCloseQueryDesign
            call fCloseDatabase
            goto endsub
        endif    
            
    sleep(1)
    '/// check if the text is in the clipboard
    printlog "check if the text is in the clipboard"                
    if getClipboard <> "Type" then
        warnlog "The Copy button doesn't work"
        printlog "TEST STOPPED"
        call fCloseQueryDesign
        call fCloseDatabase        
        goto endsub
    end if        
        
    Kontext "QueryDesignCriterion"
        QueryDesignCriterion.TypeKeys "<RIGHT>" , 2 , true
        sleep(1)

    Kontext "Toolbar"
        if Paste.isenabled then
            Paste.Click            
        else
            warnlog "The Paste icon is not enabled but I have copy something"
            printlog "TEST STOPPED"
            call fCloseQueryDesign
            call fCloseDatabase
            goto endsub
        endif 
    sleep(1)    
    Kontext "QueryDesignCriterion"
        QueryDesignCriterion.TypeKeys "1" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "<HOME>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "<SHIFT END>" , true
        sleep(1)
        QueryDesignCriterion.TypeKeys "<MOD1 C>" , true
        sleep(1)
    
    if getClipboard <> "Type1" then
        warnlog "The Paste button doesn't work"    
    end if
    
    call fCloseQueryDesign
    call fCloseDatabase   
        
    
endcase
'-------------------------------------------------------------------------
testcase tUndo

   initQueryDesign
   
   '/// close the add table dialog
   printlog "close the add table dialog"
   Kontext "AddTables"
        if AddTables.Exists(5) then
            CloseDlg.Click
        end if    
    '/// click on the add table icon in the toolbar of the query design
    printlog "click on the add table icon in the toolbar of the query design"
    Kontext "Toolbar"
        sleep(1)
        if Undo.isenabled then warnlog "The undo icon is enabled but I have nothing done"
        sleep(1)
    '/// check if the dialog opens
    printlog "check if the dialog opens"
    Kontext "Designobjectbar"    
        if Designobjectbar.exists(1) then
            AddTables.Click
            sleep(1)
        else
            warnlog "The Designobjectbar toolbar isn't visible."
        end if        
    Kontext "AddTables"
        if AddTables.Exists(5) then
            TableName.Select 1
            AddTable.Click
        else
            warnlog "The AddTable dialog doesn't open" 
        end if        
    Kontext "Toolbar"
        if Undo.isenabled then
            Undo.Click
            Kontext "Designobjectbar"
            if Designobjectbar.exists(1) then
                if not AddTables.isenabled then warnlog "The undo button doesn't work"
                sleep(1)
            else
                warnlog "The Designobjectbar toolbar isn't visible."
            end if           
        else
            warnlog "The undo icon is disabled but I have insert a table"
        endif
    
    call fCloseQueryDesign
    call fCloseDatabase  
    
endcase
'-------------------------------------------------------------------------
testcase tRedo

    initQueryDesign
    
   '/// close the add table dialog
   printlog "close the add table dialog"
   Kontext "AddTables"
        if AddTables.Exists(5) then
            CloseDlg.Click
            printlog "The AddTables dialog exists, I close it."
		else
            printlog "The AddTables dialog doesn't exists, thats OK."            
        end if    
    '/// click on the add table icon in the toolbar of the query design
    printlog "click on the add table icon in the toolbar of the query design"
    Kontext "Toolbar"
        sleep(1)
        if Redo.isenabled then warnlog "The redo icon is enabled but I have nothing done"        
    '/// check if the dialog opens
    printlog "check if the dialog opens"
    Kontext "Toolbar"
    	sleep(1)
        AddTables.Click
    Kontext "AddTables"
        if AddTables.Exists(5) then
            TableName.Select 1
            AddTable.Click
        else
            warnlog "The AddTable dialog doesn't open" 
        end if        
    Kontext "Toolbar"
        if Undo.isenabled then
            Undo.Click
            sleep(1)
            Redo.Click             
            sleep(1)
            if AddTables.isenabled then warnlog "The redo button doesn't work"
        else
            warnlog "The undo icon is disabled but I have insert a table"
        endif
        
    sleep(1)    
    
    call fCloseQueryDesign
    call fCloseDatabase
    
endcase
'-------------------------------------------------------------------------
'-------------------------------------------------------------------------
testcase tMainMenuBar

    dim iCount as integer ' the numbers of the items in the menu.    
    
    initQueryDesign
    '/// close the add table dialog
    printlog "close the add table dialog"
    Kontext "AddTables"
        if AddTables.Exists(5) then
            CloseDlg.Click
            printlog "The AddTables dialog exists, I close it."		            
        end if 
        
    Kontext "QueryDesignTable"
        QueryDesignTable.UseMenu
           
        '/// check if there are between 8 and 12 items in the file menu.
        printlog "check if there are between 8 and 12 items in the file menu."
        '/// + there different count related to the file pick list.                
        printlog "+ there different count related to the file pick list."        
        hMenuSelectNr(1) ' the file menu        
        iCount = getMenuItemCount()        
        if ( lcase( gPlatform ) = "osx" ) then
            if ( iCount <> 7 ) then
                warnlog( "File menu: 7 items expected, found " & iCount )
            endif
        else
            if (iCount <> 8 ) then
                warnlog "There should between 8 and 12 items in the file menu but there are " + iCount + " items."
             end if    
        endif    
        
        '/// check if there are 12 items in the FILE/NEW menu.
        printlog "check if there are 12 items in the FILE/NEW menu."        
        hMenuSelectNr(1) ' FILE/NEW menu        
        iCount = hMenuItemGetCount()        
        if (iCount <> 12) then
            warnlog "There should 12 items in the FILE/NEW menu but there are " + iCount + " items."
        end if        
        call hMenuClose() ' close the FILE menu
        
        '/// check the FILE/AUTOPILOTS
        printlog "check the FILE/AUTOPILOTS"
        QueryDesignTable.UseMenu        
        hMenuSelectNr(1) ' the file menu
        hMenuSelectNr(3) ' the autopilots menu        
        iCount = hMenuItemGetCount()        
        if (iCount <> 8) then
            warnlog "There should 8 items in the FILE/AUTOPILOTS menu but there are " + iCount + " items."
        endif        
        call hMenuClose()
        
        '/// check if there are 9 items in the edit menu.
        printlog "check if there are 9 items in the edit menu."
        QueryDesignTable.UseMenu 
        hMenuSelectNr(2)        
        iCount = hMenuItemGetCount()
        if (iCount <> 9) then
            warnlog "There should 9 items in the edit menu but there are " + iCount + " items."
        end if
        call hMenuClose()

        '/// check if there are 7 items in the view menu.
        printlog "check if there are 7 items in the view menu."
        QueryDesignTable.UseMenu 
        hMenuSelectNr(3)        
        iCount = hMenuItemGetCount()
        if (iCount <> 7) then
            warnlog "There should 7 items in the view menu but there are " + iCount + " items."
        end if
        call hMenuClose()
        
        '/// check if there are 2 items in the insert menu.
        printlog "check if there are 2 items in the insert menu."
        QueryDesignTable.UseMenu 
        hMenuSelectNr(4)       
        iCount = hMenuItemGetCount()
        if (iCount <> 2) then
            warnlog "There should 2 items in the insert menu but there are " + iCount + " items."
        end if
        call hMenuClose()

        '/// check if there are 4 items in the tools menu.
        printlog "check if there are 4 items in the tools menu."        
        QueryDesignTable.UseMenu 
        hMenuSelectNr(5)        
        iCount = hMenuItemGetCount()
        if ( lcase( gPlatform ) = "osx" ) then
            if ( iCount <> 3 ) then
                warnlog( "Tools menu: 3 items expected, found " & iCount )
            endif
        else
            if (iCount <> 4) then
                warnlog "There should 4 items in the tools menu but there are " + iCount + " items."
            end if
        endif
        call hMenuClose()
        
        '/// check if there are 4 items in the TOOLS/MACRO menu.
        printlog "check if there are 4 items in the TOOLS/MACRO menu."        
        QueryDesignTable.UseMenu 
        hMenuSelectNr(5)
        hMenuSelectNr(1)        
        iCount = hMenuItemGetCount()
        if (iCount <> 4) then
            warnlog "There should 4 items in the TOOLS/MACRO menu but there are " + iCount + " items."
        end if
        call hMenuClose()
    
    call fCloseQueryDesign
    call fCloseDatabase   
     
endcase
'-------------------------------------------------------------------------
'-------------------------------------------------------------------------
'-------------------------------------------------------------------------
function getMenuItemCount as Integer
'use this function becasue this doesn't count the pick list
    Dim i as Integer
    Dim j as Integer
    Dim Ende as Integer
    Dim nID as Integer
    Sleep 2
    j=0
    for i=1 to MenuGetItemCount
        if NOT MenuIsSeperator ( i ) then            
            dim s as String 
            s = Mid(MenuGetItemText( MenuGetItemID(i)),3,1)
            'printlog "s = " + s
            'printlog "MenuGetItemText( MenuGetItemID(i)) = " + MenuGetItemText( MenuGetItemID(i))
            if s <> ":" then             
                j=j+1
            endif
        endif
    next i
    getMenuItemCount = j
end function
'-------------------------------------------------------------------------
sub initQueryDesign

    hFileOpen( gOfficePath & "user/database/biblio.odb" )
        
    Kontext "DATABASE"
    
    Database.MouseDown(50,50)
    Database.MouseUp(50,50)
    
    sleep(1)
    
    NewQueryDesign
        
    ' if not DatabaseSwapIconView.exists(1) then        
        ' warnlog "InsightSwapIconView doesn't exists"
        ' exit sub
    ' end if
        ' 
    ' '/// display Queries View
    ' printlog "display Queries View"
    ' ViewQueries    
    ' if DatabaseQueriesView.exists(1) then
        ' printlog "InsightQueriesView appear"        
    ' else
        ' warnlog "InsightQueriesView doesn't appear"
        ' exit sub
    ' end if
    ' 
    ' Kontext "DATABASE"
        ' CreationList.select(1)
        ' sleep(1)
        ' Database.TypeKeys "<TAB>" , true
        ' Database.TypeKeys "<RETURN>" , true
        ' sleep(1)
end sub    
