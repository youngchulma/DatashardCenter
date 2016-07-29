/***********************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#if !defined(_O_DKP_ERROR_H_)
#define _O_DKP_ERROR_H_ 1

#include <dkpTypes.h>

/* Just support UNIX only */
#define DKP_GET_NET_ERROR()  (errno)
#define DKP_SET_NET_ERROR(e) (errno = (e))

#define DKP_GET_SYS_ERROR()  (errno)
#define DKP_SET_SYS_ERROR(e) (errno = (e))

typedef enum DKPError
{
    DKP_SUCCESS = 0,
    DKP_FAILURE = 1,
    DKP_EINVAL = 2,
    DKP_EEXIST = 3,
    DKP_ENOENT = 4,
    DKP_ERANGE = 5,
    DKP_ACCESS_DENIED = 6,
    DKP_ETIMEOUT = 7,
    DKP_FOPEN_ERROR = 8,
    DKP_FREAD_ERROR = 9,
    DKP_FWRITE_ERROR = 10,
    DKP_FDELETE_ERROR = 11,
    DKP_NOT_RUNNING = 12,
    DKP_ENOMEM = 13,
    DKP_COMMUNICATION_ERROR = 14,
    DKP_INVALID_OPTIONS = 15,
    DKP_CONNECTION_REFUSED = 16,
    DKP_SERVER_BIND_ERROR = 17,
    DKP_SERVER_LISTEN_ERROR = 18,
    DKP_INVALID_SOCKET = 19,
    DKP_THREAD_CREATE_ERROR = 20,
    DKP_ETRUNC = 21,
    DKP_EOF = 22
} DKPError;

#endif /* _O_DKP_ERROR_H_ */
