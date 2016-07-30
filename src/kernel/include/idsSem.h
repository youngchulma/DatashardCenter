/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_IDS_SEM_H_)
#define _O_IDS_SEM_H_ 1

#include <idsTypes.h>
#include <idsError.h>

/* semaphore object */
typedef struct IDS_Sem
{
    IDS_SInt mSemID;
} IDS_Sem;

IDS_RC idsSemCreate( IDS_Key aKey, IDS_SInt aValue );
IDS_RC idsSemDestroy( IDS_Key aKey );

IDS_RC idsSemOpen( IDS_Sem *aSem, IDS_Key aKey );
IDS_RC idsSemClose( IDS_Sem *aSem );

IDS_RC idsSemAcquire( IDS_Sem *aSem );
IDS_RC idsSemTryAcquire( IDS_Sem *aSem );
IDS_RC idsSemRelease( IDS_Sem *aSem );

#endif /* _O_IDS_SEM_H_ */
