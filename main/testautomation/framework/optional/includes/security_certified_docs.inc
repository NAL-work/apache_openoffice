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
'*  short description : Load certified documents and verify the certificate
'*
'\******************************************************************************

testcase tLoadCertifiedFile( cBuildID as string )


    ' Build the path to the file we want to work with 
    dim cFile as string
        cFile = gTesttoolpath & "framework\optional\input\security\DigitalSignature"
        cFile = cFile & hGetSuffix( cBuildId )
        cFile = convertpath( cFile )
        printlog( "Using file: " & cFile )

    dim cSigName as string
    dim sCertData( 20 ) as string
    
    dim sFileIn as string
        sFileIn = gTesttoolPath & "framework\optional\input\security\certificate_data.txt"
        sFileIn = convertpath( sFileIn )

    dim sFileOut as string
        sFileOut = hGetWorkPath() & "certificate_data.txt"

    ' Variable to store boolean returncodes from functions
    dim brc as boolean : brc = true
    dim irc as boolean : irc = 0

    ' the number of certificates attached to the current document        
    dim iCertCount as integer

    printlog( "Load the file" )
    hFileOpen( cFile )
    brc = hHandleActivesOnLoad( 0 , 2 )
    
    ' in case the file did not get loaded, handle the problem by aborting the test
    if ( not brc ) then
        warnlog( "The requested file could not be loaded, aborting test" )
        goto endsub
    endif
 
    brc = hOpenDigitalSignaturesDialog() 

    ' If the menuitem should not be available, clicking it will fail. In 
    ' this case we must assume that the file has been loaded but the certificate
    ' does not exist. So we close the document and abort the test here.
    if ( not brc ) then
        warnlog( "The requested menuitem is not available, the test ends" )
        call hCloseDocument()
        goto endsub
    endif
    
    ' second line of defense: If something was opened but this is not the
    ' digital signatures dialog, we abort as well.
    ' If no mozill a profile exists, we don't have the means to verify
    ' certificates, so the test aborts here as well. We get a messagebox then.
    Kontext "DigitalSignature"
    if ( not DigitalSignature.exists( 2 ) )  then
        Kontext "active"
        if ( active.exists() ) then
            qaerrorlog( "#i48252# Mozilla profile missing?: " & active.getText() )
            active.OK()
        else
            warnlog( "The current dialog is not <Digital Signatures>. Aborting" )
        endif
        call hCloseDocument()
        goto endsub
    endif
    
    ' If we have zero or more than one certificate, this is probably a bug
    ' introduced by the test maintainer. However, we warn but the test can
    ' continue
    Kontext "DigitalSignature"
    
    ViewCertificate.click()
   
    hSelectXMLSecTab( "PATH" )

    qaerrorlog( "Skipping EditBrowseBox: Not implemented in Testtool yet" )
    goto SkipEditBrowseBox

    kontext "TabXMLSecCertPath"
    XMLSecViewSigTree.select( 1 )
    cSigName = XMLSecViewSigTree.getSelText()
    if ( cSigName <> "Dummy Certificate for Testing" ) then
        warnlog( "The certificate at pos. 1 is not the dummy certificate: " & cSigName )
    else
        printlog( "Found correct certificate name: " & cSigName )
    endif

    hSelectXMLSecTab( "DETAILS" )

    kontext "TabXMLSecDetails"
    hGetListItems( XMLSecDetailsListBox, sCertData() ) 

    irc = hManageComparisionList( sFileIn, sFileOut, sCertData() )
    hListResultEvaluation( irc , 0 )

    SkipEditBrowseBox:

    hSelectXMLSecTab( "GENERAL" )
    kontext "TabXMLSecGeneral" 
    
    TabXMLSecGeneral.ok()
    
    printlog( "Close the dialog with OK" )
    Kontext "DigitalSignature"
    DigitalSignature.OK()
    
    printlog( "Close the document" )
    call hCloseDocument()
    
endcase

