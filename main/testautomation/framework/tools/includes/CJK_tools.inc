'encoding UTF-8  Do not remove or change this line!
'**************************************************************
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
'**************************************************************
'*
'* short description : Tools for CJK feature test in Writer
'*
'\***********************************************************************

function CheckAsianLanguageSupport( sSupport as String )  as String

    ToolsOptions
    Call hToolsOptions("LANGUAGESETTINGS","LANGUAGES")

    if ( aktivieren.exists() ) then
        if ( aktivieren.isEnabled() ) then
            if ( lcase( sSupport ) = "on" ) then
                printlog( "Enabling Asian Language Support" )
                Aktivieren.Check
            else
                printlog( "Disabling Asian Language Support" )
                Aktivieren.uncheck()
            endif
        else
            warnlog( "Activate Asian Language Support checkbox is disabled" )
        endif
    else
        warnlog( "Activate Asian Language Support checkbox is missing" )
    endif
    
    Kontext "ExtrasOptionenDlg"
    ExtrasOptionenDlg.OK()
    
end function

'******************************************************************************'

function fStartupNavigator(navigatorItem as String , subItemNum as Integer)
    Dim j as Integer
    
    Kontext "Navigator"
    if NOT Navigator.Exists then
        ' If you don' t ask for the Navigator and it's open it would be clodes and test fails !
        ViewNavigator
    end if
    Kontext "NavigatorWriter"
    if Auswahlliste.GetItemCount < 11 then
        Inhaltsansicht.Click
    end if
    if Auswahlliste.GetItemCount > 11 then
        For j= 1 to 1
            Auswahlliste.Select j
            Auswahlliste.TypeKeys "-"
        next j
    end if
    Kontext "NavigatorWriter"
    Auswahlliste.TypeKeys "<Up>", 11
    sleep 1
    Select case navigatorItem
    case "Headings"        : goto GoON
    case "Tables"          : Auswahlliste.TypeKeys "<down>"
    case "TextFrame"       : Auswahlliste.TypeKeys "<down>" , 2
    case "Graphics"        : Auswahlliste.TypeKeys "<down>" , 3
    case "OLEObject"       : Auswahlliste.TypeKeys "<down>" , 4
    case "Bookmarks"       : Auswahlliste.TypeKeys "<down>" , 5
    case "Section"         : Auswahlliste.TypeKeys "<down>" , 6
    case "Hyperlinks"      : Auswahlliste.TypeKeys "<down>" , 7
    case "References"      : Auswahlliste.TypeKeys "<down>" , 8
    case "Indexes"         : Auswahlliste.TypeKeys "<down>" , 9
    case "Notes"           : Auswahlliste.TypeKeys "<down>" , 10
    case "DrawObjects"     : Auswahlliste.TypeKeys "<down>" , 11
    end Select
    sleep 1
    GoON:
    Auswahlliste.TypeKeys "<return>"
    sleep 1
    Toolbox.Click Inhaltsansicht
    sleep 1
    Auswahlliste.TypeKeys "<Up>",subItemNum
    sleep 1
end function

'******************************************************************************'

function fGetCountryName( CountryID as Integer ) as String
    
    select case iSprache
    case 01   :        ' English (USA)
        select case CountryID
        case 1:  fGetCountryName = "English (USA)"
        case 33: fGetCountryName = "French (France)"
        case 34: fGetCountryName = "Spanish (Spain)"
        case 39: fGetCountryName = "Italian (Italy)"
        case 46: fGetCountryName = "Swedish (Sweden)"
        case 49: fGetCountryName = "German (Germany)"
        case 55: fGetCountryName = "Portuguese (Brazil)"
        case 81: fGetCountryName = "Japanese"
        case 82: fGetCountryName = "Korean (RoK)"
        case 86: fGetCountryName = "Chinese (simplified)"
        case 88: fGetCountryName = "Chinese (traditional)"
        case else :
            QAErrorLog "Now, the test does not support for the language " +iSprache
            fGetCountryName = ""
        end select
    case 33   :        ' France
        select case CountryID
        case 1:  fGetCountryName = "Anglais (U.S.A.)"
        case 33: fGetCountryName = "Fran??ais (France)"
        case 34: fGetCountryName = "Espagnol (Espagne)"
        case 39: fGetCountryName = "Italien (Italie)"
        case 46: fGetCountryName = "Su??dois (Su??de)"
        case 49: fGetCountryName = "Allemand (Allemagne)"
        case 55: fGetCountryName = "Portugais (Br??sil)"
        case 81: fGetCountryName = "Japonais"
        case 82: fGetCountryName = "Cor??en"
        case 86: fGetCountryName = "Chinois (simple)"
        case 88: fGetCountryName = "Chinois (traditionnel)"
        case else :
            QAErrorLog "Now, the test does not support for the language " +iSprache
            fGetCountryName = ""
        end select
    case 34   :        ' Spanish
        select case CountryID
        case 1:  fGetCountryName = "Ingl??s (EE.UU.)"
        case 33: fGetCountryName = "Franc??s (Francia)"
        case 34: fGetCountryName = "Espa??ol (Espa??a)"
        case 39: fGetCountryName = "Italiano (Italia)"
        case 46: fGetCountryName = "Sueco (Suecia)"
        case 49: fGetCountryName = "Alem??n (Alemania)"
        case 55: fGetCountryName = "Portugu??s (Brasil)"
        case 81: fGetCountryName = "Japon??s"
        case 82: fGetCountryName = "Coreano"
        case 86: fGetCountryName = "Chino (simple)"
        case 88: fGetCountryName = "Chino (tradicional)"
        case else :
            QAErrorLog "Now, the test does not support for the language " +iSprache
            fGetCountryName = ""
        end select
    case 39   :        ' Italy
        select case CountryID
        case 1:  fGetCountryName = "Inglese (US)"
        case 33: fGetCountryName = "Francese (Francia)"
        case 34: fGetCountryName = "Spagnolo (Spagna)"
        case 39: fGetCountryName = "Italiano (Italia)"
        case 46: fGetCountryName = "Svedese (Svezia)"
        case 49: fGetCountryName = "Tedesco (Germania)"
        case 55: fGetCountryName = "Portoghese (Brasile)"
        case 81: fGetCountryName = "Giapponese"
        case 82: fGetCountryName = "Coreano"
        case 86: fGetCountryName = "Cinese (semplificato)"
        case 88: fGetCountryName = "Cinese (tradizionale)"
        case else :
            QAErrorLog "Now, the test does not support for the language " +iSprache
            fGetCountryName = ""
        end select
    case 46   :        ' Swedish
        select case CountryID
        case 1:  fGetCountryName = "engelska"
        case 33: fGetCountryName = "franska (Frankrike)"
        case 34: fGetCountryName = "spanska (Spanien)"
        case 39: fGetCountryName = "italienska (Italien)"
        case 46: fGetCountryName = "svenska (Sverige)"
        case 49: fGetCountryName = "tyska (Tyskland)"
        case 55: fGetCountryName = "portugisiska (Brasilien)"
        case 81: fGetCountryName = "Japanska"
        case 82: fGetCountryName = "koreanska"
        case 86: fGetCountryName = "kinesiska (enkel)"
        case 88: fGetCountryName = "kinesiska (trad.)"
        case else :
            QAErrorLog "Now, the test does not support for the language " +iSprache
            fGetCountryName = ""
        end select
    case 49   :        ' German
        select case CountryID
        case 1:  fGetCountryName = "Englisch (USA)"
        case 33: fGetCountryName = "Franz??sisch (Frankreich)"
        case 34: fGetCountryName = "Spanisch (Spanien)"
        case 39: fGetCountryName = "Italienisch (Italien)"
        case 46: fGetCountryName = "Schwedisch (Schweden)"
        case 49: fGetCountryName = "Deutsch (Deutschland)"
        case 55: fGetCountryName = "Portugiesisch (Brasilien)"
        case 81: fGetCountryName = "Japanisch"
        case 82: fGetCountryName = "Koreanisch (RoK)"
        case 86: fGetCountryName = "Chinesisch (einfach)"
        case 88: fGetCountryName = "Chinesisch (Trad.)"
        case else :
            QAErrorLog "Now, the test does not support for the language " +iSprache
            fGetCountryName = ""
        end select
    case 50   :        ' Slovenian
       select case CountryID
       case 1:  fGetCountryName = "angle??ki (ZDA)"
       case 33: fGetCountryName = "francoski (Francija)"
       case 34: fGetCountryName = "??panski (??panija)"
       case 39: fGetCountryName = "italijanski (Italija)"
       case 46: fGetCountryName = "??vedski (??vedska)"
       case 49: fGetCountryName = "nem??ki (Nem??ija)"
       case 55: fGetCountryName = "portugalski (Brazilija)"
       case 81: fGetCountryName = "japonski"
       case 82: fGetCountryName = "korejski (RK)"
       case 86: fGetCountryName = "kitajski (poenostavljeni)"
       case 88: fGetCountryName = "kitajski (tradicionalni)"
       case else :
           QAErrorLog "Now, the test does not support for the language " +iSprache
           fGetCountryName = ""
       end select
    case 55   :        ' Portuguese
        select case CountryID
        case 1:  fGetCountryName = "Ingl??s (EUA)"
        case 33: fGetCountryName = "Franc??s (Fran??a)"
        case 34: fGetCountryName = "Espanhol (Espanha)"
        case 39: fGetCountryName = "Italiano (It??lia)"
        case 46: fGetCountryName = "Sueco (Su??cia)"
        case 49: fGetCountryName = "Alem??o (Alemanha)"
        case 55: fGetCountryName = "Portugu??s (Brasil)"
        case 81: fGetCountryName = "Japon??s"
        case 82: fGetCountryName = "Coreano (RoK)"
        case 86: fGetCountryName = "Chin??s (simplificado)"
        case 88: fGetCountryName = "Chin??s (tradicional)"
        case else :
            QAErrorLog "Now, the test does not support for the language " +iSprache
            fGetCountryName = ""
        end select
    case 81   :        ' Japanese
        select case CountryID
        case 1:  fGetCountryName = "??????(??????)"
        case 33: fGetCountryName = "???????????????(????????????)"
        case 34: fGetCountryName = "???????????????(????????????)"
        case 39: fGetCountryName = "???????????????(????????????)"
        case 46: fGetCountryName = "?????????????????????(??????????????????)"
        case 49: fGetCountryName = "????????????(?????????)"
        case 55: fGetCountryName = "??????????????????(????????????)"
        case 81: fGetCountryName = "?????????"
        case 82: fGetCountryName = "?????????"
        case 86: fGetCountryName = "?????????(?????????)"
        case 88: fGetCountryName = "?????????(?????????)"
        case else :
            QAErrorLog "Now, the test does not support for the language " +iSprache
            fGetCountryName = ""
        end select
    case 82   :        ' Korean
        select case CountryID
        case 1:  fGetCountryName = "??????(??????)"
        case 33: fGetCountryName = "????????????(?????????)"
        case 34: fGetCountryName = "????????????(?????????)"
        case 39: fGetCountryName = "??????????????? (?????????)"
        case 46: fGetCountryName = "????????????(?????????)"
        case 49: fGetCountryName = "?????????(??????)"
        case 55: fGetCountryName = "???????????????(?????????)"
        case 81: fGetCountryName = "?????????"
        case 82: fGetCountryName = "?????????"
        case 86: fGetCountryName = "?????????(??????)"
        case 88: fGetCountryName = "?????????(??????)"
        case else :
            QAErrorLog "Now, the test does not support for the language " +iSprache
            fGetCountryName = ""
        end select
    case 86   :        ' Chinese (simplified)
        select case CountryID
        case 1:  fGetCountryName = "??????(??????)"
        case 33: fGetCountryName = "??????(??????)"
        case 34: fGetCountryName = "????????????(?????????)"
        case 39: fGetCountryName = "????????????(?????????)"
        case 46: fGetCountryName = "?????????(??????)"
        case 49: fGetCountryName = "??????(??????)"
        case 55: fGetCountryName = "????????????(??????)"
        case 81: fGetCountryName = "??????"
        case 82: fGetCountryName = "?????????"
        case 86: fGetCountryName = "??????(?????????)"
        case 88: fGetCountryName = "??????(?????????)"
        case else :
            QAErrorLog "Now, the test does not support for the language " +iSprache
            fGetCountryName = ""
        end select
        
    case 88   :        ' Chinese (traditional)
        select case CountryID
        case 1:  fGetCountryName = "??????(??????)"
        case 33: fGetCountryName = "??????(??????)"
        case 34: fGetCountryName = "????????????(?????????)"
        case 39: fGetCountryName = "????????????(?????????)"
        case 46: fGetCountryName = "?????????(??????)"
        case 49: fGetCountryName = "??????(??????)"
        case 55: fGetCountryName = "????????????(??????)"
        case 81: fGetCountryName = "??????"
        case 82: fGetCountryName = "??????"
        case 86: fGetCountryName = "??????(?????????)"
        case 88: fGetCountryName = "??????(??????)"
        case else :
            QAErrorLog "Now, the test does not support for the language " +iSprache
            fGetCountryName = ""
        end select
    case else :        ' Fallback
        QAErrorLog "Now, the test does not support for the language " +iSprache
        fGetCountryName = ""
    end select
    
end function



