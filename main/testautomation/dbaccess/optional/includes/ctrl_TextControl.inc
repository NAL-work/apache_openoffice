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
'* short description : Text Control
'*
'\***********************************************************************

sub ctrl_TextControl

    call tTextControl
    call tRichTextControl
    call tRichTextControlDraw
    
end sub
'--------------------------------------------------------------------------------------
testcase tTextControl 
    
    '/// Open a new document,
    printlog "Open a new document,"
	call hNewDocument
    Kontext "DocumentWriter"       
	DocumentWriter.TypeKeys "tt_doc" , true
	sleep(1)

    call hToolbarSelect("FormControls",true)
	
  	Kontext "FormControls"   	
   	Edit.Click
   	sleep(1)      
	'/// insert a text box
    printlog "insert a text box"                    
    call hDrawingWithSelection ( 50, 20, 60, 30 )    
    sleep(1)    
	Kontext "FormControls"
	ControlProperties.Click
	sleep(2)
    '/// set properties: Background color, Horizontal scrollbar, Vertical scrollbar, Password
    printlog "set properties"  
	fsetControlProperty("TextBox","Background","92")
    fsetControlProperty("TextBox","TextType","3")    
    '/// save the document
    printlog "save the document"
	hFileSaveAsKill ( gOfficePath + ConvertPath("user/work/TT_TextBox.odt"))
	hCloseDocument
    sleep(1)
    '/// reload the document
    printlog "reload the document"
	hFileOpen ( gOfficePath + ConvertPath("user/work/TT_TextBox.odt"))    

    call hToolbarSelect("FormControls",true)    

  	Kontext "FormControls"  
     SwitchControlDesignMode.Click
    Kontext "DocumentWriter"
     DocumentWriter.TypeKeys "<SHIFT F4>"
    sleep(1)
    Kontext "FormControls"    
     try
        ControlProperties.Click
     catch 
        warnlog "error while open the control properties browser"
        call hCloseDocument
        goto endsub
     endcatch
    '/// check if the values are saved
    printlog "check if the values are saved"
	sleep(2)
    if fgetControlProperty("TextBox","Background") <> "92" then
        warnlog "the value: background is not saved"
    endif      
    
    if fgetControlProperty("TextBox","TextType") <> "3" then
        warnlog "the value: TextType is not saved"
    endif       
    sleep(1)    	
    hCloseDocument 
endcase
'--------------------------------------------------------------------------------------
testcase tRichTextControl 
    
    '/// Open a new document,
    printlog "Open a new document,"
	call hNewDocument
    Kontext "DocumentWriter"       
	DocumentWriter.TypeKeys "tt_doc" , true
	sleep(1)

    call hToolbarSelect("FormControls",true)
	
  	Kontext "FormControls"   	
   	Edit.Click
   	sleep(1)      
	'/// insert a text box
    printlog "insert a text box"                    
    call hDrawingWithSelection ( 50, 20, 60, 30 )    
    sleep(2)
	Kontext "FormControls"
	ControlProperties.Click
	sleep(2)
    '/// set properties: Background color, Horizontal scrollbar, Vertical scrollbar, Password
    printlog "set properties"  
	fsetControlProperty("TextBox","TextType","3")
    '/// turn off the design view
    printlog "turn off the design view"
    
    call hToolbarSelect("FormControls",true)

  	Kontext "FormControls"  
        SwitchControlDesignMode.Click
    '/// insert some text in the control
    printlog "insert some text in the control"
    Kontext "DocumentWriter"
        sleep(1)
        DocumentWriter.TypeKeys "<MOD1 F5>" , true
        sleep(1)
        DocumentWriter.TypeKeys "this is a blind text" , true        
        sleep(1)
        DocumentWriter.TypeKeys "<SHIFT MOD1 LEFT>" ,2, true        
        sleep(1)
        FormatStyleStrikeThrough
        sleep(1)
    '/// save the document
    printlog "save the document"
	hFileSaveAsKill ( gOfficePath + ConvertPath("user/work/TT_RichTextBox.odt"))
	hCloseDocument
    sleep(1)
    '/// reload the document
    printlog "reload the document"
	hFileOpen ( gOfficePath + ConvertPath("user/work/TT_RichTextBox.odt"))
    Kontext "DocumentWriter"
        DocumentWriter.TypeKeys "<MOD1 F5>" , true
        qaerrorlog "workaround for issue 102010"
        DocumentWriter.TypeKeys "<RIGHT>" , true
        DocumentWriter.TypeKeys "<LEFT>" , true
        sleep(1)
        DocumentWriter.TypeKeys "<MOD1 SHIFT END>" , true
        sleep(1)
        DocumentWriter.TypeKeys "<MOD1 C>" , true
        sleep(1)
        'printlog "getClipboard = " + getClipboard
        if ( getClipboard <> "this is a blind text" ) then
            warnlog "The text in the control is not saved (" + getClipboard() + ")"
        end if
        DocumentWriter.TypeKeys "<END>" , true        
        sleep(1)
        DocumentWriter.TypeKeys "<SHIFT MOD1 LEFT>" ,2, true        
        sleep(1)
        FormatCharacter
        Kontext
            active.SetPage TabFontEffects
        Kontext "TabFontEffects"
        if StrikeThrough.getSelIndex() <> 2 then            
            warnlog "StrikeThrought is not set"
        else
            printlog "StrikeThrought is set"
        end if        
        TabFontEffects.Cancel
        
        sleep(1)
                
    hCloseDocument 
endcase
'--------------------------------------------------------------------------------------
testcase tRichTextControlDraw 
    
    '/// Open a new document,
    printlog "Open a new document,"
	gApplication = "DRAW"
    call hNewDocument
    Kontext "DocumentDraw"       
	DocumentDraw.TypeKeys "tt_doc" , true
	sleep(1)

    call hToolbarSelect("FormControls",true)
	
    Kontext "DocumentDraw"
    DocumentDraw.MouseDown ( 20, 20 )
    sleep(1)
    DocumentDraw.MouseUp ( 20, 20 )
    sleep(1)
    Kontext "FormControls" 
    sleep(1)  	
   	Edit.Click
   	sleep(1) 
    call hDrawingWithSelection ( 50, 20, 60, 30 )
    sleep(2)
	Kontext "FormControls"
	ControlProperties.Click
	sleep(2)
    '/// set properties: Background color, Horizontal scrollbar, Vertical scrollbar, Password
    printlog "set properties"  
	fsetControlProperty("TextBox","TextType","3")
    '/// turn off the design view
    printlog "turn off the design view"

    printlog "close control property browser"    
    Kontext "ControlPropertiesDialog"
        ControlPropertiesDialog.close
    
    call hToolbarSelect("FormControls",true)

  	Kontext "FormControls"  
        SwitchControlDesignMode.Click
    '/// insert some text in the control
    printlog "insert some text in the control"
    Kontext "DocumentDraw"
        sleep(1)
        DocumentDraw.TypeKeys "<MOD1 F5>" , true
        sleep(1)
	DocumentDraw.TypeKeys "<MOD1 F5>" , true
	sleep(1)
        DocumentDraw.TypeKeys "this is a blind text" , true        
        sleep(1)
        DocumentDraw.TypeKeys "<SHIFT MOD1 LEFT>" ,2, true        
        sleep(1)
        FormatStyleStrikeThrough
        sleep(1)
    '/// save the document
    printlog "save the document"
	hFileSaveAsKill ( gOfficePath + ConvertPath("user/work/TT_RichTextBox.odg"),gDrawFilter)
	hCloseDocument
    sleep(1)
    '/// reload the document
    printlog "reload the document"
	hFileOpen ( gOfficePath + ConvertPath("user/work/TT_RichTextBox.odg"))
    Kontext "DocumentDraw"
        DocumentDraw.TypeKeys "<MOD1 F5>" , true
        sleep(1)
	    DocumentDraw.TypeKeys "<MOD1 F5>" , true
	    qaerrorlog "workaround for issue 102010"
	    DocumentDraw.TypeKeys "<RIGHT>" , true
        DocumentDraw.TypeKeys "<LEFT>" , true
        sleep(1)
        DocumentDraw.TypeKeys "<MOD1 SHIFT END>" , true
        sleep(1)
        DocumentDraw.TypeKeys "<MOD1 C>" , true
        sleep(1)
        printlog "getClipboard = " + getClipboard
        if ( getClipboard <> "this is a blind text" ) then
            warnlog "The text in the control is not saved"
        end if
        DocumentDraw.TypeKeys "<END>" , true        
        sleep(1)
        DocumentDraw.TypeKeys "<SHIFT MOD1 LEFT>" ,2, true        
        sleep(1)
        FormatCharacter
        Kontext
            active.SetPage TabFontEffects
        Kontext "TabFontEffects"
        if StrikeThrough.getSelIndex() <> 2 then            
            warnlog "StrikeThrought is not set (issue 32921)"
        else
            printlog "StrikeThrought is set"
        end if        
        TabFontEffects.Cancel
        
        sleep(1)
                
    hCloseDocument 
endcase
'--------------------------------------------------------------------------------------
'--------------------------------------------------------------------------------------
'--------------------------------------------------------------------------------------

