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

sub w_221_

    Call DrawToHTMLScrollingText
    Call DrawToHTMLGroupedObject
    Call DrawToHTML3D
    Call DrawToHTMLFontwork
    Call DrawToHTMLBullets
    Call DrawToHTMLDimensionLines
    Call DrawToHTMLConnectors

end sub


testcase DrawToHTMLScrollingText

  gApplication = "DRAW"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\draw.sxd' "
  printlog " + Jump to beginning of document "
  printlog " + Select Scrolling text "
  printlog " + Copy selected text "
  hFileOpenLocally( gtesttoolpath & "writer\optional\input\clipboard\draw.sxd")
  
  Kontext "DocumentDraw"
  printlog "  Jump to beginning of document "
  DocumentDraw.TypeKeys "<Tab>"
  EditCopy
  gApplication = "HTML"
  printlog "  Open a new writerdocument "
  Call hNewDocument
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
  printlog "  Paste 'Scrolling Text' in all available clipboard formats "
  Kontext "InhaltEinfuegen"
  if InhaltEinfuegen.Exists then
    Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"DRAW")
    printlog " + Write Clipboard format under pasted content "
    Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\draw_to_html_scrolling_text.html", "HTML")
    printlog " + Save document as ..\user\work\draw_to_html_scrolling_text.html"
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
    wait 500
    hFileOpen( gOfficepath + "user\work\draw_to_html_scrolling_text.html",false)
    printlog " + Reopen saved document "
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
  else
    Warnlog "Dialog 'Paste Special' is not up!"
    Call hCloseDocument
    goto endsub
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ---------------------------------------------------------------------------------

testcase DrawToHTMLGroupedObject

  gApplication = "DRAW"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\draw.sxd' "
  printlog " + Jump to beginning of document "
  printlog " + Select Grouped Object "
  printlog " + Copy selected Object "
  hFileOpenLocally( gtesttoolpath & "writer\optional\input\clipboard\draw.sxd")
  
  Kontext "DocumentDraw"
  printlog "  Jump to beginning of document "
  DocumentDraw.TypeKeys "<Tab>",2
  EditCopy
  gApplication = "HTML"
  printlog "  Open a new writerdocument "
  Call hNewDocument
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
    Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"DRAW")
    printlog " + Write Clipboard format under pasted content "
    Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\draw_to_html_grouped_object.html", "HTML")
    printlog " + Save document as ..\user\work\draw_to_html_grouped_object.html"
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
    wait 500
    hFileOpen( gOfficepath + "user\work\draw_to_html_grouped_object.html",false)
    printlog " + Reopen saved document "
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
  else
    Warnlog "Dialog 'Paste Special' is not up!"
    Call hCloseDocument
    goto endsub
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ---------------------------------------------------------------------------------

testcase DrawToHTML3D

  gApplication = "DRAW"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\draw.sxd' "
  printlog " + Jump to beginning of document "
  printlog " + Select cell <A5:C5> "
  printlog " + Copy selected text "
  hFileOpenLocally( gtesttoolpath & "writer\optional\input\clipboard\draw.sxd")
  
  Kontext "DocumentDraw"
  printlog "  Jump to beginning of document "
  DocumentDraw.TypeKeys "<Tab>",3
  EditCopy
  gApplication = "HTML"
  printlog "  Open a new writerdocument "
  Call hNewDocument
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
    Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"DRAW")
    printlog " + Write Clipboard format under pasted content "
    Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\draw_to_html_3d.html", "HTML")
    printlog " + Save document as ..\user\work\draw_to_html_3d.html"
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
    wait 500
    hFileOpen( gOfficepath + "user\work\draw_to_html_3d.html",false)
    printlog " + Reopen saved document "
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
  else
    Warnlog "Dialog 'Paste Special' is not up!"
    Call hCloseDocument
    goto endsub
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ---------------------------------------------------------------------------------

testcase DrawToHTMLFontwork

  gApplication = "DRAW"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\draw.sxd' "
  printlog " + Jump to beginning of document "
  printlog " + Select Fontwork "
  printlog " + Copy selected Fontwork "
  hFileOpenLocally( gtesttoolpath & "writer\optional\input\clipboard\draw.sxd")
  
  Kontext "DocumentDraw"
  printlog "  Jump to beginning of document "
  DocumentDraw.TypeKeys "<Tab>",4
  EditCopy
  gApplication = "HTML"
  printlog "  Open a new writerdocument "
  Call hNewDocument
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
    Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"DRAW")
    printlog " + Write Clipboard format under pasted content "
    Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\draw_to_html_fontwork.html", "HTML")
    printlog " + Save document as ..\user\work\draw_to_html_fontwork.html"
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
    wait 500
    hFileOpen( gOfficepath + "user\work\draw_to_html_fontwork.html",false)
    printlog " + Reopen saved document "
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
  else
    Warnlog "Dialog 'Paste Special' is not up!"
    Call hCloseDocument
    goto endsub
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ---------------------------------------------------------------------------------

testcase DrawToHTMLBullets

  gApplication = "DRAW"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\draw.sxd' "
  printlog " + Jump to beginning of document "
  printlog " + Select Bullets "
  printlog " + Copy selected Bullets "
  hFileOpenLocally( gtesttoolpath & "writer\optional\input\clipboard\draw.sxd")
  
  Kontext "DocumentDraw"
  printlog "  Jump to beginning of document "
  DocumentDraw.TypeKeys "<Tab>",5
  EditCopy
  gApplication = "HTML"
  printlog "  Open a new writerdocument "
  Call hNewDocument
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
    Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"DRAW")
    printlog " + Write Clipboard format under pasted content "
    Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\draw_to_html_bullets.html", "HTML")
    printlog " + Save document as ..\user\work\draw_to_html_bullets.html"
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
    wait 500
    hFileOpen( gOfficepath + "user\work\draw_to_html_bullets.html",false)
    printlog " + Reopen saved document "
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
  else
    Warnlog "Dialog 'Paste Special' is not up!"
    Call hCloseDocument
    goto endsub
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ---------------------------------------------------------------------------------

testcase DrawToHTMLDimensionLines

  gApplication = "DRAW"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\draw.sxd' "
  printlog " + Jump to beginning of document "
  printlog " + Select Dimension Lines "
  printlog " + Copy selected Dimension Lines "
  hFileOpenLocally( gtesttoolpath & "writer\optional\input\clipboard\draw.sxd")
  
  Kontext "DocumentDraw"
  printlog "  Jump to beginning of document "
  DocumentDraw.TypeKeys "<PageDown>"
  DocumentDraw.TypeKeys "<Tab>"
  EditCopy
  gApplication = "HTML"
  printlog "  Open a new writerdocument "
  Call hNewDocument
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
  printlog "  Paste 'Dimension Lines' in all available clipboard formats "
  Kontext "InhaltEinfuegen"
  if InhaltEinfuegen.Exists then
    Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"DRAW")
    printlog " + Write Clipboard format under pasted content "
    Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\draw_to_html_dim_lines.html", "HTML")
    printlog " + Save document as ..\user\work\draw_to_html_dim_lines.html"
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
    wait 500
    hFileOpen( gOfficepath + "user\work\draw_to_html_dim_lines.html",false)
    printlog " + Reopen saved document "
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
  else
    Warnlog "Dialog 'Paste Special' is not up!"
    Call hCloseDocument
    goto endsub
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ---------------------------------------------------------------------------------

testcase DrawToHTMLConnectors

  gApplication = "DRAW"
  printlog "  Open File '..\\writer\\optional\\input\\clipboard\\draw.sxd' "
  printlog " + Jump to beginning of document "
  printlog " + Select Connectors "
  printlog " + Copy selected Connectors "
  hFileOpenLocally( gtesttoolpath & "writer\optional\input\clipboard\draw.sxd")
  
  Kontext "DocumentDraw"
  printlog "  Jump to beginning of document "
  DocumentDraw.TypeKeys "<PageDown>"
  DocumentDraw.TypeKeys "<Tab>"
  EditCopy
  gApplication = "HTML"
  printlog "  Open a new writerdocument "
  Call hNewDocument
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
  printlog "  Paste 'Connectors' in all available clipboard formats "
  Kontext "InhaltEinfuegen"
  if InhaltEinfuegen.Exists then
    Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"DRAW")
    printlog " + Write Clipboard format under pasted content "
    Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\draw_to_html_connectors.html", "HTML")
    printlog " + Save document as ..\user\work\draw_to_html_connectors.html"
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
    wait 500
    hFileOpen( gOfficepath + "user\work\draw_to_html_connectors.html",false)
    printlog " + Reopen saved document "
    Wait 500
    Call hCloseDocument
    printlog " + Close saved document "
  else
    Warnlog "Dialog 'Paste Special' is not up!"
    Call hCloseDocument
    goto endsub
  end if
  printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

