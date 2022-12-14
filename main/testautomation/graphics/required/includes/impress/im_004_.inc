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
'* short description : Impress Required Test Library (4)
'*
'\*****************************************************************

sub im_004_

    call tiInsertSlideExpandSummary()

end sub

'*******************************************************************************

testcase tiInsertSlideExpandSummary

    printlog "open application"
    Call hNewDocument
    printlog "View->Master View->Outline View"
    ViewWorkspaceOutlineView
    Sleep 1
    Kontext "DocumentImpressOutlineView"
    printlog "Type 2 rows"
    DocumentImpressOutlineView.TypeKeys "Herbert<Return>Rudi"
    printlog "View->Master View->Drawing View"
    ViewWorkspaceDrawingView
    Sleep 1
    printlog "Insert->Summery Slide"
    InsertSummerySlide
    Sleep 1
    printlog "Making sure we are on the 3rd slide.."
    kontext "slides"
    SlidesControl.TypeKeys "<PAGEDOWN>", 2
    sleep 1
    kontext "DocumentImpress"
    printlog "Insert->Expand Slide"
    InsertExpandSlide
    Sleep 2
    printlog "close application"
    Call  hCloseDocument

endcase 'tiInsertSlideExpandSummary

