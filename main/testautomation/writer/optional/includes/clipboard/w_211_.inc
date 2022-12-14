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

sub w_211_

    Call WriterToCalcText
    Call WriterToCalcField
    Call WriterToCalcTable
    Call WriterToCalcFrame
    Call WriterToCalcDrawingObject
    Call WriterToCalcGraphicLinked  'wrn:1
    Call WriterToCalcGraphicEmbedded
    Call WriterToCalcOLEObject
    Call WriterToCalcControl

end sub

' ---------------------------------------------------------------------------------

testcase WriterToCalcText
    gApplication = "WRITER"
    printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
    printlog "  Jump to beginning of document "
    printlog "  Select first paragraph "
    printlog "  Copy selected text "
    if wSetClipboardtestDefaults("text") = True then
        gApplication = "CALC"
        printlog "  Open new document "
        Call hNewDocument
        printlog "  Edit / Paste Special "
        Sleep 2
        try
            EditPasteSpecialCalc
        catch
            Warnlog "Unable to execute 'Edit / Paste / Special' -> Disabled !"
            Call hCloseDocument
            wait 500
            Call hCloseDocument
            goto endsub
        endcatch
        Wait 500
        printlog "  Paste 'Text' in all available clipboard formats "
        Kontext "InhaltEinfuegen"
        if InhaltEinfuegen.Exists then
            Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"text")
            printlog "  Write Clipboard format under pasted content "
            Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_calc_text.ods", "calc8")
            printlog "  Save document as ..\user\work\writer_to_calc_text.ods"
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
            wait 500
            hFileOpen( gOfficepath + "user\work\writer_to_calc_text.ods",true)
            printlog "  Reopen saved document "
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
        else
            Warnlog "Dialog 'Paste Special' is not up!"
            Call hCloseDocument
            goto endsub
        end if
    else
        Warnlog "Writer To Calc -> 'Text' failed !"
    end if
    printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToCalcField
    gApplication = "WRITER"
    printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
    printlog "  Jump to beginning of document "
    printlog "  Select paragraph with 'Date Field' "
    printlog "  Copy selected text "
    if wSetClipboardtestDefaults("field") = True then
        gApplication = "CALC"
        printlog "  Open new document "
        Call hNewDocument
        printlog "  Edit / Paste Special "
        Sleep 2
        try
            EditPasteSpecialCalc
        catch
            Warnlog "Unable to execute 'Edit / Paste / Special' -> Disabled !"
            Call hCloseDocument
            wait 500
            Call hCloseDocument
            goto endsub
        endcatch
        Wait 500
        printlog "  Paste 'Field' in all available clipboard formats "
        Kontext "InhaltEinfuegen"
        if InhaltEinfuegen.Exists then
            Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"field")
            printlog "  Write Clipboard format under pasted content "
            Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_calc_field.ods", "calc8")
            printlog "  Save document as ..\user\work\writer_to_calc_field.ods"
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
            wait 500
            hFileOpen( gOfficepath + "user\work\writer_to_calc_field.ods",true)
            printlog "  Reopen saved document "
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
        else
            Warnlog "Dialog 'Paste Special' is not up!"
            Call hCloseDocument
            goto endsub
        end if
    else
        Warnlog "Writer To Calc -> 'Field' failed !"
    end if
    printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToCalcTable
    gApplication = "WRITER"
    printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
    printlog "  Jump to beginning of document "
    printlog "  Select 'Table' "
    printlog "  Copy selected table "
    if wSetClipboardtestDefaults("table") = True then
        gApplication = "CALC"
        printlog "  Open new document "
        Call hNewDocument
        printlog "  Edit / Paste Special "
        Sleep 2
        try
            EditPasteSpecialCalc
        catch
            Warnlog "Unable to execute 'Edit / Paste / Special' -> Disabled !"
            Call hCloseDocument
            wait 500
            goto endsub
        endcatch
        Wait 500
        printlog "  Paste 'Table' in all available clipboard formats "
        Kontext "InhaltEinfuegen"
        if InhaltEinfuegen.Exists then
            Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"table")
            kontext "navigator"
            if navigator.exists then navigator.close
            printlog "  Write Clipboard format under pasted content "

            Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_calc_table.ods", "calc8")
            printlog "  Save document as ..\user\work\writer_to_calc_table.ods"
            Wait 500
            printlog "  Close saved document "
            Call hCloseDocument
            wait 500
            kontext "navigator"
            if navigator.exists then navigator.close

            hFileOpen( gOfficepath + "user\work\writer_to_calc_table.ods",false)
            printlog "  Reopen saved document "
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
            kontext "navigator"
            if navigator.exists then navigator.close
        else
            Warnlog "Dialog 'Paste Special' is not up!"
            Call hCloseDocument
            goto endsub
        end if
    else
        Warnlog "Writer To Calc -> 'Table' failed !"
    end if
    printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToCalcFrame
    gApplication = "WRITER"
    printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
    printlog "  Jump to beginning of document "
    printlog "  Select 'Frame' "
    printlog "  Copy selected frame "
    if wSetClipboardtestDefaults("frame") = True then
        gApplication = "CALC"
        printlog "  Open new document "
        Call hNewDocument
        printlog "  Edit / Paste Special "
        Sleep 2
        try
            EditPasteSpecialCalc
        catch
            Warnlog "Unable to execute 'Edit / Paste / Special' -> Disabled !"
            Call hCloseDocument
            wait 500
            Call hCloseDocument
            goto endsub
        endcatch
        Wait 500
        printlog "  Paste 'Table' in all available clipboard formats "
        Kontext "InhaltEinfuegen"
        if InhaltEinfuegen.Exists then
            Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"frame")
            printlog "  Write Clipboard format under pasted content "
            Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_calc_frame.ods", "calc8")
            printlog "  Save document as ..\user\work\writer_to_calc_frame.ods"
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
            wait 500
            hFileOpen( gOfficepath + "user\work\writer_to_calc_frame.ods",false)
            printlog "  Reopen saved document "
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
        else
            Warnlog "Dialog 'Paste Special' is not up!"
            Call hCloseDocument
            goto endsub
        end if
    else
        Warnlog "Writer To Calc -> 'Frame' failed !"
    end if
    printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToCalcDrawingObject
    gApplication = "WRITER"
    printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
    printlog "  Jump to beginning of document "
    printlog "  Select 'Drawing Object' "
    printlog "  Copy selected Drawing Object "
    if wSetClipboardtestDefaults("DRAW") = True then
        gApplication = "CALC"
        printlog "  Open new document "
        Call hNewDocument
        printlog "  Edit / Paste Special "
        Sleep 2
        try
            EditPasteSpecialCalc
        catch
            Warnlog "Unable to execute 'Edit / Paste / Special' -> Disabled !"
            Call hCloseDocument
            wait 500
            Call hCloseDocument
            goto endsub
        endcatch
        Wait 500
        printlog "  Paste 'Table' in all available clipboard formats "
        Kontext "InhaltEinfuegen"
        if InhaltEinfuegen.Exists then
            Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"DRAW")
            printlog "  Write Clipboard format under pasted content "
            Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_calc_draw.ods", "calc8")
            printlog "  Save document as ..\user\work\writer_to_calc_draw.ods"
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
            wait 500
            hFileOpen( gOfficepath + "user\work\writer_to_calc_draw.ods",false)
            printlog "  Reopen saved document "
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
        else
            Warnlog "Dialog 'Paste Special' is not up!"
            Call hCloseDocument
            goto endsub
        end if
    else
        Warnlog "Writer To Calc -> 'Drawing Object' failed !"
    end if
    printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToCalcGraphicLinked
    EnableQaErrors = true
    gApplication = "WRITER"
    printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
    printlog "  Jump to beginning of document "
    printlog "  Select 'Linked Graphic' "
    printlog "  Copy selected Linked Graphic "
    if wSetClipboardtestDefaults("graphicL") = True then
        gApplication = "CALC"
        printlog "  Open new document "
        Call hNewDocument
        printlog "  Edit / Paste Special "
        Sleep 2
        try
            EditPasteSpecialCalc
        catch
            warnlog "Check why linked graphic fails !"
            Call hCloseDocument
            wait 500
            Call hCloseDocument
            goto endsub
        endcatch
        Wait 500
        printlog "  Paste 'Linked Graphic' in all available clipboard formats "
        Kontext "InhaltEinfuegen"
        if InhaltEinfuegen.Exists then
            Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"graphicL")
            printlog "  Write Clipboard format under pasted content "
            Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_calc_graphic1.ods", "calc8")
            printlog "  Save document as ..\user\work\writer_to_calc_graphic1.ods"
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
            wait 500
            hFileOpen( gOfficepath + "user\work\writer_to_calc_graphic1.ods",false)
            printlog "  Reopen saved document "
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
        else
            Warnlog "Dialog 'Paste Special' is not up!"
            Call hCloseDocument
            goto endsub
        end if
    else
        Warnlog "Writer To Calc -> 'Linked Graphic' failed !"
    end if
    printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
    EnableQaErrors = false
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToCalcGraphicEmbedded
    gApplication = "WRITER"
    printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
    printlog "  Jump to beginning of document "
    printlog "  Select 'Embedded Graphic' "
    printlog "  Copy selected Embedded Graphic "
    if wSetClipboardtestDefaults("graphicE") = True then
        gApplication = "CALC"
        printlog "  Open new document "
        Call hNewDocument
        printlog "  Edit / Paste Special "
        Sleep 2
        try
            EditPasteSpecialCalc
        catch
            Warnlog "Unable to execute 'Edit / Paste / Special' -> Disabled !"
            Call hCloseDocument
            wait 500
            Call hCloseDocument
            goto endsub
        endcatch
        Wait 500
        printlog "  Paste 'Embedded Graphic' in all available clipboard formats "
        Kontext "InhaltEinfuegen"
        if InhaltEinfuegen.Exists then
            Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"graphicE")
            printlog "  Write Clipboard format under pasted content "
            Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_calc_graphic2.ods", "calc8")
            printlog "  Save document as ..\user\work\writer_to_calc_graphic2.ods"
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
            wait 500
            hFileOpen( gOfficepath + "user\work\writer_to_calc_graphic2.ods",false)
            printlog "  Reopen saved document "
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
        else
            Warnlog "Dialog 'Paste Special' is not up!"
            Call hCloseDocument
            goto endsub
        end if
    else
        Warnlog "Writer To Calc -> 'Embedded Graphic' failed !"
    end if
    printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToCalcOLEObject
    gApplication = "WRITER"
    printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
    printlog "  Jump to beginning of document "
    printlog "  Select 'OLE Object' "
    printlog "  Copy selected OLE Object "
    if wSetClipboardtestDefaults("ole") = True then
        gApplication = "CALC"
        printlog "  Open new document "
        Call hNewDocument
        printlog "  Edit / Paste Special "
        Sleep 2
        try
            EditPasteSpecialCalc
        catch
            Warnlog "Unable to execute 'Edit / Paste / Special' -> Disabled !"
            Call hCloseDocument
            wait 500
            Call hCloseDocument
            goto endsub
        endcatch
        Wait 500
        printlog "  Paste 'OLE object' in all available clipboard formats "
        Kontext "InhaltEinfuegen"
        if InhaltEinfuegen.Exists then
            Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"ole")
            printlog "  Write Clipboard format under pasted content "
            Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_calc_ole.ods", "calc8")
            printlog "  Save document as ..\user\work\writer_to_calc_ole.ods"
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
            wait 500
            hFileOpen( gOfficepath + "user\work\writer_to_calc_ole.ods",false)
            printlog "  Reopen saved document "
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
        else
            Warnlog "Dialog 'Paste Special' is not up!"
            Call hCloseDocument
            goto endsub
        end if
    else
        Warnlog "Writer To Calc -> 'OLE object' failed !"
    end if
    printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase

' ----------------------------------------------------------------------------------------------

testcase WriterToCalcControl
    gApplication = "WRITER"
    printlog "  Open File '..\\writer\\optional\\input\\clipboard\\writer.sxw' "
    printlog "  Jump to beginning of document "
    printlog "  Select 'Control' "
    printlog "  Copy selected Control "
    if wSetClipboardtestDefaults("control") = True then
        gApplication = "CALC"
        printlog "  Open new document "
        Call hNewDocument
        printlog "  Edit / Paste Special "
        Sleep 2
        try
            EditPasteSpecialCalc
        catch
            Warnlog "Unable to execute 'Edit / Paste / Special' -> Disabled !"
            Call hCloseDocument
            wait 500
            Call hCloseDocument
            goto endsub
        endcatch
        Wait 500
        printlog "  Paste 'Control' in all available clipboard formats "
        Kontext "InhaltEinfuegen"
        if InhaltEinfuegen.Exists then
            Call wPasteAvailableClipboardFormats(Auswahl.GetItemCount,"control")
            printlog "  Write Clipboard format under pasted content "
            Call hFileSaveAsWithFilterKill (gOfficepath + "user\work\writer_to_calc_control.ods", "calc8")
            printlog "  Save document as ..\user\work\writer_to_calc_control.ods"
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
            wait 500
            hFileOpen( gOfficepath + "user\work\writer_to_calc_control.ods",false)
            printlog "  Reopen saved document "
            Wait 500
            Call hCloseDocument
            printlog "  Close saved document "
        else
            Warnlog "Dialog 'Paste Special' is not up!"
            Call hCloseDocument
            goto endsub
        end if
    else
        Warnlog "Writer To Calc -> 'Control' failed !"
    end if
    printlog "  Close active document "
    Do Until GetDocumentCount = 0
        Call hCloseDocument
    Loop
endcase
