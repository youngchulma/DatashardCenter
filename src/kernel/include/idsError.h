/***********************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#if !defined(_O_IDS__ERROR_H_)
#define _O_IDS__ERROR_H_ 1

#include <idsTypes.h>

#define IDS_RC_CONVERT(e)        (e)
#define IDS_RC_REVERT(e)         (e)
#define IDS_RC_FROM_SYS_ERROR(e) (e)
#define IDS_RC_TO_SYS_ERROR(e)   (e)

/* Just support UNIX only */
#define IDS_RC_GET_OS_ERROR() (errno)
#define IDS_RC_SET_OS_ERROR(e) (errno = (e))

#define IDS_RC_GET_NET_ERROR() (errno)
#define IDS_RC_SET_NET_ERROR(e) (errno = (e))

/* range of error code */
#define IDS_RC_RR_STD      0
#define IDS_RC_RR_WIN  20000
#define IDS_RC_RR_IDS  60000
#define IDS_RC_RR_APP 100000

/* IDS error code definition */
#define IDS_RC_SUCCESS           0
#define IDS_RC_EINVAL            (IDS_RC_RR_IDS + 1)
#define IDS_RC_EINTR             (IDS_RC_RR_IDS + 2)
#define IDS_RC_ESRCH             (IDS_RC_RR_IDS + 3)
#define IDS_RC_ENAMETOOLONG      (IDS_RC_RR_IDS + 4)
#define IDS_RC_EEXIST            (IDS_RC_RR_IDS + 5)
#define IDS_RC_ENOENT            (IDS_RC_RR_IDS + 6)
#define IDS_RC_ENOTEMPTY         (IDS_RC_RR_IDS + 7)
#define IDS_RC_ERANGE            (IDS_RC_RR_IDS + 8)
#define IDS_RC_EBUSY             (IDS_RC_RR_IDS + 9)
#define IDS_RC_EDEADLK           (IDS_RC_RR_IDS + 10)
#define IDS_RC_EPERM             (IDS_RC_RR_IDS + 11)
#define IDS_RC_EACCES            (IDS_RC_RR_IDS + 12)
#define IDS_RC_EAGAIN            (IDS_RC_RR_IDS + 13)
#define IDS_RC_EINPROGRESS       (IDS_RC_RR_IDS + 14)
#define IDS_RC_ETIMEDOUT         (IDS_RC_RR_IDS + 15)
#define IDS_RC_EBADF             (IDS_RC_RR_IDS + 16)
#define IDS_RC_ENOTDIR           (IDS_RC_RR_IDS + 17)
#define IDS_RC_ENOTSOCK          (IDS_RC_RR_IDS + 18)
#define IDS_RC_ENOSPC            (IDS_RC_RR_IDS + 19)
#define IDS_RC_ENOMEM            (IDS_RC_RR_IDS + 20)
#define IDS_RC_EMFILE            (IDS_RC_RR_IDS + 21)
#define IDS_RC_ENFILE            (IDS_RC_RR_IDS + 22)
#define IDS_RC_ESPIPE            (IDS_RC_RR_IDS + 23)
#define IDS_RC_EPIPE             (IDS_RC_RR_IDS + 24)
#define IDS_RC_ECONNREFUSED      (IDS_RC_RR_IDS + 25)
#define IDS_RC_ECONNABORTED      (IDS_RC_RR_IDS + 26)
#define IDS_RC_ECONNRESET        (IDS_RC_RR_IDS + 27)
#define IDS_RC_EHOSTUNREACH      (IDS_RC_RR_IDS + 28)
#define IDS_RC_ENETUNREACH       (IDS_RC_RR_IDS + 29)
#define IDS_RC_EXDEV             (IDS_RC_RR_IDS + 30)
#define IDS_RC_ENOTSUP           (IDS_RC_RR_IDS + 31)
#define IDS_RC_ENOIMPL           (IDS_RC_RR_IDS + 32)
#define IDS_RC_EOF               (IDS_RC_RR_IDS + 33)
#define IDS_RC_EDLERR            (IDS_RC_RR_IDS + 34)
#define IDS_RC_ETRUNC            (IDS_RC_RR_IDS + 35)
#define IDS_RC_EFAULT            (IDS_RC_RR_IDS + 36)
#define IDS_RC_EBADMDL           (IDS_RC_RR_IDS + 37)
#define IDS_RC_ECANCELED         (IDS_RC_RR_IDS + 38)
#define IDS_RC_ECHILD            (IDS_RC_RR_IDS + 39)
#define IDS_RC_EPROTONOSUPPORT   (IDS_RC_RR_IDS + 40)
#define IDS_RC_ENOTCONN          (IDS_RC_RR_IDS + 41)
#define IDS_RC_EISCONN           (IDS_RC_RR_IDS + 42)
#define IDS_RC_ENOPROTOOPT       (IDS_RC_RR_IDS + 43)
#define IDS_RC_EADDRINUSE        (IDS_RC_RR_IDS + 44)
#define IDS_RC_EALREADY          (IDS_RC_RR_IDS + 45)
#define IDS_RC_ELOOP             (IDS_RC_RR_IDS + 46)
#define IDS_RC_EADDRNOTAVAIL     (IDS_RC_RR_IDS + 47)
#define IDS_RC_EOPNOTSUPP        (IDS_RC_RR_IDS + 48)
#define IDS_RC_EDESTADDRREQ      (IDS_RC_RR_IDS + 49)
#define IDS_RC_EAFNOSUPPORT      (IDS_RC_RR_IDS + 50)
#define IDS_RC_EPROTO            (IDS_RC_RR_IDS + 51)
#define IDS_RC_EWOULDBLOCK       (IDS_RC_EAGAIN)
#define IDS_RC_ENOLCK            (IDS_RC_RR_IDS + 52)
#define IDS_RC_ESHUTDOWN         (IDS_RC_RR_IDS + 53)
#define IDS_RC_MAX               (IDS_RC_RR_IDS + 54)

/* test IS error code */
#define IDS_RC_IS_SUCCESS(e)      ((e) == IDS_RC_SUCCESS)
#define IDS_RC_IS_EINVAL(e)       ((e) == IDS_RC_EINVAL)
#define IDS_RC_IS_EINTR(e)        ((e) == IDS_RC_EINTR)
#define IDS_RC_IS_ESRCH(e)        ((e) == IDS_RC_ESRCH)
#define IDS_RC_IS_ENAMETOOLONG(e) ((e) == IDS_RC_ENAMETOOLONG)
#define IDS_RC_IS_EEXIST(e)       ((e) == IDS_RC_EEXIST)
#define IDS_RC_IS_ENOENT(e)       ((e) == IDS_RC_ENOENT)
#define IDS_RC_IS_ENOTEMPTY(e)    ((e) == IDS_RC_ENOTEMPTY || (e) == IDS_RC_EEXIST)
#define IDS_RC_IS_ERANGE(e)       ((e) == IDS_RC_ERANGE)
#define IDS_RC_IS_EBUSY(e)        ((e) == IDS_RC_EBUSY)
#define IDS_RC_IS_EDEADLK(e)      ((e) == IDS_RC_EDEADLK)
#define IDS_RC_IS_EPERM(e)        ((e) == IDS_RC_EPERM)
#define IDS_RC_IS_EACCES(e)       ((e) == IDS_RC_EACCES || (e) == EBADF)

#if !defined(EWOULDBLOCK) || !defined(EAGAIN)
#define IDS_RC_IS_EAGAIN(e)       ((e) == IDS_RC_EAGAIN)
#elif (EWOULDBLOCK == EAGAIN)
#define IDS_RC_IS_EAGAIN(e)       ((e) == IDS_RC_EAGAIN)
#else
#define IDS_RC_IS_EAGAIN(e)       ((e) == IDS_RC_EAGAIN || (e) == IDS_RC_EWOULDBLOCK)
#endif

#define IDS_RC_IS_EINPROGRESS(e)  ((e) == IDS_RC_EINPROGRESS)
#define IDS_RC_IS_ETIMEDOUT(e)    ((e) == IDS_RC_ETIMEDOUT)
#define IDS_RC_IS_EBADF(e)        ((e) == IDS_RC_EBADF)
#define IDS_RC_IS_ENOTDIR(e)      ((e) == IDS_RC_ENOTDIR)
#define IDS_RC_IS_ENOTSOCK(e)     ((e) == IDS_RC_ENOTSOCK)
#if defined(EDQUOT)
#define IDS_RC_IS_ENOSPC(e)       ((e) == IDS_RC_ENOSPC || (e) == EDQUOT)
#else
#define IDS_RC_IS_ENOSPC(e)       ((e) == IDS_RC_ENOSPC)
#endif
#if defined(ENOBUFS)
#define IDS_RC_IS_ENOMEM(e)       ((e) == IDS_RC_ENOMEM || (e) == ENOBUFS)
#else
#define IDS_RC_IS_ENOMEM(e)       ((e) == IDS_RC_ENOMEM)
#endif
#define IDS_RC_IS_EMFILE(e)       ((e) == IDS_RC_EMFILE)
#define IDS_RC_IS_ENFILE(e)       ((e) == IDS_RC_ENFILE)
#define IDS_RC_IS_ESPIPE(e)       ((e) == IDS_RC_ESPIPE)
#define IDS_RC_IS_EPIPE(e)        ((e) == IDS_RC_EPIPE)
#define IDS_RC_IS_ECONNREFUSED(e) ((e) == IDS_RC_ECONNREFUSED)
#define IDS_RC_IS_ECONNABORTED(e) ((e) == IDS_RC_ECONNABORTED || (e) == IDS_RC_EPROTO)
#define IDS_RC_IS_ECONNRESET(e)   ((e) == IDS_RC_ECONNRESET)
#define IDS_RC_IS_EHOSTUNREACH(e) ((e) == IDS_RC_EHOSTUNREACH)
#define IDS_RC_IS_ENETUNREACH(e)  ((e) == IDS_RC_ENETUNREACH)
#define IDS_RC_IS_EXDEV(e)        ((e) == IDS_RC_EXDEV)
#if defined(EAFNOSUPPORT)
#define IDS_RC_IS_ENOTSUP(e)      ((e) == IDS_RC_ENOTSUP || (e) == EAFNOSUPPORT)
#else
#define IDS_RC_IS_ENOTSUP(e)      ((e) == IDS_RC_ENOTSUP)
#endif
#define IDS_RC_IS_ENOIMPL(e)      ((e) == IDS_RC_ENOIMPL)
#define IDS_RC_IS_EOF(e)          ((e) == IDS_RC_EOF)
#define IDS_RC_IS_EDLERR(e)       ((e) == IDS_RC_EDLERR)
#define IDS_RC_IS_ETRUNC(e)       ((e) == IDS_RC_ETRUNC)
#define IDS_RC_IS_EFAULT(e)       ((e) == IDS_RC_EFAULT)
#define IDS_RC_IS_EBADMDL(e)      ((e) == IDS_RC_EBADMDL)
#define IDS_RC_IS_ECANCELED(e)    ((e) == IDS_RC_ECANCELED)
#define IDS_RC_IS_ECHILD(e)       ((e) == IDS_RC_ECHILD)

/* Socket error checkers */
#define IDS_RC_IS_EPROTONOSUPPORT(e)    ((e) == IDS_RC_EPROTONOSUPPORT)
#define IDS_RC_IS_ENOTCONN(e)           ((e) == IDS_RC_ENOTCONN)
#define IDS_RC_IS_EISCONN(e)            ((e) == IDS_RC_EISCONN)
#define IDS_RC_IS_ENOPROTOOPT(e)        ((e) == IDS_RC_ENOPROTOOPT)
#define IDS_RC_IS_EADDRINUSE(e)         ((e) == IDS_RC_EADDRINUSE)
#define IDS_RC_IS_EALREADY(e)           ((e) == IDS_RC_EALREADY)
#define IDS_RC_IS_ELOOP(e)              ((e) == IDS_RC_ELOOP)
#define IDS_RC_IS_EADDRNOTAVAIL(e)      ((e) == IDS_RC_EADDRNOTAVAIL)
#define IDS_RC_IS_EOPNOTSUPP(e)         ((e) == IDS_RC_EOPNOTSUPP)
#define IDS_RC_IS_EDESTADDRREQ(e)       ((e) == IDS_RC_EDESTADDRREQ)
#define IDS_RC_IS_ENOLCK(e)             ((e) == IDS_RC_ENOCLK)
#define IDS_RC_IS_ESHUTDOWN(e)          ((e) == IDS_RC_ESHUTDOWN)
#define IDS_RC_IS_NOTINITIALIZED(e)     (ACP_FALSE)
#define IDS_RC_IS_NETUNUSABLE(e)        (ACP_FALSE)

/*
 * test NOT
 */
#define IDS_RC_NOT_SUCCESS(e) (!IDS_RC_IS_SUCCESS(e))
#define IDS_RC_NOT_EINVAL(e) (!IDS_RC_IS_EINVAL(e))
#define IDS_RC_NOT_EINTR(e) (!IDS_RC_IS_EINTR(e))
#define IDS_RC_NOT_ESRCH(e) (!IDS_RC_IS_ESRCH(e))
#define IDS_RC_NOT_ENAMETOOLONG(e) (!IDS_RC_IS_ENAMETOOLONG(e))
#define IDS_RC_NOT_EEXIST(e) (!IDS_RC_IS_EEXIST(e))
#define IDS_RC_NOT_ENOENT(e) (!IDS_RC_IS_ENOENT(e))
#define IDS_RC_NOT_ENOTEMPTY(e) (!IDS_RC_IS_ENOTEMPTY(e))
#define IDS_RC_NOT_ERANGE(e) (!IDS_RC_IS_ERANGE(e))
#define IDS_RC_NOT_EBUSY(e) (!IDS_RC_IS_EBUSY(e))
#define IDS_RC_NOT_EDEADLK(e) (!IDS_RC_IS_EDEADLK(e))
#define IDS_RC_NOT_EPERM(e) (!IDS_RC_IS_EPERM(e))
#define IDS_RC_NOT_EACCES(e) (!IDS_RC_IS_EACCES(e))
#define IDS_RC_NOT_EAGAIN(e) (!IDS_RC_IS_EAGAIN(e))
#define IDS_RC_NOT_EINPROGRESS(e) (!IDS_RC_IS_EINPROGRESS(e))
#define IDS_RC_NOT_ETIMEDOUT(e) (!IDS_RC_IS_ETIMEDOUT(e))
#define IDS_RC_NOT_EBADF(e) (!IDS_RC_IS_EBADF(e))
#define IDS_RC_NOT_ENOTDIR(e) (!IDS_RC_IS_ENOTDIR(e))
#define IDS_RC_NOT_ENOTSOCK(e) (!IDS_RC_IS_ENOTSOCK(e))
#define IDS_RC_NOT_ENOSPC(e) (!IDS_RC_IS_ENOSPC(e))
#define IDS_RC_NOT_ENOMEM(e) (!IDS_RC_IS_ENOMEM(e))
#define IDS_RC_NOT_EMFILE(e) (!IDS_RC_IS_EMFILE(e))
#define IDS_RC_NOT_ENFILE(e) (!IDS_RC_IS_ENFILE(e))
#define IDS_RC_NOT_ESPIPE(e) (!IDS_RC_IS_ESPIPE(e))
#define IDS_RC_NOT_EPIPE(e) (!IDS_RC_IS_EPIPE(e))
#define IDS_RC_NOT_ECONNREFUSED(e) (!IDS_RC_IS_ECONNREFUSED(e))
#define IDS_RC_NOT_ECONNABORTED(e) (!IDS_RC_IS_ECONNABORTED(e))
#define IDS_RC_NOT_ECONNRESET(e) (!IDS_RC_IS_ECONNRESET(e))
#define IDS_RC_NOT_EHOSTUNREACH(e) (!IDS_RC_IS_EHOSTUNREACH(e))
#define IDS_RC_NOT_ENETUNREACH(e) (!IDS_RC_IS_ENETUNREACH(e))
#define IDS_RC_NOT_EXDEV(e) (!IDS_RC_IS_EXDEV(e))
#define IDS_RC_NOT_ENOTSUP(e) (!IDS_RC_IS_ENOTSUP(e))
#define IDS_RC_NOT_ENOIMPL(e) (!IDS_RC_IS_ENOIMPL(e))
#define IDS_RC_NOT_EOF(e) (!IDS_RC_IS_EOF(e))
#define IDS_RC_NOT_EDLERR(e) (!IDS_RC_IS_EDLERR(e))
#define IDS_RC_NOT_ETRUNC(e) (!IDS_RC_IS_ETRUNC(e))
#define IDS_RC_NOT_EFAULT(e) (!IDS_RC_IS_EFAULT(e))
#define IDS_RC_NOT_EBADMDL(e) (!IDS_RC_IS_EBADMDL(e))
#define IDS_RC_NOT_ECANCELED(e) (!IDS_RC_IS_ECANCELED(e))
#define IDS_RC_NOT_ECHILD(e) (!IDS_RC_IS_ECHILD(e))
#define IDS_RC_NOT_EPROTONOSUPPORT(e) (!IDS_RC_IS_EPROTONOSUPPORT(e))
#define IDS_RC_NOT_ENOTCONN(e) (!IDS_RC_IS_ENOTCONN(e))
#define IDS_RC_NOT_EISCONN(e) (!IDS_RC_IS_EISCONN(e))
#define IDS_RC_NOT_ENOPROTOOPT(e) (!IDS_RC_IS_ENOPROTOOPT(e))
#define IDS_RC_NOT_EADDRINUSE(e) (!IDS_RC_IS_EADDRINUSE(e))
#define IDS_RC_NOT_EALREADY(e) (!IDS_RC_IS_EALREADY(e))
#define IDS_RC_NOT_ELOOP(e) (!IDS_RC_IS_ELOOP(e))
#define IDS_RC_NOT_EADDRNOTAVAIL(e) (!IDS_RC_IS_EADDRNOTAVAIL(e))
#define IDS_RC_NOT_EOPNOTSUPP(e) (!IDS_RC_IS_EOPNOTSUPP(e))
#define IDS_RC_NOT_EDESTADDRREQ(e) (!IDS_RC_IS_EDESTADDRREQ(e))
#define IDS_RC_NOT_ENOLCK(e) (!IDS_RC_IS_ENOLCK(e))
#define IDS_RC_NOT_ESHUTDOWN(e) (!IDS_RC_IS_ESHUTDOWN(e))
#define IDS_RC_NOT_NOTINITIALIZED(e) (!IDS_RC_IS_NOTINITIALIZED(e))
#define IDS_RC_NOT_NETUNUSABLE(e)

#endif /* _O_IDS_ERROR_H_ */
