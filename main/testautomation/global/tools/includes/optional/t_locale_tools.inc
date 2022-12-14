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
'* short description : place it here
'*
'\***********************************************************************
'*
' #1 fThesaurusLocales         'Get locales which are supported by Thesaurus
' #1 fSpellcheckerLocales      'Get locales which are supported by Spellchecker
'*
'\***********************************************************************

function fThesaurusLocales as boolean
'/// Gets the supported thesaurus locales from the API
'/// Returns TRUE if iSprache is supported by Thesaurus
'/// Returns FALSE if iSprache is not supported by Thesaurus

    dim uno as object
    dim linugServiceMgr as object
    dim aAllLocales (256) as variant
    dim sLocale as string
    dim i as integer
    
    fThesaurusLocales = FALSE
    uno=hGetUnoService()
    linugServiceMgr=uno.createInstance("com.sun.star.linguistic2.LinguServiceManager")
    aAllLocales = linugServiceMgr.getThesaurus().getLocales()
    for i = 0 to ubound( aAllLocales ())
        sLocale = ( aAllLocales(i).Language & "-" & (aAllLocales(i).Country) )
        printlog sLocale
        if ConvertLanguage2 ( sLocale ) = iSprache then
            fThesaurusLocales = TRUE
            i = ubound( aAllLocales ())
        endif
    next i

end function

'-----------------------------------------------------------

function fSpellcheckerLocales as boolean
'/// Gets the supported spellchecker locales from the API
'/// Returns TRUE if iSprache is supported by Spellchecker
'/// Returns FALSE if iSprache is not supported by Spellchecker

    dim uno as object
    dim linugServiceMgr as object
    dim aAllLocales (256) as variant
    dim sLocale as string
    dim i as integer
    
    fSpellcheckerLocales = FALSE
    uno=hGetUnoService()
    linugServiceMgr=uno.createInstance("com.sun.star.linguistic2.LinguServiceManager")
    aAllLocales = linugServiceMgr.getSpellchecker().getLocales()
    for i = 0 to ubound( aAllLocales ())
        sLocale = ( aAllLocales(i).Language & "-" & (aAllLocales(i).Country) )
        printlog sLocale
        if ConvertLanguage2 ( sLocale ) = iSprache then
            fSpellcheckerLocales = TRUE
            i = ubound( aAllLocales ())
        endif
    next i

end function

