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



#ifndef INCLUDED_MAILDISPATCHER_HXX
#define INCLUDED_MAILDISPATCHER_HXX

//#ifndef _COM_SUN_STAR_MAIL_XMAILSERVER_HPP_
//#include "com/sun/star/mail/XMailServer.hpp"
//#endif
#include "com/sun/star/mail/XSmtpService.hpp"
#include "com/sun/star/mail/XMailMessage.hpp"
#include <osl/thread.hxx>
#include <osl/conditn.hxx>
#include <salhelper/refobj.hxx>

#include <list>

class IMailDispatcherListener;

/**
    A MailDispatcher should be used for sending a bunch a mail messages
    asynchronously. Usually a client enqueues a number of mail messages
    and then calls start to begin sending them. An instance of this class
    must not be shared among different client threads. Instead each client 
    thread should create an own instance of this class.
*/ 
class MailDispatcher : public ::salhelper::ReferenceObject, private ::osl::Thread
{
public:
    // bringing operator new/delete into scope    
	using osl::Thread::operator new;
	using osl::Thread::operator delete;
    using osl::Thread::join;
    		
public:

    /**                 
        @param xSmtpService
        [in] a reference to a mail server. A user must be
        connected to the mail server otherwise errors occur
        during the delivery of mail messages.
        
        @throws ::com::sun::star::uno::RuntimeException
        on errors during construction of an instance of this class.
    */
    MailDispatcher(::com::sun::star::uno::Reference< ::com::sun::star::mail::XSmtpService> xMailService);

    /**
        Shutdown the mail dispatcher. Every mail messages
        not yet sent will be discarded.
    */        
    virtual ~MailDispatcher();
    
    /**
        Enqueue a mail message for delivery. A client must
        start the mail dispatcher in order to send the 
        enqueued mail messages.
        
        @param xMailMessage
        [in] a mail message that should be send.
    */
    void enqueueMailMessage(::com::sun::star::uno::Reference< ::com::sun::star::mail::XMailMessage> xMailMessage);
    /** 
        Dequeues a mail message. 
        This enables the caller to remove attachments when sending mails is to be cancelled.
    */
    ::com::sun::star::uno::Reference< ::com::sun::star::mail::XMailMessage> dequeueMailMessage();
    
    /**
        Start sending mail messages asynchronously. A client may register
        a listener for mail dispatcher events. For every mail message sent 
        the notification will be sent. While handling such notification a 
        client may enqueue new mail messages. If there are no more mail
        messages to send an respective notification is sent and the mail
        dispatcher waits for more mail messages.
        
        @precond not isStarted()
    */
    void start();
    
    /**
        Stop sending mail messages.
        
        @precond isStarted()
    */
    void stop();

    /**
        Request shutdown of the mail dispatcher thread.
        NOTE: You must call this method before you release
        your last reference to this class otherwise the
        mail dispatcher thread will never end.
    */
    void shutdown();
                
    /**
        Check whether the mail dispatcher is started or not.
        
        @return 
        <TRUE/> if the sending thread is running.
    */
    bool isStarted() const;
            
    /** returns if the thread is still running
    */
	using osl::Thread::isRunning;
    
	/** returns if shutdown has already been called
    */
    bool isShutdownRequested() const  
        { return shutdown_requested_; }  
    /**
        Register a listener for mail dispatcher events.
    */
    void addListener(::rtl::Reference<IMailDispatcherListener> listener);
    
    /**
        Unregister a listener for mail dispatcher events
    */
    void removeListener(::rtl::Reference<IMailDispatcherListener> listener);
        
protected:
    virtual void SAL_CALL run();
    virtual void SAL_CALL onTerminated();

private:
    std::list< ::rtl::Reference<IMailDispatcherListener> > cloneListener();
    void sendMailMessageNotifyListener(::com::sun::star::uno::Reference< ::com::sun::star::mail::XMailMessage> message);           
    
private:    
    ::com::sun::star::uno::Reference< ::com::sun::star::mail::XSmtpService> mailserver_;    
    ::std::list< ::com::sun::star::uno::Reference< ::com::sun::star::mail::XMailMessage > > messages_;
    ::std::list< ::rtl::Reference<IMailDispatcherListener> > listeners_;    
    ::osl::Mutex message_container_mutex_;
    ::osl::Mutex listener_container_mutex_;    
    ::osl::Mutex thread_status_mutex_;
    ::osl::Condition mail_dispatcher_active_;
    ::osl::Condition wakening_call_;    
    ::rtl::Reference<MailDispatcher> m_xSelfReference;
    bool run_;    
    bool shutdown_requested_;
};

#endif // INCLUDED_MAILDISPATCHER_HXX