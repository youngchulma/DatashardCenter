/***********************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#if !defined(_O_DKP_THREAD_H_)
#define _O_DKP_THREAD_H_ 1

#include <dkpTypes.h>
#include <dkpError.h>
#include <dkpException.h>

#define DKP_THREAD_STACK_SIZE (0x10000)

/* thread attribute object */
typedef struct DKP_Thr_Attr
{
    pthread_attr_t mAttr;
} DKP_Thr_Attr;

/* thread function */
typedef DKP_SInt DKP_Thr_Func(void *);

/* thread once function */
typedef DKP_SInt DKP_Thr_Once_Func(void *);

/* thread object */
typedef struct DKP_Thr
{
    pthread_t mHandle;
} DKP_Thr;

typedef volatile enum
{
	DKP_THR_ONCE_INIT = 0,
	DKP_THR_ONCE_WAIT,
	DKP_THR_ONCE_DONE
} DKP_Thr_Once;

/* create thread attribute object */
DKP_INLINE DKP_RC dkpThrAttrCreate(DKP_Thr_Attr *aAttr)
{
	return pthread_attr_init(&aAttr->mAttr);
}

/* destroys thread attribute object */
DKP_INLINE DKP_RC dkpThrAttrDestroy(DKP_Thr_Attr *aAttr)
{
	return pthread_attr_destroy(&aAttr->mAttr);
}

/* sets thread bound mode to the thread attribute object */
DKP_INLINE DKP_RC dkpThrAttrSetScope(DKP_Thr_Attr *aAttr, DKP_Bool aFlag)
{
	return pthread_attr_setscope(&aAttr->mAttr,
                                (aFlag == DKP_TRUE) ? PTHREAD_SCOPE_SYSTEM : PTHREAD_SCOPE_PROCESS);
}

/* sets thread stack size to the thread attribute object */
DKP_RC dkpThrAttrSetStackSize(DKP_Thr_Attr *aAttr, DKP_Size aStackSize)
{
	return pthread_attr_setstacksize(&aAttr->mAttr, aStackSize);
}

/* create a new thread */
DKP_RC dkpThrCreate( DKP_Thr      *aThr,
                     DKP_Thr_Attr *aAttr,
                     DKP_Thr_Func *aFunc,
                     void         *aArg );

/* detaches a thread */
DKP_INLINE DKP_RC dkpThrDetach( DKP_Thr *aThr )
{
	return pthread_detach(aThr->mHandle);
}

/* joins a thread */
DKP_INLINE DKP_RC dkpThrJoin( DKP_Thr *aThr, DKP_SInt *aRet )
{
	DKP_RC sRc;
	void *sExitCode = NULL;

	sRc = pthread_join(aThr->mHandle, &sExitCode);

	if ( sExitCode != NULL )
	{
		*aRet = (dkp_sint32)(dkp_uint64)sExitCode;
	}
	else
	{
		/* DO NOTHING */
	}
	
	return sRc;
}

/* terminates current thread */
DKP_INLINE void dkpThrExit( DKP_SInt aExitCode )
{
	pthread_exit((void*)(dkp_uint64)aExitCode);
}

/* gets thread id of a thread */
DKP_INLINE DKP_RC dkpThrGetID( DKP_Thr *aThr, DKP_ULong *aID )
{
	*aID = (dkp_uint64)aThr->mHandle;
	return DKP_SUCCESS;
}

/* gets thread id of current thread */
DKP_INLINE dkp_uint64 dkpThrGetSelfID(void)
{
	return (dkp_uint64)pthread_self();
}

#endif /* _O_DKP_THREAD_H_ */
