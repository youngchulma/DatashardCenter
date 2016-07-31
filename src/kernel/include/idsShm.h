/*******************************************************************************
 * Copyright 1999-2007, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_IDS_SHM_H_)
#define _O_IDS_SHM_H_ 1

#include <idsTypes.h>
#include <idsError.h>
#include <idsException.h>

/* shared memory object */
typedef struct IDS_Shm
{
    IDS_SInt mShmId;
    void    *mAddr;
    IDS_Size mSize;
} IDS_Shm;

IDS_RC idsShmCreate( IDS_Key aKey, 
                     IDS_Size aSize, 
                     IDS_Mode aPermission );
IDS_RC idsShmDestroy( IDS_Key aKey);

IDS_RC idsShmAttach( IDS_Shm *aShm, IDS_Key aKey );
IDS_RC idsShmDetach( IDS_Shm *aShm );

/* gets shared memory address */
IDS_INLINE void *idsShmGetAddress( IDS_Shm *aShm )
{
    return aShm->mAddr;
}

/* gets size of shared memory */
IDS_INLINE IDS_Size idsShmGetSize( IDS_Shm *aShm )
{
    return aShm->mSize;
}

#endif /* _O_IDS_SHM_H_ */
