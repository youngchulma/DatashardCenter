/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#include <idsShm.h>
#include <idsError.h>
#include <idsException.h>

/* creates a @a aSize byte(s) of shared memory at @a aPath */
IDS_RC idsShmCreate( IDS_Key aKey, IDS_Size aSize, IDS_Mode aPermission )
{
    IDS_SInt sShmID;

    //IDS_TEST_RAISE( aPermission != (aPermission & IDS_SHM_MAX_PERM), ERR_EINVAL );

    IDS_TEST_RAISE( aKey == IPC_PRIVATE, ERR_EINVAL );

    sShmID = shmget(aKey, aSize, IPC_CREAT | IPC_EXCL | aPermission);
    IDS_TEST( sShmID == -1 );

    return IDS_SUCCESS;

    IDS_EXCEPTION( ERR_EINVAL )
    {
        return 1;
    }
    IDS_EXCEPTION_END;

    return IDS_GET_OS_ERROR();
}

/* destroys the shared memory */
IDS_RC idsShmDestroy( IDS_Key aKey)
{
    IDS_SInt sShmID;
    IDS_SInt sRc;

    IDS_TEST_RAISE( aKey == IPC_PRIVATE, ERR_EINVAL );

    sShmID = shmget(aKey, 0, SHM_R | SHM_W);
    IDS_TEST( sShmID == -1 );

    sRc = shmctl(sShmID, IPC_RMID, NULL);
    IDS_TEST( sRc != 0 )

    return IDS_SUCCESS;

    IDS_EXCEPTION( ERR_EINVAL )
    {
        return IDS_EINVAL;
    }
    IDS_EXCEPTION_END;

    return IDS_GET_OS_ERROR();
}

/* attaches the shared memory */
IDS_RC idsShmAttach( IDS_Shm *aShm, IDS_Key aKey )
{
    struct shmid_ds sStat;
    IDS_SInt        sRet;
    IDS_RC          sRC;

    aShm->mShmId = shmget(aKey, 0, SHM_R | SHM_W);
    IDS_TEST( aShm->mShmId == -1 );

    aShm->mAddr = shmat(aShm->mShmId, NULL, 0);

    IDS_TEST_RAISE( (aShm->mAddr == (void *)-1), ERR_OS );
    
    sRet = shmctl(aShm->mShmId, IPC_STAT, &sStat);
    IDS_TEST_RAISE( sRet == -1, ERR_OS1 );
    
    aShm->mSize = sStat.shm_segsz;

    return IDS_SUCCESS;

    IDS_EXCEPTION( ERR_OS )
    {
        aShm->mAddr = NULL;
    }
    IDS_EXCEPTION( ERR_OS1 )
    {
        sRC = IDS_GET_OS_ERROR();
        (void)shmdt(aShm->mAddr);
        return sRC;
    }
    IDS_EXCEPTION_END;

    return IDS_GET_OS_ERROR();
}

/* detaches the shared memory */
IDS_RC idsShmDetach( IDS_Shm *aShm )
{
    IDS_RC sRc;

    sRc = shmdt(aShm->mAddr);
    IDS_TEST( sRc == -1 );
    
    return IDS_SUCCESS;

    IDS_EXCEPTION_END;

    return IDS_GET_OS_ERROR();
}
