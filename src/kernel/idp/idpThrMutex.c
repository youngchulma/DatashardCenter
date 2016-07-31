/* Copyright 1999-2013 ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#include <idpThrMutex.h>

IDS_RC idpThrMutexCreate( IDP_ThrMutex *aMutex, IDS_SInt aFlag )
{
    pthread_mutexattr_t sAttr;
    IDS_RC sRc;

#define IDS_RETURN_IF_ERROR(aRet, aCleanup) \
    do                                      \
    {                                       \
        if ( (aRet) != 0 )                  \
        {                                   \
            aCleanup;                       \
            return (aRet);                  \
        }                                   \
        else                                \
        {                                   \
            /* DO NOTHING */                \
        }                                   \
    } while (0)

    if ( aFlag != IDP_THR_MUTEX_DEFAULT )
    {
        sRc = pthread_mutexattr_init(&sAttr);

        IDS_RETURN_IF_ERROR(sRc, );

        switch (aFlag)
        {
            case IDP_THR_MUTEX_ERRORCHECK:
            {
                sRc = pthread_mutexattr_settype(&sAttr, PTHREAD_MUTEX_ERRORCHECK);
                break;
            }
            case IDP_THR_MUTEX_RECURSIVE:
            {
                sRc = pthread_mutexattr_settype(&sAttr, PTHREAD_MUTEX_RECURSIVE);
                break;
            }
            default:
            {
                sRc = EINVAL;
                break;
            }
        }

        IDS_RETURN_IF_ERROR(sRc, (void)pthread_mutexattr_destroy(&sAttr));

        sRc = pthread_mutex_init(&aMutex->mMutex, &sAttr);
        (void)pthread_mutexattr_destroy(&sAttr);
    }
    else
    {
        sRc = pthread_mutex_init(&aMutex->mMutex, NULL);
    }

    return sRc;

#undef IDS_RETURN_IF_ERROR

}
