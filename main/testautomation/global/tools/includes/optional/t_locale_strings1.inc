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
'* short description : defining locale dependant strings 
'*
'\***********************************************************************

function fLocaleString (sReturn as string) as string

'///The function fLocaleString should be used to concentrate all locale dependant strings
'///+ in one file in order to minimize the workload for adapting a new language
'///Here is a way how to get these strings out of OOo.
'/// - "LocaleTableHeading"       : run testscript qa\qatesttool\writer\tools\w_get_locale_strings.bas
'/// - "LocaleTableContents"      : run testscript qa\qatesttool\writer\tools\w_get_locale_strings.bas
'/// - "LocaleNumber"             : run testscript qa\qatesttool\writer\tools\w_get_locale_strings.bas
'/// - "LocaleText"               : run testscript qa\qatesttool\writer\tools\w_get_locale_strings.bas
'/// - "LocaleCurrency"           : run testscript qa\qatesttool\writer\tools\w_get_locale_strings.bas
'/// - "LocaleDate"               : run testscript qa\qatesttool\writer\tools\w_get_locale_strings.bas
'/// - "LocaleTime"               : run testscript qa\qatesttool\writer\tools\w_get_locale_strings.bas
'/// - "LocalePercent"            : run testscript qa\qatesttool\writer\tools\w_get_locale_strings.bas
'/// - "LocaleScientific"         : run testscript qa\qatesttool\writer\tools\w_get_locale_strings.bas
'/// - "LocaleFraction"           : run testscript qa\qatesttool\writer\tools\w_get_locale_strings.bas
'/// - "LocaleBoolean"            : run testscript qa\qatesttool\writer\tools\w_get_locale_strings.bas
'/// - "LocaleTable"              : run testscript qa\qatesttool\writer\tools\w_get_locale_strings.bas
'/// - "LocaleCurrencyValue"      : enter 10 in a cell and format to currency
'/// - "LocaleDateValue"          : a valid ( for this locale) date format
'/// - "LocaleDateOutput"         : enter a valid date in a cell
'/// - "LocaleTimeInput"          : a valid timecode (e.g. 15:42)
'/// - "LocaleTimeValue"          : enter 15:42 in a cell
'/// - "LocalePercentValue"	      : enter 14% in a cell
'/// - "LocaleScientificValue"	  : enter 1e+008 in a cell
'/// - "LocaleBooleanValue"       : enter 1 in a cell and format to boolean value
'/// - "LocaleLocaleSettings"     : TOOLS-OPTIONS-LANGUAGE SETTINGS-Language
'/// - "LocaleScriptType"         : possible script types are "Western", "CJK" and "CTL"

    Dim sLocaleTableHeading as string
    Dim sLocaleTableContents as string
    Dim sLocaleNumber as string
    Dim sLocaleText as string
    Dim sLocaleCurrency as string
    Dim sLocaleDate as string
    Dim sLocaleTime as string
    Dim sLocalePercent as string
    Dim sLocaleScientific as string
    Dim sLocaleFraction as string
    Dim sLocaleBoolean as string
    Dim sLocaleTable as string
    Dim sLocaleCurrencyValue as string
    Dim sLocaleDateValue as string
    Dim sLocaleDateOutput as string
    Dim sLocaleTimeInput as string
    Dim sLocaleTimeValue as string
    Dim slocalePercentValue as string
    Dim sLocaleScientificValue as string
    Dim sLocaleBooleanValue as string
    Dim sLocaleLocaleSettings as string
    Dim sLocaleScriptType as string
    Dim sLocaleNumFormLanEng as string
    Dim sLocaleNumFormLanLith as string
    Dim sLocaleNumFormLanDutch as string
    
    select case iSprache
          case 01   :  sLocaleTableHeading      = "Table Heading"      ' English (USA)
                       sLocaleTableContents     = "Table Contents"
                       sLocaleNumber            = "Number"
                       sLocaleText              = "Text"
                       sLocaleCurrency          = "Currency"
                       sLocaleDate              = "Date"
                       sLocaleTime              = "Time"
                       sLocalePercent           = "Percent"
                       sLocaleScientific        = "Scientific"
                       sLocaleFraction          = "Fraction"
                       sLocaleBoolean           = "Boolean Value"
                       sLocaleTable             = "Table"
                       sLocaleCurrencyValue     = "$10.00"
                       sLocaleDateValue         = "03/31/06"
                       sLocaleDateOutput	    = "03/31/06"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "03:42:00 PM"
                       slocalePercentValue      = "14.00%"
                       sLocaleScientificValue   = "1.00E+008"
                       sLocaleBooleanValue      = "TRUE"
                       sLocaleLocaleSettings    = "English (USA)"
                       sLocaleScriptType        = "Western"
                       sLocaleNumFormLanEng     = "English (USA)"
                       sLocaleNumFormLanLith    = "Lithuanian"
                       sLocaleNumFormLanDutch   = "Dutch (Netherlands)"
                       
          case 03   :  sLocaleTableHeading      = "Cabe??alho da tabela"      ' Portuguese
                       sLocaleTableContents     = "Conte??do da tabela"
                       sLocaleNumber            = "N??mero"
                       sLocaleText              = "Texto"
                       sLocaleCurrency          = "Moeda"
                       sLocaleDate              = "Data"
                       sLocaleTime              = "Hora"
                       sLocalePercent           = "Percentagem"
                       sLocaleScientific        = "Cient??fico"
                       sLocaleFraction          = "Frac????o"
                       sLocaleBoolean           = "Valor logico"
                       sLocaleTable             = "Tabela"
                       sLocaleCurrencyValue     = "10,00 ???"
                       sLocaleDateValue         = "31-03-06"
                       sLocaleDateOutput	    = "31-03-06"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15:42:00"
                       slocalePercentValue	    = "14,00%"
                       sLocaleScientificValue   = "1,00E+008"
                       sLocaleBooleanValue      = "VERDADEIRO"
                       sLocaleLocaleSettings    = "Portugu??s (Portugal)"
                       sLocaleScriptType        = "Western"
                       sLocaleNumFormLanEng     = "Ingl??s (EUA)"
                       sLocaleNumFormLanLith    = "Lituano"
                       sLocaleNumFormLanDutch   = "Flamengo (Holanda)"
                       
          case 07   :  sLocaleTableHeading      = "?????????????????? ??????????????"      ' Russian
                       sLocaleTableContents     = "???????????????????? ??????????????"
                       sLocaleNumber            = "??????????"
                       sLocaleText              = "??????????"
                       sLocaleCurrency          = "????????????"
                       sLocaleDate              = "????????"
                       sLocaleTime              = "T??????????"
                       sLocalePercent           = "??????????????"
                       sLocaleScientific        = "??????????"
                       sLocaleFraction          = "??????????"
                       sLocaleBoolean           = "???????????????????? ????????????????"
                       sLocaleTable             = "??????????????"
                       sLocaleCurrencyValue     = "10,00??????."
                       sLocaleDateValue         = "31.03.06"
                       sLocaleDateOutput	    = "31.03.06"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15:42:00"
                       slocalePercentValue	    = "14,00%"
                       sLocaleScientificValue   = "1,00E+008"
                       sLocaleBooleanValue      = "????????????"
                       sLocaleLocaleSettings    = "??????????????"
                       sLocaleScriptType        = "Western"
                       sLocaleNumFormLanEng     = "???????????????????? (??????)"
                       sLocaleNumFormLanLith    = "??????????????????"
                       sLocaleNumFormLanDutch   = "?????????????????????? (????????????????????)"
                       
          case 31   :  sLocaleTableHeading      = "Tabelkop"      ' Dutch
                       sLocaleTableContents     = "Inhoud tabel"
                       sLocaleNumber            = "Getal"
                       sLocaleText              = "Tekst"
                       sLocaleCurrency          = "Valuta"
                       sLocaleDate              = "Datum"
                       sLocaleTime              = "Tijd"
                       sLocalePercent           = "Procent"
                       sLocaleScientific        = "Wetenschappelijk"
                       sLocaleFraction          = "Breuk"
                       sLocaleBoolean           = "Logische waarde"
                       sLocaleTable             = "Tabel"
                       sLocaleCurrencyValue     = "??? 10,00"
                       sLocaleDateValue         = "31-03-06"
                       sLocaleDateOutput	    = "31-03-06"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15:42:00"
                       slocalePercentValue	    = "14,00%"
                       sLocaleScientificValue   = "1,00E+008"
                       sLocaleBooleanValue      = "WAAR"
                       sLocaleLocaleSettings    = "Nederlands (NL)"
                       sLocaleScriptType        = "Western"
                       sLocaleNumFormLanEng     = "Engels (VS)"
                       sLocaleNumFormLanLith    = "Litouws"
                       sLocaleNumFormLanDutch   = "Nederlands (NL)"
                       
          case 33   :  sLocaleTableHeading      = "Titre de tableau"      ' French
                       sLocaleTableContents     = "Contenu de tableau"
                       sLocaleNumber            = "Nombre"
                       sLocaleText              = "Texte"
                       sLocaleCurrency          = "Mon??taire"
                       sLocaleDate              = "Date"
                       sLocaleTime              = "Heure"
                       sLocalePercent           = "Pourcentage"
                       sLocaleScientific        = "Scientifique"
                       sLocaleFraction          = "Fraction"
                       sLocaleBoolean           = "Valeur logique"
                       sLocaleTable             = "Tableau"
                       sLocaleCurrencyValue     = "10,00 ???"
                       sLocaleDateValue         = "31/03/06"
                       sLocaleDateOutput	    = "31/03/06"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15:42:00"
                       slocalePercentValue	    = "14,00%"
                       sLocaleScientificValue   = "1,00E+008"
                       sLocaleBooleanValue      = "VRAI"
                       sLocaleLocaleSettings    = "Fran??ais (France)"
                       sLocaleScriptType        = "Western"
                       sLocaleNumFormLanEng     = "Anglais (U.S.A.)"
                       sLocaleNumFormLanLith    = "Lituanien"
                       sLocaleNumFormLanDutch   = "N??erlandais (Pays-Bas)"
                       
          case 34   :  sLocaleTableHeading      = "Encabezado de la tabla"      ' Spanish
                       sLocaleTableContents     = "Contenido de la tabla"
                       sLocaleNumber            = "N??mero"
                       sLocaleText              = "Texto"
                       sLocaleCurrency          = "Moneda"
                       sLocaleDate              = "Fecha"
                       sLocaleTime              = "Hora"
                       sLocalePercent           = "Porcentaje"
                       sLocaleScientific        = "Ciencia"
                       sLocaleFraction          = "Fracci??n"
                       sLocaleBoolean           = "Valor l??gico"
                       sLocaleTable             = "Tabla"
                       sLocaleCurrencyValue     = "10,00 ???"
                       sLocaleDateValue         = "31/03/06"
                       sLocaleDateOutput	    = "31/03/06"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15:42:00"
                       slocalePercentValue	    = "14,00%"
                       sLocaleScientificValue   = "1,00E+008"
                       sLocaleBooleanValue      = "VERDADERO"
                       sLocaleLocaleSettings    = "Espa??ol (Espa??a)"
                       sLocaleScriptType        = "Western"
                       sLocaleNumFormLanEng     = "Ingl??s (Estados Unidos)"
                       sLocaleNumFormLanLith    = "Lituano"
                       sLocaleNumFormLanDutch   = "Holand??s (Pa??ses Bajos)"
                       
          case 36   :  sLocaleTableHeading      = "T??bl??zatfejl??c"      ' Hungarian
                       sLocaleTableContents     = "T??bl??zattartalom"
                       sLocaleNumber            = "Sz??m"
                       sLocaleText              = "Sz??veg"
                       sLocaleCurrency          = "P??nznem"
                       sLocaleDate              = "D??tum"
                       sLocaleTime              = "Id??"
                       sLocalePercent           = "Sz??zal??k"
                       sLocaleScientific        = "Tudom??nyos"
                       sLocaleFraction          = "T??rt"
                       sLocaleBoolean           = "Logikai ??rt??k"
                       sLocaleTable             = "T??bl??zat"
                       sLocaleCurrencyValue     = "10,00 Ft"
                       sLocaleDateValue         = "06-03-31"
                       sLocaleDateOutput	    = "2006-03-31"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15:42:00"
                       slocalePercentValue	    = "14,00%"
                       sLocaleScientificValue   = "1,00E+008"
                       sLocaleBooleanValue      = "IGAZ"
                       sLocaleLocaleSettings    = "Magyar"
                       sLocaleScriptType        = "Western"
                       sLocaleNumFormLanEng     = "Angol (USA)"
                       sLocaleNumFormLanLith    = "Litv??n"
                       sLocaleNumFormLanDutch   = "Holland (Hollandia)"
          
          case 39   :  sLocaleTableHeading      = "Intestazione tabella"      ' Italian
                       sLocaleTableContents     = "Contenuto tabella"
                       sLocaleNumber            = "Numero"
                       sLocaleText              = "Testo"
                       sLocaleCurrency          = "Valuta"
                       sLocaleDate              = "Data"
                       sLocaleTime              = "Orario"
                       sLocalePercent           = "Percentuale"
                       sLocaleScientific        = "Scientifico"
                       sLocaleFraction          = "Frazione"
                       sLocaleBoolean           = "Valore booleano"
                       sLocaleTable             = "Tabella"
                       sLocaleCurrencyValue     = "??? 10,00"
                       sLocaleDateValue         = "31/03/06"
                       sLocaleDateOutput	    = "31/03/06"
                       sLocaleTimeInput         = "15.42"
                       sLocaleTimeValue         = "15.42.00"
                       slocalePercentValue	    = "14,00%"
                       sLocaleScientificValue   = "1,00E+008"
                       sLocaleBooleanValue      = "VERO"
                       sLocaleLocaleSettings    = "Italiano (Italia)"
                       sLocaleScriptType        = "Western"
                       sLocaleNumFormLanEng     = "Inglese (USA)"
                       sLocaleNumFormLanLith    = "Lituano"
                       sLocaleNumFormLanDutch   = "Olandese (Paesi Bassi)"
                       
          case 46   :  sLocaleTableHeading      = "Tabell??verskrift"      ' Swedish
                       sLocaleTableContents     = "Tabellinneh??ll"
                       sLocaleNumber            = "Tal"
                       sLocaleText              = "Text"
                       sLocaleCurrency          = "Valuta"
                       sLocaleDate              = "Datum"
                       sLocaleTime              = "Tid"
                       sLocalePercent           = "Procent"
                       sLocaleScientific        = "Vetenskap"
                       sLocaleFraction          = "Br??k"
                       sLocaleBoolean           = "Sannolikhet"
                       sLocaleTable             = "Tabell"
                       sLocaleCurrencyValue     = "10,00 kr"
                       sLocaleDateValue         = "06-03-31"
                       sLocaleDateOutput	    = "06-03-31"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15:42:00"
                       slocalePercentValue	    = "14,00%"
                       sLocaleScientificValue   = "1,00E+008"
                       sLocaleBooleanValue      = "SANT"
                       sLocaleLocaleSettings    = "Svenska (Sverige)"
                       sLocaleScriptType        = "Western"
                       sLocaleNumFormLanEng     = "Engelska (USA)"
                       sLocaleNumFormLanLith    = "Litauiska"
                       sLocaleNumFormLanDutch   = "Holl??ndska (Nederl??nderna)"
    
          case 48   :  sLocaleTableHeading      = "Nag????wek tabeli"      ' Polish
                       sLocaleTableContents     = "Zawarto???? tabeli"
                       sLocaleNumber            = "Liczba"
                       sLocaleText              = "Tekst"
                       sLocaleCurrency          = "Waluta"
                       sLocaleDate              = "Data"
                       sLocaleTime              = "Godzina"
                       sLocalePercent           = "Procent"
                       sLocaleScientific        = "Naukowy"
                       sLocaleFraction          = "U??amek"
                       sLocaleBoolean           = "Warto???? logiczna"
                       sLocaleTable             = "Tabela"
                       sLocaleCurrencyValue     = "10,00 z??"
                       sLocaleDateValue         = "2006-03-31"
                       sLocaleDateOutput	    = "2006-03-31"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15:42:00"
                       slocalePercentValue	    = "14,00%"
                       sLocaleScientificValue   = "1,00E+008"
                       sLocaleBooleanValue      = "PRAWDA"
                       sLocaleLocaleSettings    = "Polski"
                       sLocaleScriptType        = "Western"
                       sLocaleNumFormLanEng     = "Angielski (USA)"
                       sLocaleNumFormLanLith    = "Litewski"
                       sLocaleNumFormLanDutch   = "Holenderski (Holandia)"
                       
          case 49   :  sLocaleTableHeading      = "Tabellen ??berschrift"      ' German
                       sLocaleTableContents     = "Tabellen Inhalt"
                       sLocaleNumber            = "Zahl"
                       sLocaleText              = "Text"
                       sLocaleCurrency          = "W??hrung"
                       sLocaleDate              = "Datum"
                       sLocaleTime              = "Zeit"
                       sLocalePercent           = "Prozent"
                       sLocaleScientific        = "Wissenschaft"
                       sLocaleFraction          = "Bruch"
                       sLocaleBoolean           = "Wahrheitswert"
                       sLocaleTable             = "Tabelle"
                       sLocaleCurrencyValue     = "10,00 ???"
                       sLocaleDateValue         = "31.03.06"
                       sLocaleDateOutput	    = "31.03.06"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15:42:00"
                       slocalePercentValue	    = "14,00%"
                       sLocaleScientificValue   = "1,00E+008"
                       sLocaleBooleanValue      = "WAHR"
                       sLocaleLocaleSettings    = "Deutsch (Deutschland)"
                       sLocaleScriptType        = "Western"
                       sLocaleNumFormLanEng     = "Englisch (USA)"
                       sLocaleNumFormLanLith    = "Litauisch"
                       sLocaleNumFormLanDutch   = "Niederl??ndisch (Niederlande)"

        case 50     : sLocaleTableHeading      = "Glava tabele" ' Slovenian
                      sLocaleTableContents     = "Vsebina tabele"
                      sLocaleNumber            = "??tevilo"
                      sLocaleText              = "Besedilo"
                      sLocaleCurrency          = "Valuta"
                      sLocaleDate              = "Datum"
                      sLocaleTime              = "??as"
                      sLocalePercent           = "Odstotek"
                      sLocaleScientific        = "Znanstveno"
                      sLocaleFraction          = "Ulomek"
                      sLocaleBoolean           = "Dvoji??ka vrednost"
                      sLocaleTable             = "Tabela"
                      sLocaleCurrencyValue     = "10,00 ???"
                      sLocaleDateValue         = "31.03.06"
                      sLocaleDateOutput	    = "31.03.06"
                      sLocaleTimeInput         = "15:42"
                      sLocaleTimeValue         = "15:42:00"
                      slocalePercentValue	    = "14,00%"
                      sLocaleScientificValue   = "1,00E+008"
                      sLocaleBooleanValue      = "TRUE"
                      sLocaleLocaleSettings    = "angle??ki (ZDA)"
                      sLocaleScriptType        = "Zahodni"
                      sLocaleNumFormLanEng     = "angle??ki (ZDA)"
                      sLocaleNumFormLanLith    = "litovski"
                      sLocaleNumFormLanDutch   = "nizozemski (Nizozemska)"

          case 55   :  sLocaleTableHeading      = "T??tulo da tabela"      ' Brazil (Portuguese)
                       sLocaleTableContents     = "Conteudo da table"
                       sLocaleNumber            = "N??mero"
                       sLocaleText              = "Texto"
                       sLocaleCurrency          = "Moeda"
                       sLocaleDate              = "Data"
                       sLocaleTime              = "Hora"
                       sLocalePercent           = "Porcentagem"
                       sLocaleScientific        = "Cient??fico"
                       sLocaleFraction          = "Fra????o"
                       sLocaleBoolean           = "Valor booleano"
                       sLocaleTable             = "Tabela"
                       sLocaleCurrencyValue     = "R$ 10,00"
                       sLocaleDateValue         = "31/03/06"
                       sLocaleDateOutput	    = "31/03/06"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15:42:00"
                       slocalePercentValue	    = "14,00%"
                       sLocaleScientificValue   = "1,00E+008"
                       sLocaleBooleanValue      = "VERDADEIRO"
                       sLocaleLocaleSettings    = "Portugu??s (Brasil)"
                       sLocaleScriptType        = "Western"
                       sLocaleNumFormLanEng     = "Ingl??s (EUA)"
                       sLocaleNumFormLanLith    = "Lituano"
                       sLocaleNumFormLanDutch   = "Flamengo (Holanda)"
          
          case 81   :  sLocaleTableHeading      = "???????????????"                 ' Japanese
                       sLocaleTableContents     = "????????????"
                       sLocaleNumber            = "??????"
                       sLocaleText              = "????????????"
                       sLocaleCurrency          = "??????"
                       sLocaleDate              = "??????"
                       sLocaleTime              = "??????"
                       sLocalePercent           = "?????????????????????"
                       sLocaleScientific        = "??????"
                       sLocaleFraction          = "??????"
                       sLocaleBoolean           = "?????????"
                       sLocaleTable             = "???"
                       sLocaleCurrencyValue     = "???10"
                       sLocaleDateValue         = "3???31???"
                       sLocaleDateOutput	    = "3???31???"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15:42"
                       slocalePercentValue	    = "14%"
                       sLocaleScientificValue   = "1.00E+08"
                       sLocaleBooleanValue      = "TRUE"
                       sLocaleLocaleSettings    = "?????????"
                       sLocaleScriptType        = "CJK"
                       sLocaleNumFormLanEng     = "?????? (??????)"
                       sLocaleNumFormLanLith    = "??????????????????"
                       sLocaleNumFormLanDutch   = "??????????????? (????????????)"
          
          case 82   :  sLocaleTableHeading      = "?????????"      ' Korean
                       sLocaleTableContents     = "??? ??????"
                       sLocaleNumber            = "???"
                       sLocaleText              = "?????????"
                       sLocaleCurrency          = "??????"
                       sLocaleDate              = "??????"
                       sLocaleTime              = "??????"
                       sLocalePercent           = "?????????"
                       sLocaleScientific        = "??????"
                       sLocaleFraction          = "??????"
                       sLocaleBoolean           = "?????? ???"
                       sLocaleTable             = "???"
                       sLocaleCurrencyValue     = "???10"
                       sLocaleDateValue         = "2006/3/31"
                       sLocaleDateOutput	    = "2006??? 3??? 31"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15??? 42??? 0???"
                       slocalePercentValue	    = "14%"
                       sLocaleScientificValue   = "1.00E+08"
                       sLocaleBooleanValue      = "???"
                       sLocaleLocaleSettings    = "?????????(????????????)"
                       sLocaleScriptType        = "CJK"
                       sLocaleNumFormLanEng     = "??????(??????)"
                       sLocaleNumFormLanLith    = "??????????????????"
                       sLocaleNumFormLanDutch   = "???????????????(????????????)"
          
          case 86   :  sLocaleTableHeading      = "????????????"                  ' Chinese (simplified)
                       sLocaleTableContents     = "????????????"
                       sLocaleNumber            = "??????"
                       sLocaleText              = "??????"
                       sLocaleCurrency          = "??????"
                       sLocaleDate              = "??????"
                       sLocaleTime              = "??????"
                       sLocalePercent           = "?????????"
                       sLocaleScientific        = "??????"
                       sLocaleFraction          = "??????"
                       sLocaleBoolean           = "?????????"
                       sLocaleTable             = "??????"
                       sLocaleCurrencyValue     = "???10.00"
                       sLocaleDateValue         = "2006/3/31"
                       sLocaleDateOutput	    = "06???3???31???"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15:42:00"
                       slocalePercentValue	    = "14.00%"
                       sLocaleScientificValue   = "1.00E+008"
                       sLocaleBooleanValue      = "???"
                       sLocaleLocaleSettings    = "??????????????????"
                       sLocaleScriptType        = "CJK"
                       sLocaleNumFormLanEng     = "??????????????????"
                       sLocaleNumFormLanLith    = "????????????"
                       sLocaleNumFormLanDutch   = "?????????????????????"
          
          case 88   :  sLocaleTableHeading      = "????????????"      ' Chinese (traditional)
                       sLocaleTableContents     = "????????????"
                       sLocaleNumber            = "??????"
                       sLocaleText              = "??????"
                       sLocaleCurrency          = "??????"
                       sLocaleDate              = "??????"
                       sLocaleTime              = "??????"
                       sLocalePercent           = "?????????"
                       sLocaleScientific        = "??????"
                       sLocaleFraction          = "??????"
                       sLocaleBoolean           = "?????????"
                       sLocaleTable             = "??????"
                       sLocaleCurrencyValue     = "NT$10.00"
                       sLocaleDateValue         = "2006/3/31"
                       sLocaleDateOutput	    = "06/3/31"
                       sLocaleTimeInput         = "15:42"
                       sLocaleTimeValue         = "15:42:00"
                       slocalePercentValue	    = "14.00%"
                       sLocaleScientificValue   = "1.00E+008"
                       sLocaleBooleanValue      = "???"
                       sLocaleLocaleSettings    = "?????? (??????)"
                       sLocaleScriptType        = "CJK"
                       sLocaleNumFormLanEng     = "?????? (??????)"
                       sLocaleNumFormLanLith    = "????????????"
                       sLocaleNumFormLanDutch   = "????????? (?????????)"
          
        case else :                 ' Fallback
             QAErrorLog "The test does not support language " +iSprache
             fLocaleString = "Abortion"
             exit function
    end select
      
    select case sReturn
        case "LocaleTableHeading"       : fLocaleString = slocaleTableHeading
        case "LocaleTableContents"      : fLocaleString = slocaleTableContents
        case "LocaleNumber"             : fLocaleString = sLocaleNumber
        case "LocaleText"               : fLocaleString = sLocaleText
        case "LocaleCurrency"           : fLocaleString = sLocaleCurrency
        case "LocaleDate"               : fLocaleString = sLocaleDate
        case "LocaleTime"               : fLocaleString = sLocaleTime
        case "LocalePercent"            : fLocaleString = sLocalePercent
        case "LocaleScientific"         : fLocaleString = sLocaleScientific
        case "LocaleFraction"           : fLocaleString = sLocaleFraction
        case "LocaleBoolean"            : fLocaleString = sLocaleBoolean
        case "LocaleTable"              : fLocaleString = sLocaleTable
        case "LocaleCurrencyValue"      : fLocaleString = sLocaleCurrencyValue
        case "LocaleDateValue"          : fLocaleString = sLocaleDateValue
        case "LocaleDateOutput"         : fLocaleString = sLocaleDateOutput
        case "LocaleTimeInput"          : fLocaleString = sLocaleTimeInput
        case "LocaleTimeValue"          : fLocaleString = sLocaleTimeValue
        case "LocalePercentValue"		: fLocaleString = slocalePercentValue
        case "LocaleScientificValue"	: fLocaleString = sLocaleScientificValue
        case "LocaleBooleanValue"       : fLocaleString = sLocaleBooleanValue
        case "LocaleLocaleSettings"     : fLocaleString = sLocaleLocaleSettings
        case "LocaleScriptType"         : fLocaleString = sLocaleScriptType
        case "LocaleNumFormLanEng"      : fLocaleString = sLocaleNumFormLanEng
        case "LocaleNumFormLanLith"     : fLocaleString = sLocaleNumFormLanLith
        case "LocaleNumFormLanDutch"    : fLocaleString = sLocaleNumFormLanDutch
        
        case else :                 ' Fallback
            QAErrorLog "String not available"
            fLocaleString = "Abortion"
    end select
  
end function
