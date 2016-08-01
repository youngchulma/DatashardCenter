/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_IDC_SOCK_H_)
#define _O_IDC_SOCK_H_ 1

#include <idsTime.h>

#define IDC_SOCK_INADDR_INITIALIZER {0}
#define IDC_SOCK_INADDR_SET(aAddr, aValue) (aAddr.s_addr = aValue)
#define IDC_SOCK_INADDR_GET(aAddr) ((idc_uint32_t)(aAddr.s_addr))

/* IPv4 address family */
#define IDC_AF_INET       AF_INET
/* local Unix-Domain address family */
#define IDC_AF_UNIX       AF_UNIX
/* Not specified address family */
#define IDC_AF_UNSPEC     AF_UNSPEC
/* stream socket type */
#define IDC_SOCK_STREAM   SOCK_STREAM
/* datagram socket type */
#define IDC_SOCK_DGRAM    SOCK_DGRAM

/* requests non-blocking operation */
#define IDC_MSG_DONTWAIT  MSG_NONBLOCK

/* requests operation for out-of-band data */
#define IDC_MSG_OOB       MSG_OOB

/* causes the receive operation to return data */
#define IDC_MSG_PEEK      MSG_PEEK

/* default flag value of sockets */
#define IDC_MSG_DEFAULT     (0)
#define IDC_SOCK_ERROR          -1
#define IDC_SOCK_INVALID_HANDLE -1
#define IDC_SOCK_SIZE_TYPE

#define IDC_SOCK_DO_IO(aSock, aFlag, aEvent, aOpStmt) aOpStmt

/* socket object */
typedef struct IDC_Sock
{
    IDS_SInt mHandle;
    IDS_Bool   mBlockMode;
} IDC_Sock;

/* socket address structure (struct sockaddr) */
typedef struct sockaddr IDC_SockAddr;

/* socket address structure (struct sockaddr_in) */
typedef struct sockaddr_in IDC_SockAddrIn;

/* socket address structure for Unix-Domain. */
typedef struct sockaddr_un IDC_SockAddrUn;

/* socket address structure common for IPv6 and IPv4 */
typedef struct sockaddr_storage IDC_SockAddrStorage;
  
/* length type for socket address, name, or option */
typedef socklen_t IDC_SockLen;

/* IPv4 multicast request */
typedef struct ip_mreq IDS_IPMreq;

IDS_RC idcSockInitialize(void);
IDS_RC idcSockFinalize(void);

/* open/close */
IDS_RC idcSockOpen(IDC_Sock   *aSock,
                   IDS_SInt  aFamily,
                   IDS_SInt  aType,
                   IDS_SInt  aProtocol);
IDS_RC idcSockClose(IDC_Sock *aSock);
IDS_RC idcSockShutdown(IDC_Sock *aSock, IDS_SInt aHow);

/* option */
IDS_RC idcSockGetBlockMode(IDC_Sock *aSock, IDS_Bool *aBlockMode);
IDS_RC idcSockSetBlockMode(IDC_Sock *aSock, IDS_Bool  aBlockMode);

IDS_RC idcSockGetOpt(IDC_Sock    *aSock,
                     IDS_SInt     aLevel,
                     IDS_SInt     aOptName,
                     void        *aOptVal,
                     IDC_SockLen *aOptLen);

IDS_RC idcSockSetOpt(IDC_Sock     *aSock,
                     IDS_SInt    aLevel,
                     IDS_SInt    aOptName,
                     const void     *aOptVal,
                     IDC_SockLen  aOptLen);

/* poll event */
IDS_RC idcSockPoll(IDC_Sock *aSock,
                   IDS_SInt  aEvent,
                   IDS_Time  aTimeout);

/* client socket */
IDS_RC idcSockConnect(IDC_Sock     *aSock,
                      IDC_SockAddr *aAddr,
                      IDC_SockLen   aAddrLen);

IDS_RC idcSockTimedConnect(IDC_Sock     *aSock,
                           IDC_SockAddr *aAddr,
                           IDC_SockLen   aAddrLen,
                           IDS_Time      aTimeout);

/* server socket */
IDS_RC idcSockBind(IDC_Sock           *aSock,
                   const IDC_SockAddr *aAddr,
                   IDC_SockLen         aAddrLen,
                   IDS_Bool            aReuseAddr);

IDS_RC idcSockListen(IDC_Sock *aSock, IDS_SInt  aBackLog);
IDS_RC idcSockAccept(IDC_Sock     *aAcceptSock,
                     IDC_Sock     *aListenSock,
                     IDC_SockAddr *aAddr,
                     IDC_SockLen  *aAddrLen);

/* name */
IDS_RC idcSockGetName(IDC_Sock     *aSock, 
                      IDC_SockAddr *aName, 
                      IDC_SockLen  *aNameLen);
IDS_RC idcSockGetPeerName(IDC_Sock *aSock, IDC_SockAddr *aName, IDC_SockLen *aNameLen);

/* recv/send */
IDS_RC idcSockRecv(IDC_Sock *aSock,
                   void     *aBuffer,
                   IDS_Size  aSize,
                   IDS_Size *aRecvSize,
                   IDS_SInt  aFlag);

IDS_RC idcSockSend(IDC_Sock   *aSock,
                   const void *aBuffer,
                   IDS_Size    aSize,
                   IDS_Size   *aSendSize,
                   IDS_SInt    aFlag);

IDS_RC idcSockRecvAll(IDC_Sock *aSock,
                      void     *aBuffer,
                      IDS_Size  aSize,
                      IDS_Size *aRecvSize,
                      IDS_SInt  aFlag,
                      IDS_Time  aTimeout);

IDS_RC idcSockSendAll(IDC_Sock   *aSock,
                      const void *aBuffer,
                      IDS_Size    aSize,
                      IDS_Size   *aSendSize,
                      IDS_SInt    aFlag,
                      IDS_Time    aTimeout);

IDS_RC idcSockRecvFrom(IDC_Sock      *aSock,
                       void            *aBuffer,
                       IDS_Size       aSize,
                       IDS_Size      *aRecvSize,
                       IDS_SInt     aFlag,
                       IDC_SockAddr *aAddr,
                       IDC_SockLen  *aAddrLen);

IDS_RC idcSockSendTo(IDC_Sock           *aSock,
                     const void         *aBuffer,
                     IDS_Size            aSize,
                     IDS_Size           *aSendSize,
                     IDS_SInt            aFlag,
                     const IDC_SockAddr *aAddr,
                     IDC_SockLen         aAddrLen);

#endif

