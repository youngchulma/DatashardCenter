/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_IDP_THR_COND_H_)
#define _O_DIP_THR_COND_H_

#include <idsTypes.h>
#include <idpTime.h>
#include <idpThrMutex.h>
#include <idpSpinLock.h>

/* thread conditional variable object */
typedef struct IDP_ThrCond
{
    pthread_cond_t mCond;
} IDP_ThrCond;


/* creates a thread condition variable */
IDS_INLINE IDS_RC acpThrCondCreate( IDP_ThrCond *aCond )
{
    return pthread_cond_init(&aCond->mCond, NULL);
}

/* destroys a thread condition variable */
IDS_INLINE IDS_RC acpThrCondDestroy(IDP_ThrCond *aCond)
{
    return pthread_cond_destroy(&aCond->mCond);
}

/* waits for a thread condition variable */
IDS_INLINE IDS_RC acpThrCondWait( IDP_ThrCond *aCond, IDP_ThrMutex *aMutex )
{
    return pthread_cond_wait(&aCond->mCond, &aMutex->mMutex);
}

/* waits for a thread condition variable with timeout */
IDS_INLINE IDS_RC acpThrCondTimedWait( IDP_ThrCond  *aCond,
                                       IDP_ThrMutex *aMutex,
                                       IDP_Time      aTimeout,
                                       IDP_TimeType  aTimeoutType )
{
    struct timespec sTime;

    if ( aTimeoutType == IDP_TIME_REL )
    {
        aTimeout += acpTimeNow();
    }
    else
    {
        /* do nothing */
    }

    sTime.tv_sec  = (acp_slong_t)idpTimeToSec(aTimeout);
    sTime.tv_nsec = (acp_slong_t)idpTimeGetUsec(aTimeout) * 1000;

    return pthread_cond_timedwait(&aCond->mCond, &aMutex->mMutex, &sTime);
}

/* signals a thread condition variable */
IDS_INLINE IDS_RC acpThrCondSignal( IDP_ThrCond *aCond )
{
    return pthread_cond_signal(&aCond->mCond);
}

/* broadcasts a thread condition variable */
IDS_INLINE IDS_RC acpThrCondBroadcast( IDP_ThrCond *aCond )
{
    return pthread_cond_broadcast(&aCond->mCond);
}

#endif
