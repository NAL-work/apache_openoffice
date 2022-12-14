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
'* short description : check the internal file dialog ( extended tests )
'*
'\******************************************************************************

testcase tSaveLoadDelFilesCJK()

    printlog( "Save, load and delete files from the hight UTF-8 characters list" )

    if ( not hTestLocale() ) then
        qaerrorlog( "Could not verify UTF-8 locale. Make sure an UTF-8 locale is used!" )
    endif
    
    dim cStrangeName as string
    dim iCounter as integer ' iterator
    dim iRandom  as long    ' random number
    dim brc as boolean
    
    printlog( "Invoke randomizer" )
    call randomize()
    
    printlog( "Generate filenames, run tests" )
    for iCounter = 1 to 2
        
        iRandom = int( 19968 + ( 20911 * rnd ) )
        printlog( "" )
        printlog( " * Using decimal char: " & iRandom )
        
        cStrangeName = hNameGen_append( iRandom )
        hSaveLoadDelSuccess( cStrangeName )
        
        cStrangeName = hNameGen_lead( iRandom )
        hSaveLoadDelSuccess( cStrangeName )
        
        kontext "active"
        if( active.exists() ) then
            qaerrorlog( "#i33964# Document does not exist when the last document is deleted from filepicker" )
            printlog( active.gettext() )
            active.ok()
        endif

        printlog( "Delete the file" )        
        hDeleteFile( hGetWorkPath() & cStrangeName )        
        
        printlog( "Close navigator, if it exists" )
        kontext "Navigator"
        hCloseDialog( Navigator, "close,optional" )
        
    next iCounter
    
    printlog( "Close the document" )
    hDestroyDocument()
    
endcase

