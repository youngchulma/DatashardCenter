/***********************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#if !defined(_O_DKP_THR_MUTEX_H_)
#define _O_DKP_THR_MUTEX_H_ 1

#include <dkpTypes.h>
#include <dkpError.h>
#include <dkpException.h>

/* flag for mutex attribute */
#define DKP_THR_MUTEX_DEFAULT    (0)

/* error check mutex */
#define DKP_THR_MUTEX_ERRORCHECK (1)

/* recursive mutex */
#define DKP_THR_MUTEX_RECURSIVE  (2)

/* thread mutex object */
typedef struct DKP_Thr_Mutex
{
    pthread_mutex_t mMutex;
} DKP_Thr_Mutex;

/* create a thread mutex */
DKP_RC dkpThrMutexCreate( DKP_Thr_Mutex *aMutex, DKP_SInt aFlag );

/* destroys a thread mutex */
DKP_INLINE DKP_RC dkpThrMutexDestroy( DKP_Thr_Mutex *aMutex )
{
	return pthread_mutex_destroy(&aMutex->mMutex);
}

/* lock a thread mutex */
DKP_INLINE DKP_RC dkpThrMutexLock( DKP_Thr_Mutex *aMutex )
{
	return pthread_mutex_lock(&aMutex->mMutex);
}

/* trys lock a thread mutex */
DKP_INLINE DKP_RC dkpThrMutexTryLock( DKP_Thr_Mutex *aMutex )
{
	return pthread_mutex_trylock(&aMutex->mMutex);
}

/* unlock a thread mutex */
DKP_INLINE DKP_RC dkpThrMutexUnLock( DKP_Thr_Mutex *aMutex )
{
	return pthread_mutex_unlock(&aMutex->mMutex);
}

#endif /* _O_DKP_THR_MUTEX_H_ */
