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
'* short description : Spellcheck-Testing. Functional-Test.
'*
'\***********************************************************************

sub w_spellcheck1
    Call tLanguage_Guess
end sub

'-------------------------------------------------------------------------

testcase tLanguage_Guess

'Variables:
DIM iStringPosition     AS integer 'Position of string in context menu for word, paragraph
DIM iLanguageCount      AS integer 'variable for counting through languages in test doc
DIM WordPreSet          AS string 'given string for comparison from w_locale_strings2.inc
DIM WordLanguage        AS string '"word is..."entry in context menu
DIM ParagraphLanguage   AS string '"paragraph is..."entry in context menu
DIM ParagraphPreSet     AS string 'given string for comparison of paragraphs from w_locale_strings2.inc
DIM WordLanguageTemp    AS string 'variable for checking if Office language is already covered in w_locale_strings2.inc

    '///Load test document///
    call hFileOpen (ConvertPath ( gTesttoolPath + "writer\optional\input\spellcheck\Language_Guessing_Sample_Texts.odt"))      'loading Test-Doc
    
    sleep(5)
    '----------------------------------------------------------------
    '///Enable auto spellcheck///
    Kontext "Standardbar"
    if AutoSpellcheck.GetState(2) <> 1 then     'cheking if auto-spellcheck is checked
        printlog "Autospellcheck not checked, checking Autospellcheck now"
        AutoSpellcheck.Click
        printlog "Autospellcheck checked"
    else
        printlog "Autospellcheck is already checked"
    end if
    '----------------------------------------------------------------
    ViewNavigator       'opening navigator and selecting table
    sleep(1)
    Call wNavigatorAuswahl(2,1)
    DocumentWriter.TypeKeys "<MOD1 UP>"
    ViewNavigator       'closing navigator
    printlog "-----------------"
    '----------------------------------------------------------------
    '///Put the cursor in the first wrong word///
        
    for iLanguageCount = 1 to 11         'running through the languages
    'checking the word proposal
        printlog "CHECKING WORD:"
        DocumentWriter.TypeKeys "<MOD1 DOWN>"
        DocumentWriter.TypeKeys "<MOD1 DOWN>"
        '///Call context menu///
        DocumentWriter.TypeKeys "<SHIFT F10>"       'calling context menu
        'selecting 'word is... position
        iStringPosition = hMenuItemGetCount - 1     'calculating last but one entry
        
        'getting string from position
        WordLanguage = hMenuItemGetText(iStringPosition)        'gets text from entry
        'printing out string for having a look at the values.
        printlog "WordLanguage is " + WordLanguage
        '///Verify that the language proposal "word is..." is correct///
        WordLanguageTemp = wGetLanguageGuessString("WordPreSet", iLanguageCount) 'comparing reality against the string in w_locale_strings2.inc
        if WordLanguageTemp > "" then 'checking if the language has really an entry in w_locale_strings2.inc
            if WordLanguage = WordLanguageTemp then
                printlog "Word language proposal is correct" 'all ok
            else
                warnlog "Word language proposal is not correct!" 'problem!
            end if
        else
            Call MenuSelect(0) 'closing menu when language is not yet covered
            Call hCloseDocument ''closing doc when language is not yet covered
            exit sub
        end if
        
        '///Apply the language for this word ///
        call hMenuItemCheck (iStringPosition)        'clicking on menu entry, closing context. Word looses redline.
        sleep (1)
        '///Verifiy that the language is set correctly for this word ///
        DocumentWriter.TypeKeys "<SHIFT F10>"       'calling context menu
        iStringPosition = hMenuItemGetCount - 1     'calculating last but one entry
        WordLanguage = hMenuItemGetText(iStringPosition)        'gets text from entry
        if WordLanguage = WordPreSet then ' checking if context menu ahs changed
            warnlog "Word language not applied correctly!" 'Problem!
        else
            printlog "Word language applied correctly" ''all ok
        end if
        Call MenuSelect(0) 'closing menu
        
        '----------------------------------------------------------------
        printlog "CHECKING PARAGRAPH:"
        EditUndo        'undoing hMenuItemCheck from Check-word-part
        DocumentWriter.TypeKeys "<MOD1 LEFT>"
        sleep (1)
        '///Call context menu///
        DocumentWriter.TypeKeys "<SHIFT F10>"       'calling context menu
        'selecting 'paragraph is... position
        iStringPosition = hMenuItemGetCount     'calculating last entry
        'getting string from position
        ParagraphLanguage = hMenuItemGetText(iStringPosition)        'gets text from entry
        'printing out string
        printlog ParagraphLanguage
        '///Verify that the language proposal "paragraph is..." is correct///
        if ParagraphLanguage = wGetLanguageGuessString("ParagraphPreSet", iLanguageCount) then 'comparing reality against the string in w_locale_strings2.inc
            printlog "Paragraph language proposal is correct" 'all ok
        else
            warnlog "Paragraph language proposal is not correct!" 'Problem!
        end if 
        
        
        '///Apply the language for this paragraph ///
        call hMenuItemCheck (iStringPosition)        'clicking on last menu entry, closing context. Paragraph looses redline.
        sleep (1)
        '///Verify that the language is set correctly for this paragraph ///
        DocumentWriter.TypeKeys "<SHIFT F10>"       'calling context menu
        iStringPosition = hMenuItemGetCount     'calculating last entry
        ParagraphLanguage = hMenuItemGetText(iStringPosition)        'gets text from entry
        '///Verify that the language is set correctly for this paragraph ///
        if ParagraphLanguage = ParagraphPreSet then
           warnlog "Paragraph language not applied correctly!" 'Problem
        else
            printlog "Paragraph language applied correctly" 'all ok
        end if
        Call MenuSelect(0) 'closing menu
        printlog "-----------------"
        '///Go to the next text sample ///
        '///Repeat for all western languages ///
    next iLanguageCount
    
    call hCloseDocument      'engl. Test-Doc closed
    '----------------------------------------------------------------
endcase

