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


#ifndef _PACKAGE_CONSTANTS_HXX_
#define _PACKAGE_CONSTANTS_HXX_

#include <sal/types.h>

const sal_Int32 n_ConstBufferSize = 32768;
const sal_Int32 n_ConstMaxMemoryStreamSize = 20480;

// by calculation of the digest we read 32 bytes more ( if available )
// it allows to ignore the padding if the stream is longer than n_ConstDigestDecrypt since we read at least two blocks more;
// if the stream is shorter or equal the padding will be done successfully
const sal_Int32 n_ConstDigestLength = 1024;
const sal_Int32 n_ConstDigestDecrypt = 1056; // 1024 + 32

// the constants related to the manifest.xml entries
#define PKG_MNFST_MEDIATYPE   0
#define PKG_MNFST_VERSION     1
#define PKG_MNFST_FULLPATH    2

#define PKG_MNFST_INIVECTOR   3
#define PKG_MNFST_SALT        4
#define PKG_MNFST_ITERATION   5
#define PKG_MNFST_UCOMPSIZE   6
#define PKG_MNFST_DIGEST      7
#define PKG_MNFST_ENCALG      8
#define PKG_MNFST_STARTALG    9
#define PKG_MNFST_DIGESTALG  10
#define PKG_MNFST_DERKEYSIZE 11

#define PKG_SIZE_NOENCR_MNFST 3
#define PKG_SIZE_ENCR_MNFST   12

// the properties related constants
#define ENCRYPTION_KEY_PROPERTY "EncryptionKey"
#define STORAGE_ENCRYPTION_KEYS_PROPERTY "StorageEncryptionKeys"
#define ENCRYPTION_ALGORITHMS_PROPERTY "EncryptionAlgorithms"
#define HAS_ENCRYPTED_ENTRIES_PROPERTY "HasEncryptedEntries"
#define HAS_NONENCRYPTED_ENTRIES_PROPERTY "HasNonEncryptedEntries"
#define IS_INCONSISTENT_PROPERTY "IsInconsistent"
#define MEDIATYPE_FALLBACK_USED_PROPERTY "MediaTypeFallbackUsed"


#endif

