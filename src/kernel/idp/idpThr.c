/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#include <idpThr.h>
#include <idpSpinWait.h>

/* creates a thread */

IDS_RC idpThrCreate( IDP_Thr *aThr, 
                     IDP_ThrAttr *aAttr, 
                     IDP_ThrFunc *aFunc, 
                     void *aArg )
{
    IDS_SInt sRc;

    sRc = pthread_create(&aThr->mHandle,
                         (aAttr != NULL) ? &aAttr->mAttr : NULL,
                         (void *(*)(void *))aFunc,
                         aArg );
    IDS_TEST( sRc != 0 );

    return IDS_RC_SUCCESS;

    IDS_EXCEPTION_END;

    return IDS_RC_GET_OS_ERROR();
}

IDS_RC idpThrOnce( IDP_ThrOnce *aThrOnceCtrl, IDP_ThrOnceFunc *aFunc )
{
    return IDS_RC_SUCCESS;
}
