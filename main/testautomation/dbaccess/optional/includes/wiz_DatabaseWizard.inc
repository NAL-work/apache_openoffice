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
'* short description : Database Wizard
'*
'\***********************************************************************
sub wiz_DatabaseWizard
    call tNewDatabase
    call tOpenDatabase
    call tOpenNoneDatabaseDocument
    call tStartTableWizardFromWizard
    call tODBC
    call tEvolution
    call tMozilla
    call tJDBC
    call tAdabas
    call tdBase
    call tMySQLODBC
    call tMySQLJDBC
    call tSpreadsheet
    call tText
    call tOracleJDBC
end sub
'-------------------------------------------------------------------------
testcase tNewDatabase
        
    Kontext "DocumentWriter"
        if (DocumentWriter.exists(1)) then        
            DocumentWriter.UseMenu
        else
            Kontext "DocumentBackground"
            DocumentBackground.UseMenu
        endif  
        hMenuSelectNr(1)
        hMenuSelectNr(1)
        hMenuSelectNr(5)
        
    sleep(10)
    
    Kontext "DatabaseWizard"    
        CreateNewDatabase.Check
        sleep(1)
        NextBtn.Click
        sleep(1)        
        FinishBtn.Click
        sleep(1)
	                  
    Kontext "SpeichernDlg"
        if ( Dateiname.getSelText() = "" ) then
            warnlog "#i58413# Default filename is missing"
            Dim sFileName as String
            sFileName = ConvertPath(gOfficePath + "user/work/TTDB1.odb")
            if ( app.Dir( ConvertPath(sFileName) ) ) <> "" then
                app.kill(ConvertPath(sFileName))
            endif
            Dateiname.setText(sFileName)
        endif            
        Speichern.click 
        sleep(10)
        
    Kontext "MessageBox" 
        if MessageBox.exists then
            MessageBox.yes
        end if
        
    sleep(5)

    Kontext "ContainerView"
    
    ViewTables
    
    sleep(1)
    
    call fCloseDatabase(true)
    
endcase
'-------------------------------------------------------------------------
testcase tOpenDatabase
        
    Kontext "DocumentWriter"
        if (DocumentWriter.exists(1)) then        
            DocumentWriter.UseMenu
        else
            Kontext "DocumentBackground"
            DocumentBackground.UseMenu
        endif  
        hMenuSelectNr(1)
        hMenuSelectNr(1)
        hMenuSelectNr(5)
    
    sleep(5)
        
    Kontext "DatabaseWizard"    
        OpenExistingDoc.Check
        sleep(1)
        OpenBtn.Click
        sleep(1)        
                      
    Kontext "GeneralFileDialog"
        printlog "open database from: " + Convertpath(gofficePath + "user/database/biblio.odb")
        Dateiname.setText(Convertpath(gofficePath + "user/database/biblio.odb"))            
        Oeffnen.click 
        sleep(5)
        
    Kontext "ContainerView"
    
    ViewTables
    
    sleep(1)
    
    call fCloseDatabase(false)
    
endcase   
'-------------------------------------------------------------------------
testcase tOpenNoneDatabaseDocument
        
    Kontext "DocumentWriter"
        if (DocumentWriter.exists(1)) then        
            DocumentWriter.UseMenu
        else
            Kontext "DocumentBackground"
            DocumentBackground.UseMenu
        endif  
        hMenuSelectNr(1)
        hMenuSelectNr(1)
        hMenuSelectNr(5)
    
    sleep(5)
        
    Kontext "DatabaseWizard"    
        OpenExistingDoc.Check
        sleep(1)
        OpenBtn.Click
        sleep(1)        
                      
    Kontext "GeneralFileDialog"
        printlog "open spreadsheet file from: " + Convertpath(gTesttoolPath + "dbaccess/optional/input/spreadsheet_datasource/TT_Query1.ods")
        Dateiname.setText(Convertpath(gTesttoolPath + "dbaccess/optional/input/spreadsheet_datasource/TT_Query1.ods"))            
        Oeffnen.click 
        sleep(5)
        
    Kontext "DocumentCalc"
    if (DocumentCalc.exists()) then
		warnlog "the spreadsheet should not appear"
        call hCloseDocument()
    else
        Kontext "MessageBox"
        if(MessageBox.exists(1)) then
        	printlog "messagebox appear ->> OK"
        	MessageBox.OK
            Kontext "DatabaseWizard"	
    	        DatabaseWizard.Cancel
        else
        	warnlog "there should be a message box about the fact that this is no database"
        	Kontext "DatabaseWizard"	
	            DatabaseWizard.Cancel
        endif
    endif
    
endcase
'-------------------------------------------------------------------------
testcase tODBC
qaerrorlog "not yet implemented"
endcase
'-------------------------------------------------------------------------
testcase tEvolution

    if gPlatgroup <> "lin" then
        printlog "Evolution does only exists under linux."
        goto endsub    
    end if   

    call fCreateEvolutionAddressbookDatasource(gOfficePath + "user/work/tt_evolution.odb")
    call fOpendatabase(gOfficePath + "user/work/tt_evolution.odb")
    
    Kontext "ContainerView"
        ViewTables
    
    call fCloseDatabase(true)   
    
endcase
'-------------------------------------------------------------------------
testcase tMozilla

    if ( fCreateMozillaAddressbookDatasource(gOfficePath + "user/work/tt_mozilla.odb") = true) then
        if ( fOpendatabase(gOfficePath + "user/work/tt_mozilla.odb") = true) then        
            Kontext "ContainerView"
                ViewTables
        else
            warnlog "mozilla database could not be open."

        endif
    else
        qaerrorlog "mozilla database could not be created. Maybe you have no mozilla installed."
    	Kontext "MessageBox"
    		if (MessageBox.exists(1)) then
    			MessageBox.OK
    		endif
    endif
	' try to close the database    
    call fCloseDatabase(false)
    
endcase
'-------------------------------------------------------------------------
testcase tJDBC
qaerrorlog "not yet implemented"
endcase
'-------------------------------------------------------------------------
testcase tAdabas
    qaerrorlog "not yet implemented"
endcase
'-------------------------------------------------------------------------
testcase tdBase

    call fCreateDbaseDatasource(gOfficePath + "user/work/tt_dbase.odb",gOfficePath + "user/work/")
    call fOpendatabase(gOfficePath + "user/work/tt_dbase.odb")
    
    Kontext "ContainerView"
        ViewTables
    
    call fCloseDatabase(true)
    
endcase
'-------------------------------------------------------------------------
testcase tMySQLODBC
qaerrorlog "not yet implemented"
endcase
'-------------------------------------------------------------------------
testcase tMySQLJDBC
qaerrorlog "not yet implemented"
endcase
'-------------------------------------------------------------------------
testcase tSpreadsheet
qaerrorlog "not yet implemented"
endcase
'-------------------------------------------------------------------------
testcase tText

    call fCreateTextDatasource(gOfficePath + "user/work/tt_text.odb",gOfficePath + "user/work/")
    call fOpendatabase(gOfficePath + "user/work/tt_text.odb")
    
    Kontext "ContainerView"
        ViewTables
    
    call fCloseDatabase(true)    
    
endcase
'-------------------------------------------------------------------------
testcase tOracleJDBC
qaerrorlog "not yet implemented"
endcase
'-------------------------------------------------------------------------
testcase tStartTableWizardFromWizard

    printlog "start database wizard via FILE / NEW / DATABASE"
    Kontext "DocumentWriter"
        if (DocumentWriter.exists(1)) then
            DocumentWriter.UseMenu
        else
            Kontext "DocumentBackground"
            DocumentBackground.UseMenu
        endif
        hMenuSelectNr(1)
        hMenuSelectNr(1)
        hMenuSelectNr(5)

    sleep(10)

    Kontext "DatabaseWizard"
        printlog "check create new database"
        CreateNewDatabase.Check        
        sleep(1)
        printlog "click next button"
        NextBtn.Click
        sleep(1)
        printlog "check the 'Create Table with wizard' option"
        StartTableWizard.check()
        printlog "click finished button"
        FinishBtn.Click
        sleep(1)

    Kontext "SpeichernDlg"
        printlog "click save in the save as dialog"
        if ( Dateiname.getSelText() = "" ) then
            warnlog "#i58413# Default filename is missing"
            Dim sFileName as String
            sFileName = ConvertPath(gOfficePath + "user/work/TTDB1.odb")
            if ( app.Dir( ConvertPath(sFileName) ) ) <> "" then
                app.kill(ConvertPath(sFileName))
            endif
            Dateiname.setText(sFileName)
        endif
        Speichern.click
        sleep(10)

    Kontext "MessageBox"
        if MessageBox.exists then
            MessageBox.yes
        end if

    sleep(5)

    Kontext "TableWizard"
        printlog "check if the table wizard appear"
        if( TableWizard.exists(10) ) then
            printlog "the table wizard appear."            
            CancelBtn.click()
        else
            warnlog "the table wizard does not appear."
        endif

    Kontext "ContainerView"

    ViewTables

    sleep(1)
    
    printlog "close the database"
    call fCloseDatabase(true)

endcase
'-------------------------------------------------------------------------
