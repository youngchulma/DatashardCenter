/* Copyright 1999-2013 ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id: dkpThrMutex.c 34 2016-07-29 09:57:09Z randyma $
 **********************************************************************/

#include <dkpThrMutex.h>

DKP_RC dkpThrMutexCreate( DKP_Thr_Mutex *aMutex, DKP_SInt aFlag )
{
    pthread_mutexattr_t sAttr;
    DKP_RC              sRc;

#define DKP_RETURN_IF_ERROR(aRc, aCleanup)     \
    do                                          \
    {                                           \
        if ((aRc) != 0)                         \
        {                                       \
            aCleanup ;                          \
                                                \
            return (aRc);                       \
        }                                       \
        else                                    \
        {                                       \
        }                                       \
    } while (0)

    if ( aFlag != DKP_THR_MUTEX_DEFAULT )
    {
        sRc = pthread_mutexattr_init(&sAttr);

        DKP_RETURN_IF_ERROR(sRc, );

        switch (aFlag)
        {
            case DKP_THR_MUTEX_ERRORCHECK:
			{
                sRc = pthread_mutexattr_settype(&sAttr,
                                                PTHREAD_MUTEX_ERRORCHECK);
                break;
			}
            case DKP_THR_MUTEX_RECURSIVE:
			{
                sRc = pthread_mutexattr_settype(&sAttr,
                                                PTHREAD_MUTEX_RECURSIVE);
                break;
			}
            default:
			{
                sRc = EINVAL;
                break;
			}
        }

        DKP_RETURN_IF_ERROR(sRc, (void)pthread_mutexattr_destroy(&sAttr));

        sRc = pthread_mutex_init(&aMutex->mMutex, &sAttr);

        (void)pthread_mutexattr_destroy(&sAttr);
    }
    else
    {
        sRc = pthread_mutex_init(&aMutex->mMutex, NULL);
    }

    return sRc;

#undef DKP_RETURN_IF_ERROR
}
