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
'* short description : Report Wizard Test
'*
'\***********************************************************************
sub wiz_ReportWizard
    
    call tNewReport

end sub
'-------------------------------------------------------------------------
testcase tNewReport

   ' qaerrorlog "#i92543# crash when closing report"
   ' goto endsub

    call fOpenDatabase(gOfficePath + ConvertPath("user/database/biblio.odb"))
        
    Kontext "DATABASE"
    
    ViewReports
    
    Database.MouseDown(50,50)
    Database.MouseUp(50,50)
    sleep(1)
    
    StartReportWizard
    
    sleep(5)
    
    Kontext "ReportWizard"        
        sleep(1)
        Tables.select 1
        '/// add the third field
        printlog "add the third field"
        AvailableFields.select 1
        sleep(1)
        Add.click
        sleep(1)
        '/// click NEXT
        printlog "click NEXT"
        NextBtn.click
        sleep(1)        
        '/// click NEXT
        printlog "click NEXT"
        NextBtn.click
        sleep(1)
        '/// click NEXT
        printlog "click NEXT"
        NextBtn.click
        sleep(1)
        '/// click NEXT
        printlog "click NEXT"
        NextBtn.click
        sleep(1)
        '/// click Finish
        printlog "click Finish"       
        FinishBtn.Click
    sleep(10)

    Kontext "DocumentWriter"
    	DocumentWriter.TypeKeys "<MOD1 SHIFT I>" ,  true ' EDIT / SELECT TEXT    	
        DocumentWriter.TypeKeys "<SHIFT END>" , true
        DocumentWriter.TypeKeys "<MOD1 C>" , true

	dim s as String
	s = getClipboard

    if s = "Identifier" then
        printlog "Report Table Header contains " + s + ". -> OK"
    else
        warnlog "Report Table Header contains " + s + " instead of IDENTIFIER"
    endif

    ' select next line and check content
    Kontext "DocumentWriter"
        DocumentWriter.TypeKeys "<DOWN>", 2, true
        DocumentWriter.TypeKeys "<SHIFT HOME>" , true
        DocumentWriter.TypeKeys "<MOD1 C>" , true

    s = getClipboard

    if s = "GUR00" OR s = "BOR04" then
        printlog "1. record is " + s + ". -> OK"
    else
        warnlog  "1. record is " + s + " instead of GUR00 OR BOR04"
    endif

    call fCloseForm ' should be changed to a CloseReport

    call fCloseDatabase

endcase

