/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_DKP_SPIN_LOCK_H_)
#define _O_DKP_SPIN_LOCK_H_ 1

#include <dkpSpinWait.h>
#include <dkpThread.h>

/*
 * spinlock object
 */
typedef struct DKP_SpinLock
{
    volatile dkp_sint32    mLock;
    dkp_sint32             mSpinCount;
} DKP_SpinLock;


#define ACP_SPIN_LOCK_INITIALIZER(aSpinCount) { 1, (aSpinCount) }

/**
 * initializes a spinlock
 */
DKP_INLINE void dkpSpinLockInit( DKP_SpinLock *aLock, DKP_SInt aSpinCount)
{
    aLock->mLock = 1;
    aLock->mSpinCount = aSpinCount;
}

/**
 * trys a lock for a spinlock object
 */
DKP_Bool dkpSpinLockTryLock( DKP_SpinLock *aLock );

/**
 * returns a lock state of a spinlock object
 */
DKP_INLINE DKP_Bool dkpSpinLockIsLocked( DKP_SpinLock *aLock )
{
    return (aLock->mLock == 0) ? DKP_TRUE : DKP_FALSE;
}

/**
 * locks a spinlock
 */
DKP_INLINE void dkpSpinLockLock( DKP_SpinLock *aLock )
{
    dkp_sint32 sSpinLoop;
    dkp_sint32 sSpinCount;
    dkp_uint32 sSpinSleepTime;
    dkp_bool sIsMyLock;

    /* set up conditions */
    //sSpinSleepTime = ACP_SPIN_WAIT_SLEEP_TIME_MIN;
    sIsMyLock = DKP_FALSE;

    if (aLock->mSpinCount < 0)
    {
     //   sSpinCount = acpSpinWaitGetDefaultSpinCount();
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
            if (dkpSpinLockIsLocked(aLock) == DKP_FALSE)
            {
                if (dkpSpinLockTryLock(aLock) == DKP_TRUE)
                {
                    sIsMyLock = DKP_TRUE;
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
    
        if (sIsMyLock == DKP_TRUE)
        {
            break;
        }
        else
        {
            dkpSleepUsec(sSpinSleepTime);
        }

        if (sSpinSleepTime < DKP_SPIN_WAIT_SLEEP_TIME_MAX)
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

#endif /* _O_DKP_SPIN_LOCK_H_ */

