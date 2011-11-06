/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



// MARKER(update_precomp.py): autogen include statement, do not remove
#include "precompiled_sd.hxx"

#include "MasterPagesPanel.hxx"
#include "taskpane/ScrollPanel.hxx"
#include "CurrentMasterPagesSelector.hxx"
#include "RecentMasterPagesSelector.hxx"
#include "AllMasterPagesSelector.hxx"
#include "taskpane/ToolPanelViewShell.hxx"
#include "taskpane/TaskPaneControlFactory.hxx"
#include "taskpane/TitledControl.hxx"
#include "../TaskPaneShellManager.hxx"

#include "DrawViewShell.hxx"
#include "ViewShellBase.hxx"

#include "strings.hrc"
#include "sdresid.hxx"
#include "helpids.h"
#include <svtools/valueset.hxx>
#include "app.hrc"

namespace sd { namespace toolpanel { namespace controls {


MasterPagesPanel::MasterPagesPanel (::Window& i_rParentWindow, ToolPanelViewShell& i_rPanelViewShell)
    :ScrollPanel (i_rParentWindow)
    ,m_pPanelViewShell( &i_rPanelViewShell )
{
    impl_construct( m_pPanelViewShell->GetViewShellBase() );
}

void MasterPagesPanel::impl_construct( ViewShellBase& rBase )
{
    SdDrawDocument* pDocument = rBase.GetDocument();
    ::std::auto_ptr<controls::MasterPagesSelector> pSelector;
    TitledControl* pTitledControl;

    ::boost::shared_ptr<MasterPageContainer> pContainer (new MasterPageContainer());
    
    // Create a panel with the master pages that are in use by the currently
    // edited document.
    DrawViewShell* pDrawViewShell = dynamic_cast<DrawViewShell*>(rBase.GetMainViewShell().get());
    pSelector.reset(new controls::CurrentMasterPagesSelector (
        this, 
        *pDocument,
        rBase,
        pContainer));
    pSelector->LateInit();
    pSelector->SetHelpId( HID_SD_TASK_PANE_PREVIEW_CURRENT );
    GetShellManager()->AddSubShell(
        SHELLID_SD_TASK_PANE_PREVIEW_CURRENT,
        pSelector.get(),
        pSelector->GetWindow());
    pTitledControl = AddControl (
        ::std::auto_ptr<TreeNode>(pSelector.release()),
        SdResId(STR_TASKPANEL_CURRENT_MASTER_PAGES_TITLE),
        HID_SD_CURRENT_MASTERS);
    
    // Create a panel with the most recently used master pages.
    pSelector.reset(new controls::RecentMasterPagesSelector (
        this, 
        *pDocument,
        rBase,
        pContainer));
    pSelector->LateInit();
    pSelector->SetHelpId( HID_SD_TASK_PANE_PREVIEW_RECENT );
    GetShellManager()->AddSubShell(
        SHELLID_SD_TASK_PANE_PREVIEW_RECENT,
        pSelector.get(),
        pSelector->GetWindow());
    pTitledControl = AddControl (
        ::std::auto_ptr<TreeNode>(pSelector.release()),
        SdResId(STR_TASKPANEL_RECENT_MASTER_PAGES_TITLE),
        HID_SD_RECENT_MASTERS);

    // Create a panel with all available master pages.
    pSelector.reset(new controls::AllMasterPagesSelector (
        this, 
        *pDocument,
        rBase,
        *pDrawViewShell,
        pContainer));
    pSelector->LateInit();
    pSelector->SetHelpId( HID_SD_TASK_PANE_PREVIEW_ALL );
    GetShellManager()->AddSubShell(
        SHELLID_SD_TASK_PANE_PREVIEW_ALL,
        pSelector.get(),
        pSelector->GetWindow());
    pTitledControl = AddControl (
        ::std::auto_ptr<TreeNode>(pSelector.release()),
        SdResId(STR_TASKPANEL_ALL_MASTER_PAGES_TITLE),
        HID_SD_ALL_MASTERS);
}





MasterPagesPanel::~MasterPagesPanel (void)
{
    TaskPaneShellManager* pShellManager( GetShellManager() );
    OSL_ENSURE( pShellManager, "MasterPagesPanel::~MasterPagesPanel: no shell manager anymore - cannot remove sub shells!" );
    if ( pShellManager )
    {
        pShellManager->RemoveSubShell( SHELLID_SD_TASK_PANE_PREVIEW_CURRENT );
        pShellManager->RemoveSubShell( SHELLID_SD_TASK_PANE_PREVIEW_RECENT );
        pShellManager->RemoveSubShell( SHELLID_SD_TASK_PANE_PREVIEW_ALL );
    }
}




TaskPaneShellManager* MasterPagesPanel::GetShellManager()
{
    if ( m_pPanelViewShell )
        return &m_pPanelViewShell->GetSubShellManager();
    return TreeNode::GetShellManager();
}




std::auto_ptr< ControlFactory > MasterPagesPanel::CreateControlFactory( ToolPanelViewShell& i_rToolPanelShell )
{
    return std::auto_ptr< ControlFactory >(
        new RootControlFactoryWithArg< MasterPagesPanel, ToolPanelViewShell >( i_rToolPanelShell ) );
}

} } } // end of namespace ::sd::toolpanel::controls
