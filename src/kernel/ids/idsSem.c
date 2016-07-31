/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#include <idsSem.h>

typedef union IDS_SemMutexCtl
{
    IDS_SInt        mVal;
    struct semid_ds *mBuf;
    IDS_UShort      *mArray;
} IDS_SemMutexCtl;

/* creates a semaphore */
IDS_RC idsSemCreate( IDS_Key aKey, IDS_SInt aValue )
{
    IDS_SemMutexCtl sCtl;

    IDS_SInt sSemID;
    IDS_SInt sRet;
    IDS_RC   sRc;

    IDS_TEST_RAISE( aKey == IPC_PRIVATE, ERR_EINVAL );

    sSemID = semget(aKey, 1, IPC_CREAT | IPC_EXCL | 0666);
    IDS_TEST_RAISE( sSemID == -1, ERR_GET );

    sCtl.mVal = aValue;

    sRet = semctl(sSemID, 0, SETVAL, sCtl);
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

        sCtl.mVal = 0;
        (void)semctl(sSemID, 0, IPC_RMID, sCtl);
    }
    IDS_EXCEPTION_END;

    return sRc;
}

/* destroys a semaphore
 * the process that created the semaphore must destroy it */
IDS_RC idsSemDestroy(IDS_Key aKey)
{
    IDS_SemMutexCtl sCtl;

    IDS_SInt sSemID;
    IDS_SInt sRet;
    IDS_RC   sRc;

    IDS_TEST_RAISE( aKey == IPC_PRIVATE, ERR_EINVAL );

    sSemID = semget(aKey, 1, 0666);
    IDS_TEST_RAISE( sSemID == -1, ERR_GET );
    
    sCtl.mVal = 0;

    sRet = semctl(sSemID, 0, IPC_RMID, sCtl);
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

/* opens a semphoare */
IDS_RC idsSemOpen( IDS_Sem *aSem, IDS_Key aKey )
{
    IDS_RC sRc;

    IDS_TEST_RAISE( aKey == IPC_PRIVATE, ERR_EINVAL );

    aSem->mSemID = semget(aKey, 1, 0666);
    IDS_TEST_RAISE( aSem->mSemID == -1, ERR_GET );

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

/* closes a semaphore */
IDS_RC idsSemClose( IDS_Sem *aSem )
{
    aSem->mSemID = -1;

    return IDS_RC_SUCCESS;
}

/* acquires a semaphore */
IDS_RC idsSemAcquire( IDS_Sem *aSem )
{
    struct sembuf sOp;
    IDS_SInt sRet;
    IDS_RC   sRc;

    sOp.sem_num = 0;
    sOp.sem_op  = -1;
    sOp.sem_flg = SEM_UNDO;

    while (1)
    {
        sRet = semop(aSem->mSemID, &sOp, 1);
        IDS_TEST( sRet == 0 );

        sRc = IDS_RC_GET_OS_ERROR();

        if ( IDS_RC_IS_EINTR(sRc) )
        {
            continue;
        }
        else
        {
            break;
        }
    }

    return sRc;

    IDS_EXCEPTION_END;

    return IDS_RC_SUCCESS;
}

/* trys to acquire a semaphore */
IDS_RC idsSemTryAcquire( IDS_Sem *aSem )
{
    struct sembuf sOp;
    IDS_SInt sRet;
    IDS_RC   sRc;

    sOp.sem_num = 0;
    sOp.sem_op  = -1;
    sOp.sem_flg = SEM_UNDO | IPC_NOWAIT;

    while (1)
    {
        sRet = semop(aSem->mSemID, &sOp, 1);
        IDS_TEST( sRet == 0 );

        sRc = IDS_RC_GET_OS_ERROR();

        if ( IDS_RC_IS_EINTR(sRc) )
        {
            continue;
        }
        else if ( IDS_RC_IS_EAGAIN(sRc) )
        {
            sRc = IDS_RC_EBUSY;
        }
        else
        {
            break;
        }
    }

    return sRc;

    IDS_EXCEPTION_END;

    return IDS_RC_SUCCESS;
}

/* releases a semaphore */
IDS_RC idsSemRelease( IDS_Sem *aSem )
{
    struct sembuf sOp;
    IDS_SInt sRet;
    IDS_RC   sRc;

    sOp.sem_num = 0;
    sOp.sem_op  = 1;
    sOp.sem_flg = SEM_UNDO;

    while (1)
    {
        sRet = semop(aSem->mSemID, &sOp, 1);
        IDS_TEST( sRet == 0 );

        sRc = IDS_RC_GET_OS_ERROR();

        if ( IDS_RC_IS_EINTR(sRc) )
        {
            continue;
        }
        else
        {
            break;
        }
    }

    return sRc;

    IDS_EXCEPTION_END;

    return IDS_RC_SUCCESS;
}

