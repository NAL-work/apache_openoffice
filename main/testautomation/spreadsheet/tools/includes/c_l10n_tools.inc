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
'* short description : tools for localisation in calc
'*
'\************************************************************************************************

function fFunctionname ( sFunctionname_en as string ) as string

    '///<b>The function returns the localized name of a given function in the current UI language</b>
    '///+ -Input is the english name of the function as string
    '///+ -Output is the localized name of the function as string
    '///+ -If there is no translation available the fallback is the english name

    dim sloaddocument as string
    dim sfunctionstring as string
    dim scelladress as string

    use "global/tools/includes/required/t_doc2.inc"
    const CFN = "spreadsheet:tools:includes:c_l10n_tools.in:fFunctionname "

    sloaddocument = gTesttoolPath & "spreadsheet\tools\input\Functionnames.ods"

    '///Load document with all functions <i>gTestToolPath</i>/spreadsheet/tools/input/Functionnames.ods
    hFileOpenLocally( sloaddocument )
    sleep (2)

    '///Setting selection to A1 to avoid messagebox in Search and Replace dialog.
    call fCalcSelectRange ("A1")
    '///Search for function by Search and Replace dialog
    kontext "DocumentCalc"
    EditSearchAndReplace

    kontext "FindAndReplace"
    printlog( "Reset <Find and Replace> dialog to default settings" )
    if ( FindAndReplace.exists( 1 ) ) then
        More.Click
        SimilaritySearch.UnCheck
        CurrentSelectionOnly.UnCheck
        Backwards.UnCheck
        SearchForStyles.UnCheck
        SearchIn.Select 1
        '///Setting search parameter
        WholeWordsOnly.Check
        SearchFor.SetText sFunctionname_en
        SearchNow.click
        kontext
        '///If a MsgBox appears the search must have failed => Fallback to english name
        if active.exists then
            if active.getRT = 304 then
                warnlog CFN & "Function not found, falling back to english name"
                fFunctionname = sFunctionname_en
                active.OK
            else
                '///Throw a warning if a dialog of unexpected resource type appears
                warnlog CFN & "Unknown message box! " & active.GetText
                active.Default
                fFunctionname = sFunctionname_en
            end if

            kontext "FindAndReplace"
            printlog( "Reset dialog to default settings" )
            if ( FindAndReplace.exists( 1 ) ) then
                WholeWordsOnly.UnCheck
                hCloseDialog( FindAndReplace, "close" )
            else
                warnlog( CFN & "<FindAndReplace> not open" )
            endif
            call hCloseDocument
            exit function
        end if

        kontext "FindAndReplace"
        printlog( "Reset <Find and Replace> dialog to default settings" )
        if ( FindAndReplace.exists( 1 ) ) then
            WholeWordsOnly.UnCheck
            hCloseDialog( FindAndReplace, "close" )
        else
            warnlog( CFN & "<FindAndReplace> not open" )
        endif

        Kontext "RechenleisteCalc"
        scelladress = Bereich.GetSelText
        if fCalcGetCellValue (scelladress) = sFunctionname_en then
            '///Get localised string for function by extracting functionname out of next cell
            call fCalcSelectRange ( "B" & mid(scelladress,2) )
            kontext ( "RechenleisteCalc" )
            EingabeZeileCalc.TypeKeys ("<f2><mod1 a>")
            editcopy
            sfunctionstring = GetClipboardText ()
            kontext "DocumentCalc"
            DocumentCalc.TypeKeys ("<ESCAPE>",2)
            ' DEBUG: printlog sfunctionstring
            ' DEBUG: printlog len(sfunctionstring)
            ' DEBUG: printlog instr(sfunctionstring,"(")
            fFunctionname = mid(sfunctionstring,2,(instr(sfunctionstring,"(")-2)
            printlog "  The name of the function in this locale (" & iSprache & ") is " & fFunctionname
        else
            warnlog CFN & "Function not found, falling back to english version"
            fFunctionname = sFunctionname_en
        end if
    else
        warnlog( CFN & "Unable to open <FindAndReplace> dialog" )
    endif

    call hCloseDocument
    hFileDelete( gLastWorkFile )

end function

'
'----------------------------------------------------------------------------
'

function fError_l10n ( sError_en as string ) as string

    '///<b>The function returns the localized name of a given error in the current UI language</b>
    '///+ -Input is the english name of the error as string
    '///+ -Output is the localized name of the error as string
    '///+ -If there is no translation available the fallback is the english name

    dim sloaddocument as string
    dim sfunctionstring as string
    dim scelladress as string

    use "global/tools/includes/required/t_doc2.inc"
    const CFN = "qa:qatesttool:spreadsheet:tools:includes:c_l10n_tools.in:fError_l10n "

    sloaddocument = gTesttoolPath & "spreadsheet\tools\input\Errorcodes.ods"

    '///Load document with all errorcodes <i>gTestToolPath</i>/spreadsheet/tools/input/Errorcodes.ods
    hFileOpenLocally( sloaddocument )

    '///Setting selection to A1 to avoid messagebox in Search and Replace dialog.
    call fCalcSelectRange ("A1")
    '///Search for function by Search and Replace dialog
    kontext "DocumentCalc"
    EditSearchAndReplace
    sleep (1)
    kontext "FindAndReplace"
    '///Setting dialog to defaults
    More.Click
    SimilaritySearch.UnCheck
    CurrentSelectionOnly.UnCheck
    Backwards.UnCheck
    SearchForStyles.UnCheck
    SearchIn.Select 1
    '///Setting search parameter
    WholeWordsOnly.Check
    SearchFor.SetText sError_en
    SearchNow.click
    kontext
    '///If a MsgBox appears the search must have failed => Fallback to english name
    if active.exists then
        if active.getRT = 304 then
            warnlog CFN & "Function not found, falling back to english name"
            fError_l10n = sError_en
            active.OK
        else
            '///Throw a warning if a dialog of unexpected resource type appears
            warnlog CFN & "Unknown message box! " & active.GetText
            active.Default
            fError_l10n = sError_en
        end if

        kontext "FindAndReplace"
        '///Reset dialog to defaultsetting
        if ( FindAndReplace.exists( 1 ) ) then
            WholeWordsOnly.UnCheck
            hCloseDialog( FindAndReplace, "close" )
        else
            warnlog( CFN & "Failed to open <FindAndReplace>" )
        endif

        call hCloseDocument
        exit function
    end if

    kontext "FindAndReplace"
    '///Reset dialog to defaultsetting
    if ( FindAndReplace.exists( 1 ) ) then
        WholeWordsOnly.UnCheck
        hCloseDialog( FindAndReplace, "close" )
    else
        warnlog( CFN & "Failed to open <FindAndReplace>" )
    endif
    
    Kontext "RechenleisteCalc"
    scelladress = Bereich.GetSelText
    if fCalcGetCellValue (scelladress) = sError_en then
        '///Get localised string for ERR by extracting errorcode out of next cell
        call fCalcSelectRange ( "B" & mid(scelladress,2) )
        kontext "DocumentCalc"
        editcopy
        fError_l10n = GetClipboardText ()
        kontext "DocumentCalc"
        printlog "  The name for ERR in this locale (" & iSprache & ") is " & fError_l10n
    else
        warnlog CFN & "Errorcode not found, falling back to english version"
        fError_l10n = sError_en
    end if

    call hCloseDocument
    hFileDelete( gLastWorkFile )

end function
