/* Editor Settings: expandtabs and use 4 spaces for indentation
 * ex: set softtabstop=4 tabstop=8 expandtab shiftwidth=4: *
 * -*- mode: c, c-basic-offset: 4 -*- */

/*
 * Copyright © BeyondTrust Software 2004 - 2019
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * BEYONDTRUST MAKES THIS SOFTWARE AVAILABLE UNDER OTHER LICENSING TERMS AS
 * WELL. IF YOU HAVE ENTERED INTO A SEPARATE LICENSE AGREEMENT WITH
 * BEYONDTRUST, THEN YOU MAY ELECT TO USE THE SOFTWARE UNDER THE TERMS OF THAT
 * SOFTWARE LICENSE AGREEMENT INSTEAD OF THE TERMS OF THE APACHE LICENSE,
 * NOTWITHSTANDING THE ABOVE NOTICE.  IF YOU HAVE QUESTIONS, OR WISH TO REQUEST
 * A COPY OF THE ALTERNATE LICENSING TERMS OFFERED BY BEYONDTRUST, PLEASE CONTACT
 * BEYONDTRUST AT beyondtrust.com/contact
 */

/**
 * Copyright (C) BeyondTrust Software. All rights reserved.
 *
 * @file
 *
 *     lsadmengine.c
 *
 * @brief
 *
 *     LSASS Special Domain Name/SID Utilities
 *
 * @details
 *
 *     This module has some helper routines for dealing with
 *     special domain names and SIDs.
 *
 * @author Danilo Almeida (dalmeida@likewise.com)
 *
 */

#include "specialdomain.h"
#include <strings.h>

BOOLEAN
AdIsSpecialDomainName(
    IN PCSTR pszDomainName
    )
{
    return (!strcasecmp(pszDomainName, "BUILTIN") ||
            !strcasecmp(pszDomainName, "NT AUTHORITY"));
}

// Prefix for standard (not system, built-in, etc) accounts.
#define NT_NON_UNIQUE_SID_PREFIX "S-1-5-21-"

BOOLEAN
AdIsSpecialDomainSidPrefix(
    IN PCSTR pszObjectSid
    )
{
    // The NT non-unique SID prefix (S-1-5-21) is the prefix used
    // for standard accounts.
    return !strncasecmp(pszObjectSid, NT_NON_UNIQUE_SID_PREFIX, sizeof(NT_NON_UNIQUE_SID_PREFIX)-1) ? FALSE : TRUE;
}
