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
'* short description : import presentations with shapes in .ppt format
'*
'************************************************************************
'*
' #1  t_import_shapes     ' Load all shapes with .ppt format one time
'*
'\***********************************************************************

testcase t_import_shapes
    dim i as integer
    dim iOldState as integer
    dim iDocuments as integer
    dim lDocuments(100) as string
    dim sPage as string

    iOldState = hSetMacroSecurity ( 0 )
    iDocuments = GetFileList(convertPath(gTesttoolPath + "graphics/required/input/shapes"),"*.ppt",lDocuments())
    for i = 1 to iDocuments
        printlog "(" + i + "/" + iDocuments + "): " + lDocuments(i)
        printlog "------------------------------------------------------"
        hFileOpen(lDocuments(i))
        
        ' check if the document is writable
        if fIsDocumentWritable = false then
            ' make the document writable and check if it's succesfull 
            if fMakeDocumentWritable = false then
                warnlog "The document can't be make writeable. Test stopped."
                goto endsub
            endif
        endif

        kontext "DocumentImpress"
        DocumentImpress.typeKeys("<home>")
        while (sPage <> DocumentImpress.StatusGetText(DocumentImpress.StatusGetItemID(6)))
            printlog "------------"
            sleep 1
            DocumentImpress.typeKeys("<tab>")
            sleep 1 ' loop while empty: break after 10 minutes
            DocumentImpress.typeKeys("<tab>")
            FormatPositionAndSize
                kontext
                active.setpage TabPositionAndSize
                kontext "TabPositionAndSize"
                printlog "w: '" + Width.getText + "'; h: '" + Height.getText + "'"
            TabPositionAndSize.cancel
            kontext "DocumentImpress"
            DocumentImpress.typeKeys("<F2>")
            editSelectAll
            editCopy
            printlog getClipboard
            sPage = DocumentImpress.StatusGetText(DocumentImpress.StatusGetItemID(6))
            printlog sPage
            DocumentImpress.typeKeys("<escape><pageDown>")
            sleep 5
        wend
        hCloseDocument
    next i
hSetMacroSecurity ( iOldState )
endcase

