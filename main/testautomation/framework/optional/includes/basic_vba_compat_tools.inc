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
'*  short description : Small helpers for Excel BASIC import modes
'*
'\******************************************************************************

function hSetExcelBasicImportMode( bImport as boolean, bEnable as boolean )

    printlog( "Changing Excel VBA import modes" )

    ToolsOptions
    hToolsOptions( "LoadSave", "VBAProperties" )
   
    if ( bImport ) then
        ExcelBasicLaden.check()
        if ( bEnable ) then
            ExecutableCode.check()
        else
            ExecutableCode.uncheck()
        endif
    else
        ExcelBasicLaden.uncheck()
    endif
    
    Kontext "OptionenDlg"
    OptionenDlg.ok()

end function

'*******************************************************************************

function hSetExcelImportModeDefault()

    printlog( "Setting Excel VBA import modes to default" )

    ToolsOptions
    hToolsOptions( "LoadSave", "VBAProperties" )
    
    ExcelBasicLaden.check()
    ExecutableCode.uncheck()
    
    Kontext "OptionenDlg"
    OptionenDlg.ok()

end function
