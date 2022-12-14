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

testcase tSaveReservedNamesWin()

    if ( gPlatGroup <> "w95" ) then
        printlog( "Test not relevant for Windows" )
        goto endsub
    endif

    
    ' This sub creates invalid filenames on Windows and tries to save files
    ' with those names. This should fail.
    ' The names are created dependent on the gApplication (documenttype)
    ' which must have been specified in advance. To generate the names the
    ' function hNameGenASCII_append( int, boolean ) is used which generates
    ' the file-suffix based on the current 'gApplication'
    ' Since saving is expected to fail in every case, there is no reload-test
    ' for these filenames
    
    dim cStrangeName as string
    dim iCounter as integer
    dim brc as boolean
    
    const MAX_NUMBER = 1
    
    dim iCurrentDocType as integer
    
    for iCurrentDocType = 1 to 2 
    
        printlog( "" )
        printlog( "Document Type is: " & hNumericDocType( iCurrentDocType ) )    
    
        
        printlog( CHR$(13) )
        printlog( "Check if reserved filenames on Windows are handled ok" )
        printlog( CHR$(13) )
        
        
        ' serial ports with extension (COM1.xxx-COM9.xxx are not allowed)
        printlog( CHR$(13) + "Serial ports with extensions" )
        for iCounter = 1 to MAX_NUMBER
            cStrangeName = "COM" & CHR$( iCounter + 48 )
            cStrangeName = cStrangeName & hGetSuffix( "current" )
            brc = hSaveFileExpectFailure( cStrangeName , 0 )
            if ( not brc ) then warnlog( "failed" )
        next iCounter
        
        
        ' parallel ports with extension (LPT1.xxx-LPT9.xxx are not allowed)
        printlog( CHR$(13) + "Parallel ports with extension" )
        for iCounter = 1 to MAX_NUMBER
            cStrangeName = "LPT" & CHR$( iCounter + 48 )
            cStrangeName = cStrangeName & hGetSuffix( "current" )
            brc = hSaveFileExpectFailure( cStrangeName , 0 )
            if ( not brc ) then warnlog( "failed" )
        next iCounter
        
        
        printlog( "" )
        printlog( "Reserved characters" )
        
        ' descr: hNameGenASCII_append takes an ASCII-char as int and a boolean
        ' value for "append file suffix" if true
        ' descr: SaveFileExpectFailure takes a filename and a numeric value for
        ' the type of errorhandling (0 = invalid char, 1 = path separator)
        
        cStrangeName = hNameGen_append( 60 ) ' char "<"
        brc = hSaveFileExpectFailure( cStrangeName , 0 )
        if ( not brc ) then warnlog( "failed" )
        
        cStrangeName = hNameGen_append( 62 ) ' char ">"
        brc = hSaveFileExpectFailure( cStrangeName , 0 )
        if ( not brc ) then warnlog( "failed" )
        
        cStrangeName = hNameGen_append( 34 ) ' char '"'
        brc = hSaveFileExpectFailure( cStrangeName , 0 )
        if ( not brc ) then warnlog( "failed" )
        
        cStrangeName = hNameGen_append( 124 ) ' char "|"
        brc = hSaveFileExpectFailure( cStrangeName , 0 )
        if ( not brc ) then warnlog( "failed" )
        
        'misinterpreted characters (seen as UNC name or device by Windows)
        cStrangeName = hNameGen_append( 92 ) ' char "\"
        brc = hSaveFileExpectFailure( cStrangeName , 1 )
        if ( not brc ) then warnlog( "failed" )
        
        cStrangeName = hNameGen_append( 47 ) ' char "/"
        brc = hSaveFileExpectFailure( cStrangeName , 1 )
        if ( not brc ) then warnlog( "failed" )
        
        cStrangeName = hNameGen_append( 58 ) ' char ":"
        brc = hSaveFileExpectFailure( cStrangeName , 0 )
        if ( not brc ) then warnlog( "failed" )
        
        printlog( "Close the document" )
        brc = hDestroyDocument()
        
    next iCurrentDocType
    
endcase

