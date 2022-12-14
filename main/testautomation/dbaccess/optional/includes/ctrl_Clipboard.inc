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
'* short description : Clipboard test with controls between all application
'*
'\***********************************************************************

sub ctrl_Clipboard
	
    call tFromText         'copy control from text document and paste it to the other application and check
    call tFromCalc         'copy control from calc document and paste it to the other application and check
    call tFromDraw         'copy control from draw document and paste it to the other application and check
    call tFromImpress      'copy control from impress document and paste it to the other application and check

end sub
'--------------------------------------------------------------------------------------
testcase tFromText

    '/// Open a new document and empty clipboard
        printlog "Open a new document and empty clipboard"
	call hNewDocument
    Kontext "DocumentWriter"    
	    DocumentWriter.TypeKeys "tt_doc" , true
        sleep(1)
        setClipboard(" ")
        sleep(1)

    call hToolbarSelect("FormControls",true)   
	
  	Kontext "FormControls"   	
   	    PushButton.Click
        sleep(1)      
	'/// insert a Push Button
        printlog "insert a Push Button"    
        call hDrawingWithSelection ( 20, 20, 30, 30 )
        sleep(2)
	Kontext "FormControls"
	    ControlProperties.Click
        sleep (1)
    Kontext "ControlPropertiesTabControl"   
        ControlPropertiesTabControl.setPage TabGeneralControl       'make shure that tabpage general in property is choosen
        sleep(2)        
    '/// set control property: Name
        printlog "set control property"      
    Kontext "TabGeneralControl"	
        if TabGeneralControl.exists(3) then
                NameText.setText("FromText")
        else warnlog "control property browser could not be opend"
        endif
        sleep (1)    
    '/// copy control to clipboard
        printlog "copy control to clipboard" 
    Kontext "DocumentWriter"
        DocumentWriter.TypeKeys "<F6>", TRUE
        sleep (1)
        DocumentWriter.TypeKeys "<COPY>", TRUE
        sleep (1)
    '/// close document
        printlog "close document" 
    call hCloseDocument
    
    '/// open new document (to repeat for all documents except the document you copy from)
        dim i as integer    'counter
    for i = 1 to 3
    '/// paste control from clipboard and open control property browser
        if i = 1 then 
            gApplication = "CALC"
                printlog "-- Text to Calc Clipboard Test --"
                printlog "open a new Calc document"
                call hNewDocument
                printlog "paste control from clipboard" 
            Kontext "DocumentCalc"
                DocumentCalc.TypeKeys "<PASTE>", TRUE
                sleep (1)
                printlog "open control property browser from context"     
                DocumentCalc.TypeKeys "<SHIFT F10>", TRUE
                call hMenuSelectNr(4)
            endif
        if i = 2 then 
            gApplication = "DRAW"
                printlog "-- Text to Draw Clipboard Test --"
                printlog "open a new Draw document"
                call hNewDocument
                printlog "paste control from clipboard" 
            Kontext "DocumentDraw"
                DocumentDraw.TypeKeys "<PASTE>", TRUE
                sleep (1)
                printlog "open control property browser from context"     
                DocumentDraw.TypeKeys "<SHIFT F10>", TRUE
                call hMenuSelectNr(2)
            endif
        if i = 3 then 
            gApplication = "IMPRESS"
                printlog "-- Text to Impress Clipboard Test --"
                printlog "open a new Impress document"
                call hNewDocument
                printlog "paste control from clipboard" 
            Kontext "DocumentImpress"
                DocumentImpress.TypeKeys "<PASTE>", TRUE
                sleep (1)
                printlog "open control property browser from context"     
                DocumentImpress.TypeKeys "<SHIFT F10>", TRUE
                call hMenuSelectNr(2)
            endif           
    
        Kontext "ControlPropertiesTabControl"   
            ControlPropertiesTabControl.setPage TabGeneralControl       'make shure that tabpage general in property is choosen
            sleep(2) 
        '/// check if control was correctly stored in clipboard  
        Kontext "TabGeneralControl"	
            if TabGeneralControl.exists(3) then
                if NameText.getText <> "FromText" then
                    warnlog "Control is not saved correctly"
                else printlog "control was saved correctly"
                endif
            else warnlog "Control property browser could not be opend"
            endif
            sleep (1)
        '/// Close document
            printlog "close document" 
        call hCloseDocument
        
    next i
        printlog "*** Testcase End ***"
        
endcase

'--------------------------------------------------------------------------------------
testcase tFromCalc

    '/// Open a new document and empty clipboard
        printlog "Open a new document and empty clipboard"
        gApplication = "CALC"
	call hNewDocument
    Kontext "DocumentCalc"    
	    DocumentCalc.TypeKeys "tt_doc" , true
        sleep(1)
        setClipboard(" ")
        sleep(1)

    call hToolbarSelect("FormControls",true)   	

  	Kontext "FormControls"  
   	    PushButton.Click
        sleep(1)      
	'/// insert a Push Button
        printlog "insert a Push Button"    
        call hDrawingWithSelection ( 20, 20, 30, 30 )
        sleep(2)
	Kontext "FormControls"
	    ControlProperties.Click
        sleep (1)
    Kontext "ControlPropertiesTabControl"   
        ControlPropertiesTabControl.setPage TabGeneralControl       'make shure that tabpage general in property is choosen
        sleep(2)        
    '/// set control property: Name
        printlog "set control property"      
    Kontext "TabGeneralControl"	
        if TabGeneralControl.exists(3) then
                NameText.setText("FromCalc")
        else warnlog "control property browser could not be opend"
        endif
        sleep (1)    
    '/// copy control to clipboard
        printlog "copy control to clipboard" 
    Kontext "DocumentCalc"
        DocumentCalc.TypeKeys "<F6>", TRUE
        sleep (1)
        DocumentCalc.TypeKeys "<COPY>", TRUE
        sleep (1)
    '/// close document
        printlog "close document" 
    call hCloseDocument
    
    '/// open new document (to repeat for all documents except the document you copy from)
        dim i as integer    'counter
    for i = 1 to 3
    '/// paste control from clipboard and open control property browser
        if i = 1 then 
            gApplication = "WRITER"
                printlog "-- Calc to Text Clipboard Test --"
                printlog "open a new Text document"
                call hNewDocument
                printlog "paste control from clipboard" 
            Kontext "DocumentWriter"
                DocumentWriter.TypeKeys "<PASTE>", TRUE
                sleep (1)
                printlog "open control property browser from context"     
                DocumentWriter.TypeKeys "<SHIFT F10>", TRUE
                call hMenuSelectNr(4)
            endif
        if i = 2 then 
            gApplication = "DRAW"
                printlog "-- Calc to Draw Clipboard Test --"
                printlog "open a new Draw document"
                call hNewDocument
                printlog "paste control from clipboard" 
            Kontext "DocumentDraw"
                DocumentDraw.TypeKeys "<PASTE>", TRUE
                sleep (1)
                printlog "open control property browser from context"     
                DocumentDraw.TypeKeys "<SHIFT F10>", TRUE
                call hMenuSelectNr(2)
            endif
        if i = 3 then 
            gApplication = "IMPRESS"
                printlog "-- Calc to Impress Clipboard Test --"
                printlog "open a new Impress document"
                call hNewDocument
                printlog "paste control from clipboard" 
            Kontext "DocumentImpress"
                DocumentImpress.TypeKeys "<PASTE>", TRUE
                sleep (1)
                printlog "open control property browser from context"     
                DocumentImpress.TypeKeys "<SHIFT F10>", TRUE
                call hMenuSelectNr(2)
            endif           
    
        Kontext "ControlPropertiesTabControl"   
            ControlPropertiesTabControl.setPage TabGeneralControl       'make shure that tabpage general in property is choosen
            sleep(2) 
        '/// check if control was correctly stored in clipboard  
        Kontext "TabGeneralControl"	
            if TabGeneralControl.exists(3) then
                if NameText.getText <> "FromCalc" then
                    warnlog "Control is not saved correctly. Name should be FromCalc but it is " + NameText.getText 
                else
                    printlog "control was saved correctly"
                endif
            else warnlog "Control property browser could not be opend"
            endif
            sleep (1)
        '/// Close document
            printlog "close document" 
        call hCloseDocument
        
    next i
        printlog "*** Testcase End ***"
        
endcase

'--------------------------------------------------------------------------------------
testcase tFromDraw

    '/// Open a new document and empty clipboard
        printlog "Open a new document and empty clipboard"
        gApplication = "DRAW"
	call hNewDocument
    Kontext "DocumentDraw"    
	    DocumentDraw.TypeKeys "tt_doc" , true
        sleep(1) 
        setClipboard(" ")
        sleep(1) 

    call hToolbarSelect("FormControls",true)   

  	Kontext "FormControls"  
   	    PushButton.Click
        sleep(1)      
	'/// insert a Push Button
        printlog "insert a Push Button"    
        call hDrawingWithSelection ( 20, 20, 30, 30 )
        sleep(2)
	Kontext "FormControls"
	    ControlProperties.Click
        sleep (1)
    Kontext "ControlPropertiesTabControl"   
        ControlPropertiesTabControl.setPage TabGeneralControl       'make shure that tabpage general in property is choosen
        sleep(2)        
    '/// set control property: Name
        printlog "set control property"      
    Kontext "TabGeneralControl"	
        if TabGeneralControl.exists(3) then
                NameText.setText("FromDraw")
        else warnlog "control property browser could not be opend"
        endif
        sleep (1)    
    '/// copy control to clipboard
        printlog "copy control to clipboard" 
    Kontext "DocumentDraw"
        DocumentDraw.TypeKeys "<F6>", TRUE
        sleep (1)
        DocumentDraw.TypeKeys "<COPY>", TRUE
        sleep (1)
    '/// close document
        printlog "close document" 
    call hCloseDocument
    
    '/// open new document (to repeat for all documents except the document you copy from)
        dim i as integer    'counter
    for i = 1 to 3
    '/// paste control from clipboard and open control property browser
        if i = 1 then 
            gApplication = "WRITER"
                printlog "-- Draw to Text Clipboard Test --"
                printlog "open a new Text document"
                call hNewDocument
                printlog "paste control from clipboard" 
            Kontext "DocumentWriter"
                DocumentWriter.TypeKeys "<PASTE>", TRUE
                sleep (1)
                printlog "open control property browser from context"     
                DocumentWriter.TypeKeys "<SHIFT F10>", TRUE
                call hMenuSelectNr(4)
            endif
        if i = 2 then 
            gApplication = "CALC"
                printlog "-- Draw to Calc Clipboard Test --"
                printlog "open a new Calc document"
                call hNewDocument
                printlog "paste control from clipboard" 
            Kontext "DocumentCalc"
                DocumentCalc.TypeKeys "<PASTE>", TRUE
                sleep (1)
                printlog "open control property browser from context"     
                DocumentCalc.TypeKeys "<SHIFT F10>", TRUE
                call hMenuSelectNr(4)
            endif
        if i = 3 then 
            gApplication = "IMPRESS"
                printlog "-- Draw to Impress Clipboard Test --"
                printlog "open a new Impress document"
                call hNewDocument
                printlog "paste control from clipboard" 
            Kontext "DocumentImpress"
                DocumentImpress.TypeKeys "<PASTE>", TRUE
                sleep (1)
                printlog "open control property browser from context"     
                DocumentImpress.TypeKeys "<SHIFT F10>", TRUE
                call hMenuSelectNr(2)
            endif           
    
        Kontext "ControlPropertiesTabControl"   
            ControlPropertiesTabControl.setPage TabGeneralControl       'make shure that tabpage general in property is choosen
            sleep(2) 
        '/// check if control was correctly stored in clipboard  
        Kontext "TabGeneralControl"	
            if TabGeneralControl.exists(3) then
                if NameText.getText <> "FromDraw" then
                    warnlog "Control is not saved correctly"
                else printlog "control was saved correctly"
                endif
            else warnlog "Control property browser could not be opend"
            endif
            sleep (1)
        '/// Close document
            printlog "close document" 
        call hCloseDocument
        
    next i
        printlog "*** Testcase End ***"
        
endcase

'--------------------------------------------------------------------------------------
testcase tFromImpress

    '/// Open a new document and empty clipboard
        printlog "Open a new document and empty clipboard"
        gApplication = "IMPRESS"
	call hNewDocument
    Kontext "DocumentImpress"    
	    DocumentImpress.TypeKeys "tt_doc" , true
        sleep(1) 
        setClipboard(" ")
        sleep(1)

    call hToolbarSelect("FormControls",true)    
    
  	Kontext "FormControls"  
   	    PushButton.Click
        sleep(1)      
	'/// insert a Push Button
        printlog "insert a Push Button"    
        call hDrawingWithSelection ( 20, 20, 30, 30 )
        sleep(2)
	Kontext "FormControls"
	    ControlProperties.Click
        sleep (1)
    Kontext "ControlPropertiesTabControl"   
        ControlPropertiesTabControl.setPage TabGeneralControl       'make shure that tabpage general in property is choosen
        sleep(2)        
    '/// set control property: Name
        printlog "set control property"      
    Kontext "TabGeneralControl"	
        if TabGeneralControl.exists(3) then
                NameText.setText("FromImpress")
        else warnlog "control property browser could not be opend"
        endif
        sleep (1)    
    '/// copy control to clipboard
        printlog "copy control to clipboard" 
    Kontext "DocumentImpress"
        DocumentImpress.TypeKeys "<F6>", TRUE
        sleep (1)
        DocumentImpress.TypeKeys "<COPY>", TRUE
        sleep (1)
    '/// close document
        printlog "close document" 
    call hCloseDocument
    
    '/// open new document (to repeat for all documents except the document you copy from)
        dim i as integer    'counter
    for i = 1 to 3
    '/// paste control from clipboard and open control property browser
        if i = 1 then 
            gApplication = "WRITER"
                printlog "-- Impress to Text Clipboard Test --"
                printlog "open a new Text document"
                call hNewDocument
                printlog "paste control from clipboard" 
            Kontext "DocumentWriter"
                DocumentWriter.TypeKeys "<PASTE>", TRUE
                sleep (1)
                printlog "open control property browser from context"     
                DocumentWriter.TypeKeys "<SHIFT F10>", TRUE
                call hMenuSelectNr(4)
            endif
        if i = 2 then 
            gApplication = "CALC"
                printlog "-- Impress to Calc Clipboard Test --"
                printlog "open a new Calc document"
                call hNewDocument
                printlog "paste control from clipboard" 
            Kontext "DocumentCalc"
                DocumentCalc.TypeKeys "<PASTE>", TRUE
                sleep (1)
                printlog "open control property browser from context"     
                DocumentCalc.TypeKeys "<SHIFT F10>", TRUE
                call hMenuSelectNr(4)
            endif
        if i = 3 then 
            gApplication = "DRAW"
                printlog "-- Impress to Draw Clipboard Test --"
                printlog "open a new Draw document"
                call hNewDocument
                printlog "paste control from clipboard" 
            Kontext "DocumentDraw"
                DocumentDraw.TypeKeys "<PASTE>", TRUE
                sleep (1)
                printlog "open control property browser from context"     
                DocumentDraw.TypeKeys "<SHIFT F10>", TRUE
                call hMenuSelectNr(2)
            endif           
    
        Kontext "ControlPropertiesTabControl"   
            ControlPropertiesTabControl.setPage TabGeneralControl       'make shure that tabpage general in property is choosen
            sleep(2) 
        '/// check if control was correctly stored in clipboard  
        Kontext "TabGeneralControl"	
            if TabGeneralControl.exists(3) then
                if NameText.getText <> "FromImpress" then
                    warnlog "Control is not saved correctly"
                else printlog "control was saved correctly"
                endif
            else warnlog "Control property browser could not be opend"
            endif
            sleep (1)
        '/// Close document
            printlog "close document" 
        call hCloseDocument
        
    next i
        printlog "*** Testcase End ***"
        
endcase
