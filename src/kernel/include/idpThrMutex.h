/***********************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#if !defined(_O_IDP_THR_MUTEX_H_)
#define _O_IDP_THR_MUTEX_H_ 1

#include <idsTypes.h>
#include <idsError.h>
#include <idsException.h>

/* flag for mutex attribute */
#define IDP_THR_MUTEX_DEFAULT    (0)
/* error check mutex */
#define IDP_THR_MUTEX_ERRORCHECK (1)
/* recursive mutex */
#define IDP_THR_MUTEX_RECURSIVE  (2)

/* thread mutex initializer */
#define IDP_THR_MUTEX_INITIALIZER { PTHREAD_MUTEX_INITIALIZER }

/* thread mutex object */
typedef struct IDP_ThrMutex
{
    pthread_mutex_t mMutex;
} IDP_ThrMutex;

/* create a thread mutex */
IDS_RC idpThrMutexCreate( IDP_ThrMutex *aMutex, IDS_SInt aFlag );

/* destroys a thread mutex */
IDS_INLINE IDS_RC idpThrMutexDestroy( IDP_ThrMutex *aMutex )
{
	return pthread_mutex_destroy(&aMutex->mMutex);
}

/* lock a thread mutex */
IDS_INLINE IDS_RC idpThrMutexLock( IDP_ThrMutex *aMutex )
{
	return pthread_mutex_lock(&aMutex->mMutex);
}

/* trys lock a thread mutex */
IDS_INLINE IDS_RC idpThrMutexTryLock( IDP_ThrMutex *aMutex )
{
	return pthread_mutex_trylock(&aMutex->mMutex);
}

/* unlock a thread mutex */
IDS_INLINE IDS_RC idsThrMutexUnLock( IDP_ThrMutex *aMutex )
{
	return pthread_mutex_unlock(&aMutex->mMutex);
}

#endif /* _O_IDP_THR_MUTEX_H_ */
