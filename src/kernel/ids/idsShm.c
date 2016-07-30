/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#include <idsShm.h>
#include <idsFile.h>
#include <idsException.h>

#define IDS_SHM_MAX_PERM    (   \
    IDS_S_IRUSR | IDS_S_IWUSR | \
    IDS_S_IRGRP | IDS_S_IWGRP | \
    IDS_S_IROTH | IDS_S_IWOTH )

/* creates a @a aSize byte(s) of shared memory at @a aPath */
IDS_RC idsShmCreate( IDS_Key aKey, 
                     IDS_Size aSize, 
                     IDS_Mode aPermission )
{
    IDS_SInt sShmID;
    IDS_RC   sRc;

    IDS_TEST_RAISE( aPermission != (aPermission & IDS_SHM_MAX_PERM), ERR_EINVAL );

    IDS_TEST_RAISE( aKey == IPC_PRIVATE, ERR_EINVAL );

    sShmID = shmget(aKey, aSize, IPC_CREAT | IPC_EXCL | aPermission);
    IDS_TEST_RAISE( sShmID == -1, ERR_GET );

    return IDS_RC_SUCCESS;

    IDS_EXCEPTION( ERR_EINVAL )
    {
        sRc = IDS_RC_EINVAL;
    }
    IDS_EXCEPTION( ERR_GET )
    {
        sRc = IDS_RC_GET_OS_ERROR();
    }
    IDS_EXCEPTION_END;

    return sRc;
}

/* destroys the shared memory */
IDS_RC idsShmDestroy( IDS_Key aKey )
{
    IDS_SInt sShmID;
    IDS_SInt sRet;
    IDS_RC   sRc;

    IDS_TEST_RAISE( aKey == IPC_PRIVATE, ERR_EINVAL );

    sShmID = shmget(aKey, 0, SHM_R | SHM_W);
    IDS_TEST_RAISE( sShmID == -1, ERR_GET );

    sRet = shmctl(sShmID, IPC_RMID, NULL);
    IDS_TEST_RAISE( sRet != 0, ERR_CONTROL );

    return IDS_RC_SUCCESS;

    IDS_EXCEPTION( ERR_EINVAL )
    {
        sRc = IDS_RC_EINVAL;
    }
    IDS_EXCEPTION( ERR_GET )
    {
        sRc = IDS_RC_GET_OS_ERROR();
    }
    IDS_EXCEPTION( ERR_CONTROL )
    {
        sRc = IDS_RC_GET_OS_ERROR();
    }
    IDS_EXCEPTION_END;

    return sRc;
}

/* attaches the shared memory */
IDS_RC idsShmAttach( IDS_Shm *aShm, IDS_Key aKey )
{
    struct shmid_ds sStat;
    IDS_SInt        sRet;
    IDS_RC          sRc;

    aShm->mShmId = shmget(aKey, 0, SHM_R | SHM_W);
    IDS_TEST_RAISE( aShm->mShmId == -1, ERR_GET );

    aShm->mAddr = shmat(aShm->mShmId, NULL, 0);
    IDS_TEST_RAISE( aShm->mAddr == (void *)-1, ERR_ATTACH );
    
    sRet = shmctl(aShm->mShmId, IPC_STAT, &sStat);
    IDS_TEST_RAISE( sRet == -1, ERR_CONTROL );
    
    aShm->mSize = sStat.shm_segsz;

    return IDS_RC_SUCCESS;

    IDS_EXCEPTION( ERR_GET )
    {
        sRc = IDS_RC_GET_OS_ERROR();
    }
    IDS_EXCEPTION( ERR_ATTACH )
    {
        aShm->mAddr = NULL;
        sRc = IDS_RC_GET_OS_ERROR();
    }
    IDS_EXCEPTION( ERR_CONTROL )
    {
        sRc = IDS_RC_GET_OS_ERROR();
        (void)shmdt(aShm->mAddr);
    }
    IDS_EXCEPTION_END;

    return sRc;
}

/* detaches the shared memory */
IDS_RC idsShmDetach( IDS_Shm *aShm )
{
    IDS_RC sRc;

    sRc = shmdt(aShm->mAddr);
    IDS_TEST( sRc == -1 );
    
    return IDS_RC_SUCCESS;

    IDS_EXCEPTION_END;

    return IDS_RC_GET_OS_ERROR();
}
