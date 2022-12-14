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
'*  short description : Supported extension platforms
'*
'\******************************************************************************

testcase tExtensionPlatforms

    printlog( "Verify that only extensions designed for this platform are installed" )
    
    dim cBasePath as string
        cBasePath = gTesttoolPath & "extensions\optional\input\platform\"
        cBasePath = convertpath( cBasePath )
    
    dim cConfigFile as string
        cConfigFile = cBasePath & "extensions.info"
        
    dim iExtensionCount as integer
    dim iCurrentExtension as integer
    
    dim cCurrentExtensionName as string
    dim cCurrentExtensionPath as string
    dim cCurrentExtensionFile as string
    dim cCurrentExtensionPlatform as string
    dim cInfoArray( 200 ) as string
    
    dim iStatus as integer
    dim bShouldInstall as boolean
    
    hGetDataFileSection( cConfigFile, cInfoArray(), "general", "", "" )
    iExtensionCount = hGetValueForKeyAsInt( cInfoArray(), "ExtensionCount" )

    for iCurrentExtension = 1 to iExtensionCount
    
        hGetDataFileSection( cConfigFile, cInfoArray(), iCurrentExtension, "" , "" )
        cCurrentExtensionFile = hGetValueForKeyAsString( cInfoArray(), "File" )
        cCurrentExtensionName = hGetValueForKeyAsString( cInfoArray(), "Name" )
        cCurrentExtensionPath = cBasePath & cCurrentExtensionFile
        cCurrentExtensionPlatform = hGetValueForKeyAsString( cInfoArray(), "Platform" )
        
        ' Find out whether the extension should install or not
        select case ( cCurrentExtensionPlatform )
        case "all"           : bShouldInstall = TRUE
        case gtSysName       : bShouldInstall = TRUE
        case gPlatGroup      : bShouldInstall = TRUE
        case gPlatform       : bShouldInstall = TRUE
        case else            : bShouldInstall = FALSE
        end select

        printlog( "" )
        printlog( "("+iCurrentExtension+"/"+iExtensionCount+") Current extension: " & cCurrentExtensionFile )
        iStatus = hExtensionAddGUI( cCurrentExtensionPath, "InstallForUser, NoLicense, NoUpdate, Verbose" )
        
        if ( iStatus = -7 or iStatus >= 0 ) then
        
            kontext "Active"
            if ( Active.exists( 2 ) ) then
                select case ( bShouldInstall ) 
                case TRUE  : warnlog( "Extension should install but a warning is displayed" )
                case FALSE : printlog( "Extension is for another platform, it is not installed" )
                end select
                Active.ok()
            else
                select case ( bShouldInstall ) 
                case TRUE  : printlog( "No platform mismatch warning. Good." )
                case FALSE : warnlog( "Platform mismatch warning is missing!" )
                end select
            endif
            
            kontext "PackageManager"
            if ( PackageManager.exists( 1 ) ) then PackageManager.close()

            iStatus = hExtensionRemoveGUI( cCurrentExtensionName )
            
            select case ( iStatus )
            case 0: ' Extension was removed successfully
                    select case ( bShouldInstall ) 
                    case TRUE  : printlog( "Extension was installed and removed, good" )
                    case FALSE : warnlog( "The extension was removed but should not be installed" )
                    end select
            case 3: ' Extension was not found at removal
                    select case ( bShouldInstall ) 
                    case TRUE  : warnlog( "The extension should have been installed but is missing" )
                    case FALSE : printlog( "The extension was not installed. Good" )
                    end select
            case else : ' Any other returnvalue is bad
                    warnlog( "Unexpected returnvalue from function: " & iStatus )
            end select
            
        else
            warnlog( "Bad status returned, installation of extension failed" )
            goto endsub
        endif
        
    next iCurrentExtension

endcase


