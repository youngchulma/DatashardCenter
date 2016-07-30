/***********************************************************************
 * Copyright 1999-2016 ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#if !defined(_O_DKP_SOCKET_H_)
#define _O_DKP_SOCKET_H_ 1

#include <dkpTime.h>
#include <dkpTypes.h>
#include <dkpError.h>
#include <dkpException.h>

#define DKP_AF_UNIX             AF_UNIX
#define DKP_PF_UNIX             PF_UNIX

#define DKP_SOCK_STREAM         SOCK_STREAM
#define DKP_SOCK_DGRAM          SOCK_DGRAM

#define DKP_SOCK_ERROR          (-1)
#define DKP_SOCK_INVALID_HANDLE (-1)

/* Flags we can use with send and recv */
#define DKP_SOCK_MSG_DONTWAIT   (0x40)   /* Nonblocking io */
#define DKP_SOCK_MSG_NOSIGNAL   (0x4000) /* Do not generate SIGPIPE */
#define DKP_SOCK_BACKLOG_NUM    (128)

#define DKP_SELECT_READ         (1)
#define DKP_SELECT_WRITE        (2)

typedef enum dkpSockMode
{
    DKP_SOCK_BLOCKING = 0, 
    DKP_SOCK_NON_BLOCKING = 1
} dkpSockMode;

typedef struct dkpSocket
{
    SInt mHandle;
    dkpSockMode mMode;
} dkpSocket;

typedef struct sockaddr dkpSockAddr;
typedef struct sockaddr_un dkpSockAddrDomain;
typedef struct sockaddr_in dkpSockAddrInternet;
typedef socklen_t dkpSockLen;

/* Sock Open / Close */
DKP_RC dkpSockOpen( dkpSocket *aSock,
                    SInt aFamily,
                    SInt aType,
                    SInt aProtocol );

DKP_RC dkpSockClose( dkpSocket *aSock );

/* Sock Option */
DKP_RC dkpSockSetMode( dkpSocket *aSock, dkpSockMode aMode );

/* Sock Select */
DKP_RC dkpSockSelect( dkpSocket *aSock,
                      SInt aEvent,
                      dkpTime aTimeout );

/* Client Socket */
DKP_RC dkpSockConnect( dkpSocket *aSock,
                       dkpSockAddr *aAddr,
                       dkpSockLen aAddrLen );

DKP_RC dkpSockTimedConnect( dkpSocket *aSock,
                            dkpSockAddr *aAddr,
                            dkpSockLen aAddrLen,
                            dkpTime aTimeout );

/* Server Socket */
DKP_RC dkpSockBind( dkpSocket *aSock,
                    dkpSockAddr *aAddr,
                    dkpSockLen aAddrLen );

DKP_RC dkpSockListen( dkpSocket *aSock, SInt aBackLog );

DKP_RC dkpSockAccept( dkpSocket *aAcceptSock,
                      dkpSocket *aListenSock,
                      dkpSockAddr *aAddr,
                      dkpSockLen *aAddrLen );

/* Socket Send / Recv */
DKP_RC dkpSockSend( dkpSocket *aSock,
                    const void *aBuffer,
                    UInt aSize,
                    SInt aFlag,
                    dkpTime aTimeout );

DKP_RC dkpSockRecv( dkpSocket *aSock,
                    void *aBuffer,
                    UInt aSize,
                    SInt aFlag,
                    dkpTime aTimeout );

#endif /* _O_DKP_SOCKET_H_  */
