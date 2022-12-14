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
'* short description : Tools->Options: OpenOffice.org Accessibility
'*
'\******************************************************************************

testcase tOOoAccessibility

   Dim lbSave ( 10 ) as Boolean
   Dim sSave as String

 printlog " - save default setting"
   ToolsOptions
   hToolsOptions ( "StarOffice", "Accessibility" )

   lbSave (9) = AutomaticDetectHC.IsChecked
   lbSave (2) = ForPagePreviews.IsChecked
   lbSave (3) = HelpTips.IsChecked
   sSave      = After.GetText
   lbSave (4) = AllowAnimatedGraphics.IsChecked
   lbSave (5) = AllowAnimatedText.IsChecked
   lbSave (6) = AlwaysUseAutomaticFontColor.IsChecked
   'lbSave (7) = UseSystemFont.IsChecked
   lbSave (10) = UseTextSelectionCursor.IsChecked
   if SupportAssistiveTechnologyTools.Exists and SupportAssistiveTechnologyTools.IsVisible then
      lbSave (8) = SupportAssistiveTechnologyTools.IsChecked
   end if


 printlog " - revers/change settings"
   if lbSave (9) = TRUE then AutomaticDetectHC.UnCheck else AutomaticDetectHC.Check
   if lbSave (2) = TRUE then ForPagePreviews.Uncheck else ForPagePreviews.Check
   HelpTips.Check
   After.SetText  "17"
   if lbSave (3) = TRUE then HelpTips.Uncheck else HelpTips.Check
   if lbSave (4) = TRUE then AllowAnimatedGraphics.Uncheck else AllowAnimatedGraphics.Check
   if lbSave (5) = TRUE then AllowAnimatedText.Uncheck else AllowAnimatedText.Check
   if lbSave (6) = TRUE then AlwaysUseAutomaticFontColor.Uncheck else AlwaysUseAutomaticFontColor.Check
   'if lbSave (7) = TRUE then UseSystemFont.Uncheck else UseSystemFont.Check
   if lbSave (10) = TRUE then UseTextSelectionCursor.Uncheck else UseTextSelectionCursor.Check
   if SupportAssistiveTechnologyTools.Exists and SupportAssistiveTechnologyTools.IsVisible then
      if (gPlatgroup <> "unx") then
         Printlog "'Support assistive technology tools' won't be tested due to system dialog could come up and look the test out :-("
      else
         Warnlog "unexpected error 4711 :-)"
      endif
'      if lbSave (8) = TRUE then SupportAssistiveTechnologyTools.Uncheck else SupportAssistiveTechnologyTools.Check
   else
      if (gPlatgroup <> "unx") then
         Warnlog "'Support assistive technology tools' is not available :-("
      endif
   end if

 printlog " - press OK at the options dialog"
   Kontext "ExtrasOptionenDlg"
   ExtrasOptionenDlg.OK
   Sleep (3)

 printlog " - exit/restart StarOffice"
   ExitRestartTheOffice

 printlog " - check settings"
   ToolsOptions
   hToolsOptions ( "StarOffice", "Accessibility" )

   if AutomaticDetectHC.IsChecked = lbSave (9) then warnlog "Automatic Detect HC ... : => changes not saved!"
   if ForPagePreviews.IsChecked = lbSave (2) then warnlog "For Page Previews : => changes not saved!"
   if HelpTips.IsChecked = lbSave (3) then warnlog "Help Tips : => changes not saved!"
   HelpTips.Check
   if After.GetText <> "17" then warnlog "After... : => changes not saved!"
   if AllowAnimatedGraphics.IsChecked = lbSave (4) then warnlog "Allow Animated Graphics : => changes not saved!"
   if AllowAnimatedText.IsChecked = lbSave (5) then warnlog "Allow Animated Text : => changes not saved!"
   if AlwaysUseAutomaticFontColor.IsChecked = lbSave (6) then warnlog "Always Use Automatic Font Color : => changes not saved!"
   'if UseSystemFont.IsChecked = lbSave (7) then warnlog "Use System Font : => changes not saved!"
   if UseTextSelectionCursor.IsChecked = lbSave (10) then warnlog "Use Text Selection Cursor : => changes not saved!"
'   if SupportAssistiveTechnologyTools.Exists and SupportAssistiveTechnologyTools.IsVisible then
'      if SupportAssistiveTechnologyTools.IsChecked = lbSave (8) then warnlog "Support Assistive Technology Tools : => changes not saved!"
'   end if

 printlog " - second settings"
   AutomaticDetectHC.UnCheck
   ForPagePreviews.Check
   HelpTips.Check
   After.SetText  "1"
   AllowAnimatedGraphics.Uncheck
   AllowAnimatedText.Check
   AlwaysUseAutomaticFontColor.Uncheck
   'UseSystemFont.Check
   UseTextSelectionCursor.UnCheck
   if SupportAssistiveTechnologyTools.Exists and SupportAssistiveTechnologyTools.IsVisible then
      SupportAssistiveTechnologyTools.Uncheck
   end if

 printlog " - press OK at the options dialog"
   Kontext "ExtrasOptionenDlg"
   ExtrasOptionenDlg.OK
   Sleep (3)

 printlog " - check changes"
   ToolsOptions
   hToolsOptions ( "StarOffice", "Accessibility" )

   if AutomaticDetectHC.IsChecked <> FALSE then warnlog "Automatic Detect HC ... : => changes not saved!"
   if ForPagePreviews.IsChecked <> TRUE then warnlog "For Page Previews : => changes not saved!"
   if HelpTips.IsChecked <> TRUE then warnlog "Help Tips : => changes not saved!"
   if After.GetText <> "1" then warnlog "After... : => changes not saved!"
   if AllowAnimatedGraphics.IsChecked <> FALSE then warnlog "Allow Animated Graphics : => changes not saved!"
   if AllowAnimatedText.IsChecked <> TRUE then warnlog "Allow Animated Text : => changes not saved!"
   if AlwaysUseAutomaticFontColor.IsChecked <> FALSE then warnlog "Always Use Automatic Font Color : => changes not saved!"
   'if UseSystemFont.IsChecked <> TRUE then warnlog "Use System Font : => changes not saved!"
   if UseTextSelectionCursor.IsChecked <> FALSE then warnlog "Use Text Selection Cursor : => changes not saved!"
   if SupportAssistiveTechnologyTools.Exists and SupportAssistiveTechnologyTools.IsVisible then
      if SupportAssistiveTechnologyTools.IsChecked <> FALSE then warnlog "Support Assistive Technology Tools : => changes not saved!"
   end if

   if lbSave (9) = TRUE then AutomaticDetectHC.Check else AutomaticDetectHC.UnCheck
   if lbSave (2) = TRUE then ForPagePreviews.Check else ForPagePreviews.UnCheck
   HelpTips.Check
   After.SetText  sSave
   if lbSave (3) = TRUE then HelpTips.Check else HelpTips.UnCheck
   if lbSave (4) = TRUE then AllowAnimatedGraphics.Check else AllowAnimatedGraphics.UnCheck
   if lbSave (5) = TRUE then AllowAnimatedText.Check else AllowAnimatedText.UnCheck
   if lbSave (6) = TRUE then AlwaysUseAutomaticFontColor.Check else AlwaysUseAutomaticFontColor.UnCheck
   'if lbSave (7) = TRUE then UseSystemFont.Check else UseSystemFont.UnCheck
   if lbSave (10) = TRUE then UseTextSelectionCursor.Check else UseTextSelectionCursor.UnCheck
   if SupportAssistiveTechnologyTools.Exists and SupportAssistiveTechnologyTools.IsVisible then
      if lbSave (8) = TRUE then SupportAssistiveTechnologyTools.Check else SupportAssistiveTechnologyTools.UnCheck
   end if

 printlog " - press OK at the options dialog"
   Kontext "ExtrasOptionenDlg"
   ExtrasOptionenDlg.OK
   Sleep (3)

 printlog " - check reset"
   ToolsOptions
   hToolsOptions ( "StarOffice", "Accessibility" )

   if AutomaticDetectHC.IsChecked <> lbSave (9) then warnlog "Automatic Detect HC ... : => changes not saved!"
   if ForPagePreviews.IsChecked <> lbSave (2) then warnlog "For Page Previews : => changes not saved!"
   if HelpTips.IsChecked <> lbSave (3) then warnlog "Help Tips : => changes not saved!"
   HelpTips.Check
   if After.GetText <> sSave then warnlog "After... : => changes not saved!"
   if AllowAnimatedGraphics.IsChecked <> lbSave (4) then warnlog "Allow Animated Graphics : => changes not saved!"
   if AllowAnimatedText.IsChecked <> lbSave (5) then warnlog "Allow Animated Text : => changes not saved!"
   if AlwaysUseAutomaticFontColor.IsChecked <> lbSave (6) then warnlog "Always Use Automatic Font Color : => changes not saved!"
   'if UseSystemFont.IsChecked <> lbSave (7) then warnlog "Use System Font : => changes not saved!"
   if UseTextSelectionCursor.IsChecked <> lbSave (10) then warnlog "Use Text Selection Cursor : => changes not saved!"
   if SupportAssistiveTechnologyTools.Exists and SupportAssistiveTechnologyTools.IsVisible then
      if SupportAssistiveTechnologyTools.IsChecked <> lbSave (8) then warnlog "Support Assistive Technology Tools : => changes not saved!"
   end if
 printlog " - press OK at the options dialog"
   Kontext "ExtrasOptionenDlg"
   ExtrasOptionenDlg.OK
   Sleep (3)

endcase

