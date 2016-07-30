/***********************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#if !defined(_O_IDP_THREAD_H_)
#define _O_IDP_THREAD_H_ 1

#include <idsTypes.h>
#include <idsError.h>
#include <idsException.h>

#define IDP_THREAD_STACK_SIZE (0x10000)

/* thread attribute object */
typedef struct IDP_Thr_Attr
{
    pthread_attr_t mAttr;
} IDP_Thr_Attr;

/* thread function */
typedef IDS_SInt IDP_Thr_Func(void *);

/* thread once function */
typedef IDS_SInt IDP_Thr_Once_Func(void *);

/* thread object */
typedef struct IDP_Thr
{
    pthread_t mHandle;
} IDP_Thr;

typedef volatile enum
{
	IDP_THR_ONCE_INIT = 0,
	IDP_THR_ONCE_WAIT,
	IDP_THR_ONCE_DONE
} IDP_Thr_Once;

/* create thread attribute object */
IDS_INLINE IDS_RC idpThrAttrCreate( IDP_Thr_Attr *aAttr )
{
	return pthread_attr_init(&aAttr->mAttr);
}

/* destroys thread attribute object */
IDS_INLINE IDS_RC idpThrAttrDestroy( IDP_Thr_Attr *aAttr )
{
	return pthread_attr_destroy(&aAttr->mAttr);
}

/* sets thread bound mode to the thread attribute object */
IDS_INLINE IDS_RC idpThrAttrSetScope( IDP_Thr_Attr *aAttr, IDS_Bool aFlag )
{
	return pthread_attr_setscope(&aAttr->mAttr,
                                (aFlag == IDS_TRUE) ? PTHREAD_SCOPE_SYSTEM : PTHREAD_SCOPE_PROCESS);
}

/* sets thread stack size to the thread attribute object */
IDS_RC idpThrAttrSetStackSize( IDP_Thr_Attr *aAttr, IDS_Size aStackSize)
{
	return pthread_attr_setstacksize(&aAttr->mAttr, aStackSize);
}

/* create a new thread */
IDS_RC idpThrCreate( IDP_Thr      *aThr,
                     IDP_Thr_Attr *aAttr,
                     IDP_Thr_Func *aFunc,
                     void         *aArg );

/* detaches a thread */
IDS_INLINE IDS_RC idpThrDetach( IDP_Thr *aThr )
{
	return pthread_detach(aThr->mHandle);
}

/* joins a thread */
IDS_INLINE IDS_RC idpThrJoin( IDP_Thr *aThr, IDS_SInt *aRet )
{
	IDS_RC sRc;
	void *sExitCode = NULL;

	sRc = pthread_join(aThr->mHandle, &sExitCode);

	if ( sExitCode != NULL )
	{
		*aRet = (IDS_SInt)(IDS_ULong)sExitCode;
	}
	else
	{
		/* DO NOTHING */
	}
	
	return sRc;
}

/* terminates current thread */
IDS_INLINE void idpThrExit( IDS_SInt aExitCode )
{
	pthread_exit((void*)(IDS_SLong)aExitCode);
}

/* gets thread id of a thread */
IDS_INLINE void idpThrGetID( IDP_Thr *aThr, IDS_ULong *aID )
{
	*aID = (IDS_ULong)aThr->mHandle;
}

/* gets thread id of current thread */
IDS_INLINE IDS_ULong idpThrGetSelfID(void)
{
	return (IDS_ULong)pthread_self();
}

#endif /* _O_IDP_THREAD_H_ */
