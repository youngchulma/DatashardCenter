/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_IDS_FILE_H_)
#define _O_IDS_FILE_H_ 1

#include <idsTime.h>

#define IDS_O_RDONLY O_RDONLY
#define IDS_O_WRONLY O_WRONLY
#define IDS_O_RDWR   O_RDWR
#define IDS_O_APPEND O_APPEND
#define IDS_O_CREAT  O_CREAT
#define IDS_O_TRUNC  O_TRUNC
#define IDS_O_EXCL   O_EXCL
#define IDS_O_SYNC   O_SYNC

/*
 * permission
 */
#define IDS_S_IRWXU  S_IRWXU
#define IDS_S_IRUSR  S_IRUSR
#define IDS_S_IWUSR  S_IWUSR
#define IDS_S_IXUSR  S_IXUSR
#define IDS_S_IRWXG  S_IRWXG
#define IDS_S_IRGRP  S_IRGRP
#define IDS_S_IWGRP  S_IWGRP
#define IDS_S_IXGRP  S_IXGRP
#define IDS_S_IRWXO  S_IRWXO
#define IDS_S_IROTH  S_IROTH
#define IDS_S_IWOTH  S_IWOTH
#define IDS_S_IXOTH  S_IXOTH

/*
 * whence to seek
 */
#define IDS_SEEK_SET SEEK_SET
#define IDS_SEEK_CUR SEEK_CUR
#define IDS_SEEK_END SEEK_END

/*
 * Pipe types
 */
#define IDS_PIPE_READ  0
#define IDS_PIPE_WRITE 1

/* file object */
typedef struct IDS_File
{
    ids_sint32 mHandle;
} IDS_File;

/* file types */
typedef enum IDS_FileType
{
    IDS_FILE_UNK = 0, /**< unknown file type */
    IDS_FILE_REG,     /**< regular file      */
    IDS_FILE_DIR,     /**< directory         */
    IDS_FILE_CHR,     /**< character device  */
    IDS_FILE_BLK,     /**< block device      */
    IDS_FILE_FIFO,    /**< named pipe, FIFO  */
    IDS_FILE_LNK,     /**< symbolic link     */
    IDS_FILE_SOCK     /**< socket file       */
} IDS_FileType;

/* file stat structure */
typedef struct IDS_Stat
{
    IDS_SInt     mPermission; /**< file permission             */
    IDS_FileType mType;       /**< file type                   */
    IDS_Offset   mSize;       /**< file size                   */
    IDS_Time     mAccessTime; /**< last accessed time          */
    IDS_Time     mModifyTime; /**< last modified time          */
    IDS_Time     mChangeTime; /**< last attribute changed time */
} IDS_Stat;

/*
IDS_INLINE acp_rc_t acpFileOpen(acp_file_t   *aFile,
                                acp_char_t   *aPath,
                                acp_sint32_t  aFlag,
                                acp_mode_t    aMode)
{
    acp_path_pool_t sPool;
    acp_char_t*     sPath = NULL;
    acp_rc_t        sRC;

    if (aPath == NULL)
    {
        sRC = IDS_RC_EFAULT;
    }
    else
    {
        acpPathPoolInit(&sPool);
        sPath = acpPathFull(aPath, &sPool);

        if(NULL == sPath)
        {
            sRC = IDS_RC_GET_OS_ERROR();
        }
        else
        {
            (void)umask(0);
            aFile->mHandle = open(sPath, aFlag, aMode);
            sRC = (aFile->mHandle == -1) ?
                IDS_RC_GET_OS_ERROR() : IDS_RC_SUCCESS;
        }

        acpPathPoolFinal(&sPool);
    }

    return sRC;
}
*/

/**
 * closes the file
 */
 /*
IDS_INLINE acp_rc_t acpFileClose(acp_file_t *aFile)
{
    acp_sint32_t sRet;

    sRet = close(aFile->mHandle);

    return (sRet != 0) ? IDS_RC_GET_OS_ERROR() : IDS_RC_SUCCESS;
}
*/
/**
 * reads data from the file
 */
 /*
IDS_INLINE acp_rc_t acpFileRead(acp_file_t *aFile,
                                void       *aBuffer,
                                acp_size_t  aSize,
                                acp_size_t *aReadSize)
{
    acp_ssize_t sRet;
    acp_rc_t    sRC;

    if (aSize == 0)
    {
        sRet = 0;
        sRC  = IDS_RC_SUCCESS;
    }
    else
    {
        if (aSize > (acp_size_t)IDS_SINT32_MAX)
        {
            return IDS_RC_EINVAL;
        }
        else
        {
            sRet = read(aFile->mHandle, aBuffer, aSize);

            if (sRet == -1)
            {
                return IDS_RC_GET_OS_ERROR();
            }
            else if (sRet == 0)
            {
                sRC = IDS_RC_EOF;
            }
            else
            {
                sRC = IDS_RC_SUCCESS;
            }
        }
    }

    if (aReadSize != NULL)
    {
        *aReadSize = (acp_size_t)sRet;
    }
    else
    {
    }

    return sRC;
}
*/
/**
 * writes data to the file
 */
 /*
IDS_INLINE acp_rc_t acpFileWrite(acp_file_t *aFile,
                                 const void *aBuffer,
                                 acp_size_t  aSize,
                                 acp_size_t *aWrittenSize)
{
    acp_ssize_t sRet;

    if (aSize > (acp_size_t)IDS_SINT32_MAX)
    {
        return IDS_RC_EINVAL;
    }
    else
    {

        sRet = write(aFile->mHandle, aBuffer, aSize);

        if (sRet == -1)
        {
            return IDS_RC_GET_OS_ERROR();
        }
        else
        {
            if (aWrittenSize != NULL)
            {
                *aWrittenSize = (acp_size_t)sRet;
            }
            else
            {
            }

            return IDS_RC_SUCCESS;
        }
    }
}
*/
/**
 * moves the current location of the file
 */
 /*
IDS_INLINE acp_rc_t acpFileSeek(acp_file_t   *aFile,
                                acp_offset_t  aOffset,
                                acp_sint32_t  aWhence,
                                acp_offset_t *aAbsOffset)
{
    acp_offset_t sRet;

    sRet = lseek(aFile->mHandle, aOffset, aWhence);

    if (sRet == (acp_offset_t)-1)
    {
        return IDS_RC_GET_OS_ERROR();
    }
    else
    {
        if (aAbsOffset != NULL)
        {
            *aAbsOffset = sRet;
        }
        else
        {
        }

        return IDS_RC_SUCCESS;
    }
}
*/
/**
 * synchronizes the file's in-memory state  with  that  on the physical medium
 */
 /*
IDS_INLINE acp_rc_t acpFileSync(acp_file_t *aFile)
{
    acp_sint32_t sRet;

    sRet = fsync(aFile->mHandle);

    return (sRet != 0) ? IDS_RC_GET_OS_ERROR() : IDS_RC_SUCCESS;
}
*/
/**
 * truncates the file to @a aSize byte(s)
 */
/*
IDS_INLINE acp_rc_t acpFileTruncate(acp_file_t *aFile, acp_offset_t aSize)
{
    acp_sint32_t sRet;

    sRet = ftruncate(aFile->mHandle, aSize);

    return (sRet != 0) ? IDS_RC_GET_OS_ERROR() : IDS_RC_SUCCESS;
}
*/
/**
 * truncates the file at @a aPath to @a aSize byte(s)
 */
/*
IDS_INLINE acp_rc_t acpFileTruncateAtPath(acp_char_t *aPath, acp_offset_t aSize)
{
    acp_path_pool_t sPool;
    acp_sint32_t    sRet;
    acp_char_t*     sPath = NULL;
    acp_rc_t        sRC;

    if (aPath == NULL)
    {
        sRC = IDS_RC_EFAULT;
    }
    else
    {
        acpPathPoolInit(&sPool);
        sPath = acpPathFull(aPath, &sPool);

        if(NULL == sPath)
        {
            sRC = IDS_RC_GET_OS_ERROR();
        }
        else
        {
            sRet = truncate(sPath, aSize);
            sRC = (sRet != 0) ? IDS_RC_GET_OS_ERROR() : IDS_RC_SUCCESS;
        }

        acpPathPoolFinal(&sPool);
    }

    return sRC;
}
*/
/**
 * duplicates file object
 */
 /*
IDS_INLINE acp_rc_t acpFileDup(acp_file_t *aOldFile, acp_file_t *aNewFile)
{
    aNewFile->mHandle = dup(aOldFile->mHandle);

    return (aNewFile->mHandle == -1) ? IDS_RC_GET_OS_ERROR() : IDS_RC_SUCCESS;
}

IDS_EXPORT acp_rc_t acpFileCopy(acp_char_t  *aOldPath,
                                acp_char_t  *aNewPath,
                                acp_bool_t  aOverwrite);
*/
/**
 * renames the file
 */
 /*
IDS_INLINE acp_rc_t acpFileRename(acp_char_t *aOldPath, acp_char_t *aNewPath)
{
    acp_path_pool_t sPool;
    acp_sint32_t    sRet;
    acp_char_t*     sOldPath = NULL;
    acp_char_t*     sNewPath = NULL;
    acp_rc_t        sRC;

    if ((aOldPath == NULL) || (aNewPath == NULL))
    {
        return IDS_RC_EFAULT;
    }
    else
    {
        acpPathPoolInit(&sPool);
        sOldPath = acpPathFull(aOldPath, &sPool);

        if(NULL == sOldPath)
        {
            sRC = IDS_RC_GET_OS_ERROR();
        }
        else
        {
            sNewPath = acpPathFull(aNewPath, &sPool);

            if(NULL == sNewPath)
            {
                sRC = IDS_RC_GET_OS_ERROR();
            }
            else
            {
                sRet = rename(sOldPath, sNewPath);
                sRC = (sRet != 0) ? IDS_RC_GET_OS_ERROR() : IDS_RC_SUCCESS;
            }
        }

        acpPathPoolFinal(&sPool);
    }

    return sRC;
}
*/
/**
 * removes the file
 */
 /*
IDS_INLINE acp_rc_t acpFileRemove(acp_char_t *aPath)
{
    acp_path_pool_t sPool;
    acp_sint32_t    sRet;
    acp_char_t*     sPath = NULL;
    acp_rc_t        sRC;

    if (aPath == NULL)
    {
        sRC = IDS_RC_EFAULT;
    }
    else
    {
        acpPathPoolInit(&sPool);
        sPath = acpPathFull(aPath, &sPool);

        if(NULL == sPath)
        {
            sRC = IDS_RC_GET_OS_ERROR();
        }
        else
        {
            sRet = unlink(sPath);
            sRC = (sRet != 0) ? IDS_RC_GET_OS_ERROR() : IDS_RC_SUCCESS;
        }

        acpPathPoolFinal(&sPool);
    }

    return sRC;
}
*/
/**
 * generates the System V IPC key with file path and project id
 */
/*
IDS_INLINE acp_rc_t acpFileGetKey(
    acp_char_t*  aPath,
    acp_sint32_t aProj,
    acp_key_t*   aKey)
{
    if (aProj == 0)
    {
        return IDS_RC_ENOTSUP;
    }
    else
    {
        *aKey = ftok(aPath, aProj);
        return (-1 == (*aKey))? IDS_RC_GET_OS_ERROR() : IDS_RC_SUCCESS;
    }
}
*/
/**
 * create pipe
 */
 /*
IDS_INLINE acp_rc_t acpFilePipe(acp_file_t aPipe[])
{
    acp_rc_t sRC = IDS_RC_SUCCESS;
    acp_sint32_t sPipe[2];
    acp_sint32_t sRet;

    sRet = pipe(sPipe);
    IDS_TEST_RAISE(-1 == sRet, PIPE_CREATE_FAILED);

    aPipe[IDS_PIPE_READ].mHandle = sPipe[IDS_PIPE_READ];
    aPipe[IDS_PIPE_WRITE].mHandle = sPipe[IDS_PIPE_WRITE];

    return sRC;

    IDS_EXCEPTION(PIPE_CREATE_FAILED)
    {
        sRC = IDS_RC_GET_OS_ERROR();
    }

    IDS_EXCEPTION_END;

    return sRC;
}

IDS_EXPORT acp_rc_t acpFileLock(acp_file_t *aFile);
IDS_EXPORT acp_rc_t acpFileTryLock(acp_file_t *aFile);
IDS_EXPORT acp_rc_t acpFileUnlock(acp_file_t *aFile);

IDS_EXPORT acp_rc_t acpFileStat(acp_file_t *aFile, acp_stat_t *aStat);
IDS_EXPORT acp_rc_t acpFileStatAtPath(acp_char_t  *aPath,
                                      acp_stat_t *aStat,
                                      acp_bool_t  aTraverseLink);

*/
#endif
