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


#ifndef _BYTE_CHUCKER_HXX_
#define _BYTE_CHUCKER_HXX_

#include <com/sun/star/uno/Sequence.h>
#include <com/sun/star/uno/Reference.h>
#include <com/sun/star/io/BufferSizeExceededException.hpp>
#include <com/sun/star/io/IOException.hpp>
#include <com/sun/star/io/NotConnectedException.hpp>
#include <com/sun/star/uno/RuntimeException.hpp>
#include <com/sun/star/lang/IllegalArgumentException.hpp>

namespace com { namespace sun { namespace star {
	namespace io { class XSeekable; class XOutputStream; }
} } }
class ByteChucker 
{
protected:
	com::sun::star::uno::Reference < com::sun::star::io::XOutputStream > xStream;
	com::sun::star::uno::Reference < com::sun::star::io::XSeekable > xSeek;
	com::sun::star::uno::Sequence < sal_Int8 > a1Sequence, a2Sequence, a4Sequence;
	sal_Int8 * const p1Sequence, * const p2Sequence, * const p4Sequence;

public:
	ByteChucker (com::sun::star::uno::Reference<com::sun::star::io::XOutputStream> xOstream);
	~ByteChucker();

    void WriteBytes( const ::com::sun::star::uno::Sequence< sal_Int8 >& aData )
		throw(::com::sun::star::io::NotConnectedException, ::com::sun::star::io::BufferSizeExceededException, ::com::sun::star::io::IOException, ::com::sun::star::uno::RuntimeException);

    sal_Int64 GetPosition() 
		throw(::com::sun::star::io::IOException, ::com::sun::star::uno::RuntimeException);

	ByteChucker& operator << (sal_Int8 nInt8);
	ByteChucker& operator << (sal_Int16 nInt16);
	ByteChucker& operator << (sal_Int32 nInt32);
	ByteChucker& operator << (sal_uInt8 nuInt8);
	ByteChucker& operator << (sal_uInt16 nuInt16);
	ByteChucker& operator << (sal_uInt32 nuInt32);
};

#endif
