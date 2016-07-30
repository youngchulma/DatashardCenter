/***********************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#if !defined(_O_IDS_ERROR_H_)
#define _O_IDS_ERROR_H_ 1

#include <idsTypes.h>

/* Just support UNIX only */
#define IDS_GET_OS_ERROR() (errno)
#define IDS_SET_OS_ERROR(e) (errno = (e))

typedef enum IDSError
{
    IDS_SUCCESS = 0,
    IDS_FAILURE = 1,
    IDS_EINVAL = 2,
    IDS_EEXIST = 3,
    IDS_ENOENT = 4,
    IDS_ERANGE = 5,
    IDS_ACCESS_DENIED = 6,
    IDS_ETIMEOUT = 7,
    IDS_FOPEN_ERROR = 8,
    IDS_FREAD_ERROR = 9,
    IDS_FWRITE_ERROR = 10,
    IDS_FDELETE_ERROR = 11,
    IDS_NOT_RUNNING = 12,
    IDS_ENOMEM = 13,
    IDS_COMMUNICATION_ERROR = 14,
    IDS_INVALID_OPTIONS = 15,
    IDS_CONNECTION_REFUSED = 16,
    IDS_SERVER_BIND_ERROR = 17,
    IDS_SERVER_LISTEN_ERROR = 18,
    IDS_INVALID_SOCKET = 19,
    IDS_THREAD_CREATE_ERROR = 20,
    IDS_ETRUNC = 21,
    IDS_EOF = 22
} IDSError;

#endif /* _O_IDS_ERROR_H_ */
