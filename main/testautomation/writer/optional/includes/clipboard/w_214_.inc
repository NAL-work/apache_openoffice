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
'* short description : CROSS-APPLICATIONS CLIPBOARD TEST (Writer)
'*
'\***********************************************************************

sub w_214_

    Call WriterToHTMLText
    Call WriterToHTMLField
    Call WriterToHTMLTable
    Call WriterToHTMLFrame
    Call WriterToHTMLDrawingObject
    Call WriterToHTMLGraphicLinked
    Call WriterToHTMLGraphicEmbedded
    Call WriterToHTMLOLEObject
    Call WriterToHTMLControl

end sub

' ---------------------------------------------------------------------------------

testcase WriterToHTMLText
  gApplication = "WRITER"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
  printlog " + Jump to beginning of document "
  printlog " + Select first paragraph "
  printlog " + Copy selected text "
  if wSetClipboardtestDefaults("text") = True then
    gApplication = "HTML"
    printlog " + Open new document "
    Call hNewDocument
    printlog " + Edit / Paste Special "
    Sleep 2
    try
       EditPasteSpecialWriter
    catch
       Warnlog "Unable to execute 'Edit / Paste Special' ! Test failed!"
       Call hCloseDocument ' Close Source-File
       Call hCloseDocument ' Close Target-File
       goto endsub
    endcatch
    Wait 500
    printlog "  Paste 'Text' in all available clipboard formats "
    Kontext "InhaltEinfuegen"
    if InhaltEinfuegen.Exists then
     Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"text")
    printlog " + Write Clipboard format under pasted content "
     Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_html_text.html", "HTML")
     printlog " + Save document as ..\user\work\writer_to_html_text.html"
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
     wait 500
     hFileOpen( gOfficepath + "user\work\writer_to_html_text.html")
     printlog " + Reopen saved document "
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
    else
     Warnlog "Dialog 'Paste Special' is not up!"
     Call hCloseDocument
     goto endsub
    end if
  else
   Warnlog "Writer To HTML -> 'Text' failed !"
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToHTMLField
  gApplication = "WRITER"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
  printlog " + Jump to beginning of document "
  printlog " + Select paragraph with 'Date Field' "
  printlog " + Copy selected text "
  if wSetClipboardtestDefaults("field") = True then
    gApplication = "HTML"
    printlog " + Open new document "
    Call hNewDocument
    printlog " + Edit / Paste Special "
    Sleep 2
    try
       EditPasteSpecialWriter
    catch
       Warnlog "Unable to execute 'Edit / Paste Special' ! Test failed!"
       Call hCloseDocument ' Close Source-File
       Call hCloseDocument ' Close Target-File
       goto endsub
    endcatch
    Wait 500
    printlog "  Paste 'Field' in all available clipboard formats "
    Kontext "InhaltEinfuegen"
    if InhaltEinfuegen.Exists then
     Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"field")
    printlog " + Write Clipboard format under pasted content "
     Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_html_field.html", "HTML")
     printlog " + Save document as ..\user\work\writer_to_html_field.html"
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
     wait 500
     hFileOpen( gOfficepath + "user\work\writer_to_html_field.html")
     printlog " + Reopen saved document "
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
    else
     Warnlog "Dialog 'Paste Special' is not up!"
     Call hCloseDocument
     goto endsub
    end if
  else
   Warnlog "Writer To HTML -> 'Field' failed !"
  end if
    printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToHTMLTable
  gApplication = "WRITER"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
  printlog " + Jump to beginning of document "
  printlog " + Select 'Table' "
  printlog " + Copy selected table "
  if wSetClipboardtestDefaults("table") = True then
    gApplication = "HTML"
    printlog " + Open new document "
    Call hNewDocument
    printlog " + Edit / Paste Special "
    Sleep 2
    try
       EditPasteSpecialWriter
    catch
       Warnlog "Unable to execute 'Edit / Paste Special' ! Test failed!"
       Call hCloseDocument ' Close Source-File
       Call hCloseDocument ' Close Target-File
       goto endsub
    endcatch
    Wait 500
    printlog "  Paste 'Table' in all available clipboard formats "
    Kontext "InhaltEinfuegen"
    if InhaltEinfuegen.Exists then
     Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"table")
     printlog " + Write Clipboard format under pasted content "
     Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_html_table.html", "HTML")
     printlog " + Save document as ..\user\work\writer_to_html_table.html"
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
     wait 500
     hFileOpen( gOfficepath + "user\work\writer_to_html_table.html")
     printlog " + Reopen saved document "
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
    else
     Warnlog "Dialog 'Paste Special' is not up!"
     Call hCloseDocument
     goto endsub
    end if
  else
   Warnlog "Writer To HTML -> 'Table' failed !"
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToHTMLFrame
  gApplication = "WRITER"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
  printlog " + Jump to beginning of document "
  printlog " + Select 'Frame' "
  printlog " + Copy selected frame "
  if wSetClipboardtestDefaults("frame") = True then
    gApplication = "HTML"
    printlog " + Open new document "
    Call hNewDocument
    printlog " + Edit / Paste Special "
    Sleep 2
    try
       EditPasteSpecialWriter
    catch
       Warnlog "Unable to execute 'Edit / Paste Special' ! Test failed!"
       Call hCloseDocument ' Close Source-File
       Call hCloseDocument ' Close Target-File
       goto endsub
    endcatch
    Wait 500
    printlog "  Paste 'Table' in all available clipboard formats "
    Kontext "InhaltEinfuegen"
    if InhaltEinfuegen.Exists then
     Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"frame")
     printlog " + Write Clipboard format under pasted content "
     Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_html_frame.html", "HTML")
     printlog " + Save document as ..\user\work\writer_to_html_frame.html"
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
     wait 500
     hFileOpen( gOfficepath + "user\work\writer_to_html_frame.html")
     printlog " + Reopen saved document "
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
    else
     Warnlog "Dialog 'Paste Special' is not up!"
     Call hCloseDocument
     goto endsub
    end if
  else
   Warnlog "Writer To HTML -> 'Frame' failed !"
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToHTMLDrawingObject
  gApplication = "WRITER"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
  printlog " + Jump to beginning of document "
  printlog " + Select 'Drawing Object' "
  printlog " + Copy selected Drawing Object "
  if wSetClipboardtestDefaults("DRAW") = True then
    gApplication = "HTML"
    printlog " + Open new document "
    Call hNewDocument
    printlog " + Edit / Paste Special "
    Sleep 2
    try
       EditPasteSpecialWriter
    catch
       Warnlog "Unable to execute 'Edit / Paste Special' ! Test failed!"
       Call hCloseDocument ' Close Source-File
       Call hCloseDocument ' Close Target-File
       goto endsub
    endcatch
    Wait 500
    printlog "  Paste 'Table' in all available clipboard formats "
    Kontext "InhaltEinfuegen"
    if InhaltEinfuegen.Exists then
     Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"DRAW")
     printlog " + Write Clipboard format under pasted content "
     Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_html_draw.html", "HTML")
     printlog " + Save document as ..\user\work\writer_to_html_draw.html"
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
     wait 500
     hFileOpen( gOfficepath + "user\work\writer_to_html_draw.html")
     printlog " + Reopen saved document "
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
    else
     Warnlog "Dialog 'Paste Special' is not up!"
     Call hCloseDocument
     goto endsub
    end if
  else
   Warnlog "Writer To HTML -> 'Drawing Object' failed !"
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToHTMLGraphicLinked
  gApplication = "WRITER"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
  printlog " + Jump to beginning of document "
  printlog " + Select 'Linked Graphic' "
  printlog " + Copy selected Linked Graphic "
  if wSetClipboardtestDefaults("graphicL") = True then
    gApplication = "HTML"
    printlog " + Open new document "
    Call hNewDocument
    printlog " + Edit / Paste Special "
    Sleep 2
    try
       EditPasteSpecialWriter
    catch
       Warnlog "Unable to execute 'Edit / Paste Special' ! Test failed!"
       Call hCloseDocument ' Close Source-File
       Call hCloseDocument ' Close Target-File
       goto endsub
    endcatch
    Wait 500
    printlog "  Paste 'Linked Graphic' in all available clipboard formats "
    Kontext "InhaltEinfuegen"
    if InhaltEinfuegen.Exists then
     Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"graphicL")
     printlog " + Write Clipboard format under pasted content "
     Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_html_graphic1.html", "HTML")
     printlog " + Save document as ..\user\work\writer_to_html_graphic1.html"
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
     wait 500
     hFileOpen( gOfficepath + "user\work\writer_to_html_graphic1.html")
     printlog " + Reopen saved document "
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
    else
     Warnlog "Dialog 'Paste Special' is not up!"
     Call hCloseDocument
     goto endsub
    end if
  else
   Warnlog "Writer To HTML -> 'Linked Graphic' failed !"
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToHTMLGraphicEmbedded
  gApplication = "WRITER"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
  printlog " + Jump to beginning of document "
  printlog " + Select 'Embedded Graphic' "
  printlog " + Copy selected Embedded Graphic "
  if wSetClipboardtestDefaults("graphicE") = True then
    gApplication = "HTML"
    printlog " + Open new document "
    Call hNewDocument
    printlog " + Edit / Paste Special "
    Sleep 2
    try
       EditPasteSpecialWriter
    catch
       Warnlog "Unable to execute 'Edit / Paste Special' ! Test failed!"
       Call hCloseDocument ' Close Source-File
       Call hCloseDocument ' Close Target-File
       goto endsub
    endcatch
    Wait 500
    printlog "  Paste 'Embedded Graphic' in all available clipboard formats "
    Kontext "InhaltEinfuegen"
    if InhaltEinfuegen.Exists then
     Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"graphicE")
     printlog " + Write Clipboard format under pasted content "
     Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_html_graphic2.html", "HTML")
     printlog " + Save document as ..\user\work\writer_to_html_graphic2.html"
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
     wait 500
     hFileOpen( gOfficepath + "user\work\writer_to_html_graphic2.html")
     printlog " + Reopen saved document "
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
    else
     Warnlog "Dialog 'Paste Special' is not up!"
     Call hCloseDocument
     goto endsub
    end if
  else
   Warnlog "Writer To HTML -> 'Embedded Graphic' failed !"
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToHTMLOLEObject
  gApplication = "WRITER"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
  printlog " + Jump to beginning of document "
  printlog " + Select 'OLE Object' "
  printlog " + Copy selected OLE Object "
  if wSetClipboardtestDefaults("ole") = True then
    gApplication = "HTML"
    printlog " + Open new document "
    Call hNewDocument
    printlog " + Edit / Paste Special "
    Sleep 2
    try
       EditPasteSpecialWriter
    catch
       Warnlog "Unable to execute 'Edit / Paste Special' ! Test failed!"
       Call hCloseDocument ' Close Source-File
       Call hCloseDocument ' Close Target-File
       goto endsub
    endcatch
    Wait 500
    printlog "  Paste 'OLE object' in all available clipboard formats "
    Kontext "InhaltEinfuegen"
    if InhaltEinfuegen.Exists then
     Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"ole")
     printlog " + Write Clipboard format under pasted content "
     Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_html_ole.html", "HTML")
     printlog " + Save document as ..\user\work\writer_to_html_ole.html"
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
     wait 500
     hFileOpen( gOfficepath + "user\work\writer_to_html_ole.html")
     printlog " + Reopen saved document "
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
    else
     Warnlog "Dialog 'Paste Special' is not up!"
     Call hCloseDocument
     goto endsub
    end if
  else
   Warnlog "Writer To HTML -> 'OLE object' failed !"
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToHTMLControl
  gApplication = "WRITER"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
  printlog " + Jump to beginning of document "
  printlog " + Select 'Control' "
  printlog " + Copy selected Control "
  if wSetClipboardtestDefaults("control") = True then
    gApplication = "HTML"
    printlog " + Open new document "
    Call hNewDocument
    printlog " + Edit / Paste Special "
    Sleep 2
    try
       EditPasteSpecialWriter
    catch
       Warnlog "Unable to execute 'Edit / Paste Special' ! Test failed!"
       Call hCloseDocument ' Close Source-File
       Call hCloseDocument ' Close Target-File
       goto endsub
    endcatch
    Wait 500
    printlog "  Paste 'Control' in all available clipboard formats "
    Kontext "InhaltEinfuegen"
    if InhaltEinfuegen.Exists then
     Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"control")
     printlog " + Write Clipboard format under pasted content "
     Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_html_control.html", "HTML")
     printlog " + Save document as ..\user\work\writer_to_html_control.html"
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
     wait 500
     hFileOpen( gOfficepath + "user\work\writer_to_html_control.html")
     printlog " + Reopen saved document "
     Wait 500
     Call hCloseDocument
     printlog " + Close saved document "
    else
     Warnlog "Dialog 'Paste Special' is not up!"
     Call hCloseDocument
     goto endsub
    end if
  else
   Warnlog "Writer To HTML -> 'Control' failed !"
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

'------------------------------------------------------------------------------------------------------
