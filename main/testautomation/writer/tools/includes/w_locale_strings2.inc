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
'* short description : defining locale dependant strings for language guessing
'*
'\***********************************************************************
function wGetLanguageGuessString(sValue as string, iLanguageCount as integer) as string 'function for getting strings out of this file

    'Variables:
    DIM WordPreSet as string 'string as it shoud be for words
    DIM ParagraphPreSet as string 'string as it shoud be for paragraphs

    '///already covered Office languages: ///'
    '///english     01 ///'
    '///russian     07 ///'
    '///dutch       31 ///'
    '///french      33///'
    '///spanish     34 ///'
    '///hungarian   36 ///'
    '///italian     39 ///'
    '///swedish     46 ///'
    '///polish      48 ///'
    '///german      49 ///'
    '///slovenian      50 ///'
    '///german      55 ///'

    '///already covered languages in the test document: ///'
    '///Case 1: english ///'
    '///Case 2: portugese///'
    '///Case 3: russian///'
    '///Case 4: dutch///'
    '///Case 5: french///'
    '///Case 6: spanish///'
    '///Case 7: hungarian///'
    '///Case 8: italian///'
    '///Case 9: swedish///'
    '///Case 10: polish///'
    '///Case 11: german///'

    Select Case iSprache        'Detecting Office language
    Case 01         'Case 01:  english
        '-----------------------------------------------------------------------
        Select Case iLanguageCount
        Case 1: WordPreSet      = "Word is English (USA)"
            ParagraphPreSet = "Paragraph is English (USA)"
        Case 2: WordPreSet      = "Word is Portuguese (Portugal)"
            ParagraphPreSet = "Paragraph is Portuguese (Portugal)"
        Case 3: WordPreSet      = "Word is Russian"
            ParagraphPreSet = "Paragraph is Russian"
        Case 4: WordPreSet      = "Word is Dutch (Netherlands)"
            ParagraphPreSet = "Paragraph is Dutch (Netherlands)"
        Case 5: WordPreSet      = "Word is French (France)"
            ParagraphPreSet = "Paragraph is French (France)"
        Case 6: WordPreSet      = "Word is Spanish (Spain)"
            ParagraphPreSet = "Paragraph is Spanish (Spain)"
        Case 7: WordPreSet      = "Word is Hungarian"
            ParagraphPreSet = "Paragraph is Hungarian"
        Case 8: WordPreSet      = "Word is Italian (Italy)"
            ParagraphPreSet = "Paragraph is Italian (Italy)"
        Case 9: WordPreSet      = "Word is Swedish (Sweden)"
            ParagraphPreSet = "Paragraph is Swedish (Sweden)"
        Case 10:WordPreSet      = "Word is Polish"
            ParagraphPreSet = "Paragraph is Polish"
        Case 11:WordPreSet      = "Word is German (Germany)"
            ParagraphPreSet = "Paragraph is German (Germany)"
        end select
        '-----------------------------------------------------------------------
    Case 07        'Case 07: russian
        Select Case iLanguageCount
        Case 1: WordPreSet      = "???????? ??????????: ???????????????????? (??????)"
            ParagraphPreSet = "???????? ????????????: ???????????????????? (??????)"
        Case 2: WordPreSet      = "???????? ??????????: ?????????????????????????? (????????????????????)"
            ParagraphPreSet = "???????? ????????????: ?????????????????????????? (????????????????????)"
        Case 3: WordPreSet      = "???????? ??????????: ??????????????"
            ParagraphPreSet = "???????? ????????????: ??????????????"
        Case 4: WordPreSet      = "???????? ??????????: ?????????????????????? (????????????????????)"
            ParagraphPreSet = "???????? ????????????: ?????????????????????? (????????????????????)"
        Case 5: WordPreSet      = "???????? ??????????: ?????????????????????? (??????????????)"
            ParagraphPreSet = "???????? ????????????: ?????????????????????? (??????????????)"
        Case 6: WordPreSet      = "???????? ??????????: ?????????????????? (??????????????)"
            ParagraphPreSet = "???????? ????????????: ?????????????????? (??????????????)"
        Case 7: WordPreSet      = "???????? ??????????: ????????????????????"
            ParagraphPreSet = "???????? ????????????: ????????????????????"
        Case 8: WordPreSet      = "???????? ??????????: ?????????????????????? (????????????) "
            ParagraphPreSet = "???????? ????????????: ?????????????????????? (????????????) "
        Case 9: WordPreSet      = "???????? ??????????: ???????????????? (????????????)"
            ParagraphPreSet = "???????? ????????????: ???????????????? (????????????)"
        Case 10:WordPreSet      = "???????? ??????????: ????????????????"
            ParagraphPreSet = "???????? ????????????: ????????????????"
        Case 11:WordPreSet      = "???????? ??????????: ???????????????? (????????????????)"
            ParagraphPreSet = "???????? ????????????: ???????????????? (????????????????)"
        end select
        '-----------------------------------------------------------------------
    Case 31        'Case 31: dutch
        Select Case iLanguageCount
        Case 1: WordPreSet      = "Woord is Engels (VS)"
            ParagraphPreSet = "Alinea is Engels (VS)"
        Case 2: WordPreSet      = "Woord is Portugees (Portugal)"
            ParagraphPreSet = "Alinea is Portugees (Portugal)"
        Case 3: WordPreSet      = "Woord is Russisch"
            ParagraphPreSet = "Alinea is Russisch"
        Case 4: WordPreSet      = "Woord is Nederlands (NL)"
            ParagraphPreSet = "Alinea is Nederlands (NL)"
        Case 5: WordPreSet      = "Woord is Frans (Frankrijk)"
            ParagraphPreSet = "Alinea is Frans (Frankrijk)"
        Case 6: WordPreSet      = "Woord is Spaans (Spanje)"
            ParagraphPreSet = "Alinea is Spaans (Spanje)"
        Case 7: WordPreSet      = "Woord is Hongaars"
            ParagraphPreSet = "Alinea is Hongaars"
        Case 8: WordPreSet      = "Woord is Italiaans (Itali??)"
            ParagraphPreSet = "Alinea is Italiaans (Itali??)"
        Case 9: WordPreSet      = "Woord is Zweeds (Zweden)"
            ParagraphPreSet = "Alinea is Zweeds (Zweden)"
        Case 10:WordPreSet      = "Woord is Pools"
            ParagraphPreSet = "Alinea is Pools"
        Case 11:WordPreSet      = "Woord is Duits (Duitsland)"
            ParagraphPreSet = "Alinea is Duits (Duitsland)"
        end select
        '-----------------------------------------------------------------------
    Case 33        'Case 33: french
        Select Case iLanguageCount
        Case 1: WordPreSet      = "Le mot est en Anglais (U.S.A.)"
            ParagraphPreSet = "Le paragraphe est en Anglais (U.S.A.)"
        Case 2: WordPreSet      = "Le mot est en Portugais (Portugal)"
            ParagraphPreSet = "Le paragraphe est en Portugais (Portugal)"
        Case 3: WordPreSet      = "Le mot est en Russe"
            ParagraphPreSet = "Le paragraphe est en Russe"
        Case 4: WordPreSet      = "Le mot est en N??erlandais (Pays-Bas)"
            ParagraphPreSet = "Le paragraphe est en N??erlandais (Pays-Bas)"
        Case 5: WordPreSet      = "Le mot est en Fran??ais (France)"
            ParagraphPreSet = "Le paragraphe est en Fran??ais (France)"
        Case 6: WordPreSet      = "Le mot est en Espagnol (Espagne)"
            ParagraphPreSet = "Le paragraphe est en Espagnol (Espagne)"
        Case 7: WordPreSet      = "Le mot est en Hongrois"
            ParagraphPreSet = "Le paragraphe est en Hongrois"
        Case 8: WordPreSet      = "Le mot est en Italien (Italie)"
            ParagraphPreSet = "Le paragraphe est en Italien (Italie)"
        Case 9: WordPreSet      = "Le mot est en Su??dois (Su??de)"
            ParagraphPreSet = "Le paragraphe est en Su??dois (Su??de)"
        Case 10: WordPreSet     = "Le mot est en Polonais"
            ParagraphPreSet = "Le paragraphe est en Polonais"
        Case 11: WordPreSet     = "Le mot est en Allemand (Allemagne)"
            ParagraphPreSet = "Le paragraphe est en Allemand (Allemagne)"
        end select
        '-----------------------------------------------------------------------
    Case 34        'Case 34: spanish
        Select Case iLanguageCount
        Case 1: WordPreSet      = "La palabra est?? Ingl??s (Estados Unidos)"
            ParagraphPreSet = "El p??rrafo es  Ingl??s (Estados Unidos)"
        Case 2: WordPreSet      = "La palabra est?? Espa??ol (Espa??a)"
            ParagraphPreSet = "El p??rrafo es  Portugu??s (Portugal)"
        Case 3: WordPreSet      = "La palabra est?? Ruso"
            ParagraphPreSet = "El p??rrafo es  Ruso"
        Case 4: WordPreSet      = "La palabra est?? Holand??s (Pa??ses Bajos)"
            ParagraphPreSet = "El p??rrafo es  Holand??s (Pa??ses Bajos)"
        Case 5: WordPreSet      = "La palabra est?? Franc??s (Francia)"
            ParagraphPreSet = "El p??rrafo es  Franc??s (Francia)"
        Case 6: WordPreSet      = "La palabra est?? Espa??ol (Espa??a)"
            ParagraphPreSet = "El p??rrafo es  Espa??ol (Espa??a)"
        Case 7: WordPreSet      = "La palabra est?? H??ngaro"
            ParagraphPreSet = "El p??rrafo es  H??ngaro"
        Case 8: WordPreSet      = "La palabra est?? Italiano (Italia)"
            ParagraphPreSet = "El p??rrafo es  Italiano (Italia)"
        Case 9: WordPreSet      = "La palabra est?? Sueco (Suecia)"
            ParagraphPreSet = "El p??rrafo es  Sueco (Suecia)"
        Case 10:WordPreSet     = "La palabra est?? Polaco"
            ParagraphPreSet = "El p??rrafo es  Polaco"
        Case 11:WordPreSet     = "La palabra est?? Alem??n (Alemania)"
            ParagraphPreSet = "El p??rrafo es  Alem??n (Alemania)"
        end select
        '-----------------------------------------------------------------------
    Case 36        'Case 36: hungarian
        Select Case iLanguageCount
        Case 1: WordPreSet      = "A sz??: Angol (USA)"
            ParagraphPreSet = "Bekezd??s: Angol (USA)"
        Case 2: WordPreSet      = "A sz??: Portug??l (Portug??lia)"
            ParagraphPreSet = "Bekezd??s: Portug??l (Portug??lia)"
        Case 3: WordPreSet      = "A sz??: Orosz"
            ParagraphPreSet = "Bekezd??s: Orosz"
        Case 4: WordPreSet      = "A sz??: Holland (Hollandia)"
            ParagraphPreSet = "Bekezd??s: Holland (Hollandia)"
        Case 5: WordPreSet      = "A sz??: Francia (Franciaorsz??g)"
            ParagraphPreSet = "Bekezd??s: Francia (Franciaorsz??g)"
        Case 6: WordPreSet      = "A sz??: Spanyol (Spanyolorsz??g)"
            ParagraphPreSet = "Bekezd??s: Spanyol (Spanyolorsz??g)"
        Case 7: WordPreSet      = "A sz??: Magyar"
            ParagraphPreSet = "Bekezd??s: Magyar"
        Case 8: WordPreSet      = "A sz??: Olasz (Olaszorsz??g)"
            ParagraphPreSet = "Bekezd??s: Olasz (Olaszorsz??g)"
        Case 9: WordPreSet      = "A sz??: Sv??d (Sv??dorsz??g)"
            ParagraphPreSet = "Bekezd??s: Sv??d (Sv??dorsz??g)"
        Case 10:WordPreSet      = "A sz??: Lengyel"
            ParagraphPreSet = "Bekezd??s: Lengyel"
        Case 11:WordPreSet      = "A sz??: N??met (N??metorsz??g)"
            ParagraphPreSet = "Bekezd??s: N??met (N??metorsz??g)"
        end select
        '-----------------------------------------------------------------------
    Case 39        'Case 39: italian
        Select Case iLanguageCount
        Case 1: WordPreSet      = "La parola ?? Inglese (USA)"
            ParagraphPreSet = "Il paragrafo ?? Inglese (USA)"
        Case 2: WordPreSet      = "La parola ?? Portoghese (Portogallo)"
            ParagraphPreSet = "Il paragrafo ?? Portoghese (Portogallo)"
        Case 3: WordPreSet      = "La parola ?? Russo"
            ParagraphPreSet = "Il paragrafo ?? Russo"
        Case 4: WordPreSet      = "La parola ?? Olandese (Paesi Bassi)"
            ParagraphPreSet = "Il paragrafo ?? Olandese (Paesi Bassi)"
        Case 5: WordPreSet      = "La parola ?? Francese (Francia)"
            ParagraphPreSet = "Il paragrafo ?? Francese (Francia)"
        Case 6: WordPreSet      = "La parola ?? Spagnolo (Spagna)"
            ParagraphPreSet = "Il paragrafo ?? Spagnolo (Spagna)"
        Case 7: WordPreSet      = "La parola ?? Ungherese"
            ParagraphPreSet = "Il paragrafo ?? Ungherese"
        Case 8: WordPreSet      = "La parola ?? Italiano (Italia)"
            ParagraphPreSet = "Il paragrafo ?? Italiano (Italia)"
        Case 9: WordPreSet      = "La parola ?? Svedese (Svezia)"
            ParagraphPreSet = "Il paragrafo ?? Svedese (Svezia)"
        Case 10: WordPreSet     = "La parola ?? Polacco"
            ParagraphPreSet = "Il paragrafo ?? Polacco"
        Case 11: WordPreSet     = "La parola ?? Tedesco (Germania)"
            ParagraphPreSet = "Il paragrafo ?? Tedesco (Germania)"
        end select
        '-----------------------------------------------------------------------
    Case 46        'Case 46: swedish
        Select Case iLanguageCount
        Case 1: WordPreSet      = "Ordet ??r  Engelska (USA)"
            ParagraphPreSet = "Stycket ??r  Engelska (USA)"
        Case 2: WordPreSet      = "Ordet ??r  Portugisiska (Portugal)"
            ParagraphPreSet = "Stycket ??r  Portugisiska (Portugal)"
        Case 3: WordPreSet      = "Ordet ??r  Ryska"
            ParagraphPreSet = "Stycket ??r  Ryska"
        Case 4: WordPreSet      = "Ordet ??r  Svenska (Sverige)"
            ParagraphPreSet = "Stycket ??r  Holl??ndska (Nederl??nderna)"
        Case 5: WordPreSet      = "Ordet ??r  Franska (Frankrike)"
            ParagraphPreSet = "Stycket ??r  Franska (Frankrike)"
        Case 6: WordPreSet      = "Ordet ??r  Spanska (Spanien)"
            ParagraphPreSet = "Stycket ??r  Spanska (Spanien)"
        Case 7: WordPreSet      = "Ordet ??r  Ungerska"
            ParagraphPreSet = "Stycket ??r  Ungerska"
        Case 8: WordPreSet      = "Ordet ??r  Italienska (Italien)"
            ParagraphPreSet = "Stycket ??r  Italienska (Italien)"
        Case 9: WordPreSet      = "Ordet ??r  Svenska (Sverige)"
            ParagraphPreSet = "Stycket ??r  Svenska (Sverige)"
        Case 10:WordPreSet      = "Ordet ??r  Polska"
            ParagraphPreSet = "Stycket ??r  Polska"
        Case 11:WordPreSet      = "Ordet ??r  Tyska (Tyskland)"
            ParagraphPreSet = "Stycket ??r  Tyska (Tyskland)"
        end select
        '-----------------------------------------------------------------------
    Case 48        'Case 48: polish
        Select Case iLanguageCount
        Case 1: WordPreSet      = "Wyraz jest Angielski (USA)"
            ParagraphPreSet = "Akapit jest Angielski (USA)"
        Case 2: WordPreSet      = "Wyraz jest Portugalski (Portugalia)"
            ParagraphPreSet = "Akapit jest Portugalski (Portugalia)"
        Case 3: WordPreSet      = "Wyraz jest Rosyjski"
            ParagraphPreSet = "Akapit jest Rosyjski"
        Case 4: WordPreSet      = "Wyraz jest Holenderski (Holandia)"
            ParagraphPreSet = "Akapit jest Holenderski (Holandia)"
        Case 5: WordPreSet      = "Wyraz jest Francuski (Francja)"
            ParagraphPreSet = "Akapit jest Francuski (Francja)"
        Case 6: WordPreSet      = "Wyraz jest Hiszpa??ski (Hiszpania)"
            ParagraphPreSet = "Akapit jest Hiszpa??ski (Hiszpania)"
        Case 7: WordPreSet      = "Wyraz jest W??gierski"
            ParagraphPreSet = "Akapit jest W??gierski"
        Case 8: WordPreSet      = "Wyraz jest W??oski (W??ochy)"
            ParagraphPreSet = "Akapit jest W??oski (W??ochy)"
        Case 9: WordPreSet      = "Wyraz jest Szwedzki (Szwecja)"
            ParagraphPreSet = "Akapit jest Szwedzki (Szwecja)"
        Case 10:WordPreSet      = "Wyraz jest Polski"
            ParagraphPreSet = "Akapit jest Polski"
        Case 11:WordPreSet      = "Wyraz jest Niemiecki (Niemcy)"
            ParagraphPreSet = "Akapit jest Niemiecki (Niemcy)"
        end select
        '-----------------------------------------------------------------------
    Case 49        'Case 49: german
        Select Case iLanguageCount
        Case 1: WordPreSet      = "Wort ist Englisch (USA)"
            ParagraphPreSet = "Absatz ist Englisch (USA)"
        Case 2: WordPreSet      = "Wort ist Portugiesisch (Portugal)"
            ParagraphPreSet = "Absatz ist Portugiesisch (Portugal)"
        Case 3: WordPreSet      = "Wort ist Russisch"
            ParagraphPreSet = "Absatz ist Russisch"
        Case 4: WordPreSet      = "Wort ist Niederl??ndisch (Niederlande)"
            ParagraphPreSet = "Absatz ist Niederl??ndisch (Niederlande)"
        Case 5: WordPreSet      = "Wort ist Franz??sisch (Frankreich)"
            ParagraphPreSet = "Absatz ist Franz??sisch (Frankreich)"
        Case 6: WordPreSet      = "Wort ist Spanisch (Spanien)"
            ParagraphPreSet = "Absatz ist Spanisch (Spanien)"
        Case 7: WordPreSet      = "Wort ist Ungarisch"
            ParagraphPreSet = "Absatz ist Ungarisch"
        Case 8: WordPreSet      = "Wort ist Italienisch (Italien)"
            ParagraphPreSet = "Absatz ist Italienisch (Italien)"
        Case 9: WordPreSet      = "Wort ist Schwedisch (Schweden)"
            ParagraphPreSet = "Absatz ist Schwedisch (Schweden)"
        Case 10:WordPreSet      = "Wort ist Polnisch"
            ParagraphPreSet = "Absatz ist Polnisch"
        Case 11:WordPreSet      = "Wort ist Deutsch (Deutschland)"
            ParagraphPreSet = "Absatz ist Deutsch (Deutschland)"
        end select
        '-----------------------------------------------------------------------
    Case 50        'Case 50: slovenian
       Select Case iLanguageCount
       Case 1: WordPreSet      = "Jezik besede je angle??ki (ZDA)"
           ParagraphPreSet = "Jezik odstavka je angle??ki (ZDA)"
       Case 2: WordPreSet      = "Jezik besede je portugalski (Portugalska)"
           ParagraphPreSet = "Jezik odstavka je portugalski (Portugalska)"
       Case 3: WordPreSet      = "Jezik besede je ruski"
           ParagraphPreSet = "Jezik odstavka je ruski"
       Case 4: WordPreSet      = "Jezik besede je nizozemski (Nizozemska)"
           ParagraphPreSet = "Jezik odstavka je nizozemski (Nizozemska)"
       Case 5: WordPreSet      = "Jezik besede je francoski (Francija)"
           ParagraphPreSet = "Jezik odstavka je francoski (Francija)"
       Case 6: WordPreSet      = "Jezik besede je ??panski (??panija)"
           ParagraphPreSet = "Jezik odstavka je ??panski (??panija)"
       Case 7: WordPreSet      = "Jezik besede je mad??arski"
           ParagraphPreSet = "Jezik odstavka je mad??arski"
       Case 8: WordPreSet      = "Jezik besede je italijanski (Italija)"
           ParagraphPreSet = "Jezik odstavka je italijanski (Italija)"
       Case 9: WordPreSet      = "Jezik besede je ??vedski (??vedska)"
           ParagraphPreSet = "Jezik odstavka je ??vedski (??vedska)"
       Case 10:WordPreSet      = "Jezik besede je poljski"
           ParagraphPreSet = "Jezik odstavka je poljski"
       Case 11:WordPreSet      = "Jezik besede je nem??ki (Nem??ija)"
           ParagraphPreSet = "Jezik odstavka je nem??ki (Nem??ija)"
       end select
       '-----------------------------------------------------------------------
    Case 55        'Case 55: Portuguese (Brazil)
        Select Case iLanguageCount
        Case 1: WordPreSet      = "a palavra ?? Ingl??s (EUA)"
            ParagraphPreSet = "O par??grafo ?? Ingl??s (EUA)"
        Case 2: WordPreSet      = "a palavra ?? Portugu??s (Brasil)"
            ParagraphPreSet = "O par??grafo ?? Portugu??s (Portugal)"
        Case 3: WordPreSet  	= "a palavra ?? Russo"
            ParagraphPreSet = "O par??grafo ?? Russo"
        Case 4: WordPreSet      = "a palavra ?? Holand??s (Holanda)"
            ParagraphPreSet = "O par??grafo ?? Holand??s (Holanda)"
        Case 5: WordPreSet      = "a palavra ?? Franc??s (Fran??a)"
            ParagraphPreSet = "O par??grafo ?? Franc??s (Fran??a)"
        Case 6: WordPreSet      = "a palavra ?? Portugu??s (Brasil)"
            ParagraphPreSet = "O par??grafo ?? Espanhol (Espanha)"
        Case 7: WordPreSet      = "a palavra ?? H??ngaro"
            ParagraphPreSet = "O par??grafo ?? H??ngaro"
        Case 8: WordPreSet      = "a palavra ?? Italiano (It??lia)"
            ParagraphPreSet = "O par??grafo ?? Italiano (It??lia)"
        Case 9: WordPreSet      = "a palavra ?? Sueco (Su??cia)"
            ParagraphPreSet = "O par??grafo ?? Sueco (Su??cia)"
        Case 10:WordPreSet      = "a palavra ?? Polon??s"
            ParagraphPreSet = "O par??grafo ?? Polon??s"
        Case 11:WordPreSet      = "a palavra ?? Alem??o (Alemanha)"
            ParagraphPreSet = "O par??grafo ?? Alem??o (Alemanha)"
        end select
        '-----------------------------------------------------------------------
    case else
        'if Office language is not already covered: warning appears.
        Warnlog "Language has to be added to testcase. Please see w_locale_strings2.inc for further details"
        QAErrorlog "Please add " & iSprache & " to file!"
        wGetLanguageGuessString = ""
    end select
    '-----------------------------------------------------------------------
    'distinguishing if string for word or string for paragraph is handed over
    if sValue = "WordPreSet" then
        wGetLanguageGuessString = WordPreSet
    elseif sValue = "ParagraphPreSet" then
        wGetLanguageGuessString = ParagraphPreSet
    end if

end function
