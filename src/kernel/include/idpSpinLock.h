/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_IDP_SPIN_LOCK_H_)
#define _O_IDP_SPIN_LOCK_H_ 1

#include <idpThr.h>
#include <idpAtomic.h>
#include <idpSpinWait.h>

/* spinlock object */
typedef struct IDP_SpinLock
{
    volatile IDS_SInt mLock;
    IDS_SInt          mSpinCount;
} IDP_SpinLock;

#define ACP_SPIN_LOCK_INITIALIZER(aSpinCount) { 1, (aSpinCount) }

/* initializes a spinlock */
IDS_INLINE void idpSpinLockInit( IDP_SpinLock *aLock, IDS_SInt aSpinCount )
{
    aLock->mLock = 1;
    aLock->mSpinCount = aSpinCount;
}

/* trys a lock for a spinlock object */
IDS_Bool idpSpinLockTryLock( IDP_SpinLock *aLock );

/* returns a lock state of a spinlock object */
IDS_INLINE IDS_Bool idpSpinLockIsLocked( IDP_SpinLock *aLock )
{
    return (aLock->mLock == 0) ? IDS_TRUE : IDS_FALSE;
}

/* locks a spinlock */
IDS_INLINE void idpSpinLockLock( IDP_SpinLock *aLock )
{
    IDS_SInt sSpinLoop;
    IDS_SInt sSpinCount;
    IDS_UInt sSpinSleepTime;
    IDS_Bool sIsMyLock;

    /* set up conditions */
    sSpinSleepTime = IDP_SPIN_WAIT_SLEEP_TIME_MIN;
    sIsMyLock = IDS_FALSE;

    if (aLock->mSpinCount < 0)
    {
        sSpinCount = idpSpinWaitGetDefaultSpinCount();
    }
    else
    {
        sSpinCount = aLock->mSpinCount;
    }

    while (1)
    {
        for (sSpinLoop = 0;
             sSpinLoop <= sSpinCount; /* sSpinCount can be 0 in UP! */
             sSpinLoop++)
        {
            if (idpSpinLockIsLocked(aLock) == IDS_FALSE)
            {
                if (idpSpinLockTryLock(aLock) == IDS_TRUE)
                {
                    sIsMyLock = IDS_TRUE;
                    break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                /* do loop */
            }
        }
    
        if (sIsMyLock == IDS_TRUE)
        {
            break;
        }
        else
        {
            idpSleepUsec(sSpinSleepTime);
        }

        if (sSpinSleepTime < IDP_SPIN_WAIT_SLEEP_TIME_MAX)
        {
            sSpinSleepTime *= 2;
        }
        else
        {
            /* reach maximum sleep time */
        }
    }

    return;
}

void idpSpinLockUnlock( IDP_SpinLock *aLock )
{
    (void)idpAtomicSet32(&(aLock->mLock), 1);
}

void idpSpinLockSetCount( IDP_SpinLock *aLock, IDS_SInt aSpinCount )
{
    aLock->mSpinCount = aSpinCount;
}

#endif /* _O_IDP_SPIN_LOCK_H_ */

