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



#ifndef __FRAMEWORK_HELPER_DOCKINGAREADEFAULTACCEPTOR_HXX_
#define __FRAMEWORK_HELPER_DOCKINGAREADEFAULTACCEPTOR_HXX_

//_________________________________________________________________________________________________________________
//	my own includes
//_________________________________________________________________________________________________________________

#include <classes/framecontainer.hxx>
#include <threadhelp/threadhelpbase.hxx>
#include <macros/generic.hxx>
#include <macros/xinterface.hxx>
#include <macros/xtypeprovider.hxx>
#include <macros/debug.hxx>

//_________________________________________________________________________________________________________________
//	interface includes
//_________________________________________________________________________________________________________________
#include <com/sun/star/ui/XDockingAreaAcceptor.hpp>
#include <com/sun/star/frame/XFrame.hpp>

//_________________________________________________________________________________________________________________
//	other includes
//_________________________________________________________________________________________________________________
#include <cppuhelper/implbase1.hxx>
#include <cppuhelper/weakref.hxx>

//_________________________________________________________________________________________________________________
//	namespace
//_________________________________________________________________________________________________________________

namespace framework{

//_________________________________________________________________________________________________________________


class DockingAreaDefaultAcceptor    :	private ThreadHelpBase                                      ,
						                public ::cppu::WeakImplHelper1< ::com::sun::star::ui::XDockingAreaAcceptor >
{
    public:

		//---------------------------------------------------------------------------------------------------------
		//	constructor / destructor
		//---------------------------------------------------------------------------------------------------------

		/*-****************************************************************************************************//**
			@short		constructor to initialize this instance
			@descr		A docking area acceptor
						But we need a instance to create more then one enumerations to the same tasklist!

			@seealso	class Desktop
			@seealso	class OTasksEnumeration

			@param		"xOwner" is a reference to our owner and must be the desktop!
			@param		"pTasks" is a pointer to the taskcontainer of the desktop. We need it to create a new enumeration.
			@return		-

			@onerror	Do nothing and reset this object to default with an empty list.
		*//*-*****************************************************************************************************/

	 	DockingAreaDefaultAcceptor(	const css::uno::Reference< css::frame::XFrame >& xOwner );
        virtual ~DockingAreaDefaultAcceptor();

        //---------------------------------------------------------------------------------------------------------
		//	XDockingAreaAcceptor
		//---------------------------------------------------------------------------------------------------------

        virtual css::uno::Reference< css::awt::XWindow > SAL_CALL getContainerWindow() throw (css::uno::RuntimeException);
        virtual sal_Bool SAL_CALL requestDockingAreaSpace( const css::awt::Rectangle& RequestedSpace ) throw (css::uno::RuntimeException);
        virtual void SAL_CALL setDockingAreaSpace( const css::awt::Rectangle& BorderSpace ) throw (css::uno::RuntimeException);


	//-------------------------------------------------------------------------------------------------------------
	//	variables
	//	(should be private everyway!)
	//-------------------------------------------------------------------------------------------------------------

	private:

		css::uno::WeakReference< css::frame::XFrame >		m_xOwner			;	/// weak reference to our frame object!
};

} // namespace framework

#endif // __FRAMEWORK_HELPER_DOCKINGAREADEFAULTACCEPTOR_HXX_
