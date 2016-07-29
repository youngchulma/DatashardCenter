/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#include <dkpSpinWait.h>
#include <dkpThread.h>

/* runs a function only once */
ACP_EXPORT void acpThrOnce(acp_thr_once_t      *aOnceControl,
                           acp_thr_once_func_t *aFunc)
{

    /* avoid duplication */
    ACP_TEST(*aOnceControl == ACP_THR_ONCE_DONE);


    if (acpAtomicCas32(aOnceControl,
                       ACP_THR_ONCE_WAIT,
                       ACP_THR_ONCE_INIT) == ACP_THR_ONCE_INIT)
    {
        (*aFunc)();

        *aOnceControl = ACP_THR_ONCE_DONE;
    }
    else
    {
        /*
 *          * wait until the other threads are finished
 *                   */
        ACP_SPIN_WAIT(*aOnceControl == ACP_THR_ONCE_DONE, 0);
    }


    return; /* explicitly exit */

    ACP_EXCEPTION_END;
    return; /* explicitly exit */
}

/* creates a thread */
DKP_RC dkpThrCreate( acp_thr_t      *aThr,
                                 acp_thr_attr_t *aAttr,
                                 acp_thr_func_t *aFunc,
                                 void           *aArg)
{
    acp_sint32_t sRet;

    sRet = pthread_create(&aThr->mHandle,
                          (aAttr != NULL) ? &aAttr->mAttr : NULL,
                          (void *(*)(void *))aFunc,
                          aArg);

    if (sRet == 0)
    {
        aThr->mFunc  = aFunc;
        aThr->mArg   = aArg;

        return ACP_RC_SUCCESS;
    }
    else
    {
        return ACP_RC_GET_OS_ERROR();
    }
}

#endif
