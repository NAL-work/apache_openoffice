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
'* short description : Page Number
'*
'\***********************************************************************************
sub rpt_PageNumber

    printlog "------------------ rpt_PageNumber.inc ---------------------"
    
    call tDefaultSetting
    call tPageNumber
    
end sub
'-------------------------------------------------------------------------
'-------------------------------------------------------------------------
'-------------------------------------------------------------------------
testcase tDefaultSetting

    '/// FILE / OPEN / biblio.odb
    printlog "FILE / OPEN / biblio.odb"        
    call fOpenDataBase(gOfficePath + ConvertPath("user/database/biblio.odb"))
    
    '/// INSERT / REPORT
    printlog "INSERT / REPORT"    
    call fOpenNewReportDesign
    
    sleep(1)
    
    '/// select any section to get the insert page number menu item activated
    printlog "select any section to get the insert page number menu item activated"
    Kontext "ReportDesign"
        ReportDesign.MouseDown(50, 10)
        ReportDesign.MouseUp(50, 10)
    
    '/// INSERT / PAGE NUMBER    
    Kontext "ReportDesign"
    ReportDesign.UseMenu 
        hMenuSelectNr(4)
        hMenuSelectNr(1)        
    
	sleep(1)
    '/// check if the "Page Number" dialog appear
    printlog "check if the ""Page Number"" dialog appear"
    Kontext "ReportPageNumber"
        if (ReportPageNumber.exists(3)) then              
            
            '/// check if PageN is checked
            printlog "check if PageN is checked"            
            if ( PageN.isChecked() ) then
                printlog "Default PageN is checked"
            else
                warnlog "Default PageN is not checked"
            endif    
            
            '/// check if PageOfPage is checked
            printlog "check if PageOfPage is checked"
            if TopOfPage.isChecked() then
                printlog "Default TopOfPage is checked"
            else
                warnlog "Default TopOfpage is not checked"
            endif
            
            '/// check if PageAlignment is set to center
            printlog "check if PageAlignment is set to center"
            if ( PageNumberAlignment.getSelIndex() = 2 ) then
                printlog "center alignment is selected"
            else
                warnlog "center alignment is not selected"
            endif
            
            '/// check if ShowNumberOnFirstPage checkboc is available. If not issue i78945
            printlog "check if ShowNumberOnFirstPage checkboc is available"
            if ( ShowNumberOnFirstPage.isVisible() ) then
            
                '/// check if ShowNumberOnFirstPage is checked
                printlog "check if PageAlignment is set to center"
                if ( ShowNumberOnFirstPage.isChecked() ) then
                    printlog "ShowNumberOnFirstPage is checked"
                else
                    warnlog "ShowNumberOnFirstPage is not checked"
                endif
            else            
                qaerrorlog "#i78945# ShowNumberOnFirstPage is not visible"            
            endif
	        '/// close dialog with OK
            printlog "close dialog with OK"
	        ReportPageNumber.OK
		else
            warnlog "ReportPageNumber doesn't exists"	        
	    endif    
    
    '/// close the report designer with WINDOW / CLOSE
    printlog "close the report designer with WINDOW / CLOSE"    
    call fCloseReportDesign
    
    '/// close the database with FILE / CLOSE
    printlog "close the database with FILE / CLOSE"    
    call fCloseDatabase
    
endcase
'-------------------------------------------------------------------------
testcase tPageNumber

    '/// open Bibliography database
    printlog "open Bibliography database"    
    call fOpenDataBase(gOfficePath + ConvertPath("user/database/biblio.odb"))
    
    '/// open the report designer
    printlog "open the report designer"
    call fOpenNewReportDesign
    
    sleep(1)
    
    '/// select the first table in the content list box
    printlog "select the first table in the content list box"
    Kontext "ReportDataProperties"   
        Content.select 1
        Content.typeKeys("<RETURN>",true) ' important to leave the listbox
    
    'close the Add Field dialog to get the focus back to the design
    call fCloseAddFieldDialog
    
    '/// turn of the page header    
    call fSwitchPageHeader
    '/// insert a data control
    printlog "insert a data control"    
  	Kontext "FormControls"   	
   	    Edit.Click
        sleep(1)
    
    Kontext "ReportDesign"    
        ReportDesign.MouseDown ( 30, 10 )            
        ReportDesign.MouseMove ( 40, 20 )            
        ReportDesign.MouseUp ( 40, 20 )

    Kontext "ReportDesign"

        '/// align the control to the left    
        ReportDesign.UseMenu 
        hMenuSelectNr(5)
        hMenuSelectNr(5)
        hMenuSelectNr(1)
        
        '/// align the control to the top
        ReportDesign.UseMenu 
        hMenuSelectNr(5)
        hMenuSelectNr(5)
        hMenuSelectNr(4)
        
    sleep(1)    
        
    Kontext "ReportPropertiesTabControl"
        ReportPropertiesTabControl.setPage ReportDataProperties
    
    Kontext "ReportDataProperties" 
        DataField.select 1
        DataField.typeKeys("<RETURN>",true) ' important to leave the listbox
    
    ' select detail section with unselect the control
    Kontext "ReportDesign"
        ReportDesign.MouseDown(50, 10)
        ReportDesign.MouseUp(50, 10)
        
    Kontext "ReportGeneralProperties"           
        Height.setText("0")
        Height.typeKeys("<RETURN>",true)
        
    '/// INSERT / PAGE NUMBER    
    Kontext "ReportDesign"
    ReportDesign.UseMenu 
        hMenuSelectNr(4)
        hMenuSelectNr(1)        
    
	sleep(1)
    
    Kontext "ReportPageNumber"
        '/// check PageNofM
        printlog "check PageNofM"
        PageNOfM.Check()
        '/// check BottomOfPage
        printlog "check BottomOfPage"
        BottomOfPage.check()
        '/// select the 3 entry inPageNumberAlignment
        printlog "select the 3 entry inPageNumberAlignment"
        PageNumberAlignment.select(3)
                
        '/// close dialog with OK
        printlog "close dialog with OK"
        ReportPageNumber.OK
	
    'sleep(5)
    
    
    Kontext "ReportPropertiesTabControl"
        ReportPropertiesTabControl.setPage ReportDataProperties 
    'sleep(5)
    Kontext "ReportDataProperties"
        dim s as string
        s = DataField.getSelText()        
        if ((instr(s," & PageNumber() & ") = 0) OR (instr(s," & PageCount()") = 0)) then
            warnlog "The page number function is not correct.The function is " + s
        else
            printlog "The page number function is correct."
        endif
    'sleep(5)
    '/// execute the report            
    call fExecuteReport
    
    sleep(10)
    
    '/// check if the report is created
    printlog "check if the report is created"
    Kontext "DocumentWriter"
        if (DocumentWriter.exists(10)) then
            call fCloseReportView
        else
            warnlog "No report is created."
        endif
        
    '/// close the report designer with WINDOW / CLOSE
    printlog "close the report designer with WINDOW / CLOSE"    
    call fCloseReportDesign
    
    '/// close the database with FILE / CLOSE
    printlog "close the database with FILE / CLOSE"    
    call fCloseDatabase
    
endcase
'-------------------------------------------------------------------------

