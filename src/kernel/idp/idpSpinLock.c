/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id:
 ******************************************************************************/

#include <idpSpinLock.h>

IDS_Bool idpSpinLockTryLock( IDP_SpinLock *aLock )
{
    IDS_SInt sVal;
    
    sVal = idpAtomicCas64(&aLock->mLock, 0, 1);

    return (sVal != 0) ? IDS_TRUE : IDS_FALSE;
} 
