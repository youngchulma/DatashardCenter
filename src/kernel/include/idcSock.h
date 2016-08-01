/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_IDC_SOCK_H_)
#define _O_IDC_SOCK_H_ 1

#include <idpTime.h>

#if defined(ACP_CFG_DOXYGEN)

#elif defined(ALTI_CFG_OS_SOLARIS)

#elif defined(ALTI_CFG_OS_WINDOWS)

#else
#  define ACP_SOCK_INADDR_INITIALIZER {0}
#  define ACP_SOCK_INADDR_SET(aAddr, aValue) (aAddr.s_addr = aValue)
#  define ACP_SOCK_INADDR_GET(aAddr) ((acp_uint32_t)(aAddr.s_addr))

#endif

/**
 * IPv4 address family
 * @see acpSockOpen()
 */
#define ACP_AF_INET       AF_INET
#if defined(AF_INET6) || defined(ACP_CFG_DOXYGEN)
/**
 * IPv6 address family; currently not supported
 * @see acpSockOpen()
 */
#define ACP_AF_INET6      AF_INET6
#else
#define ACP_AF_INET6      26
#endif
/**
 * local Unix-Domain address family
 * @see acpSockOpen()
 */
#define ACP_AF_UNIX       AF_UNIX

/**
* Not specified address family
* @see acpSockOpen()
*/
#define ACP_AF_UNSPEC     AF_UNSPEC

/**
 * stream socket type
 * @see acpSockOpen()
 */
#define ACP_SOCK_STREAM   SOCK_STREAM
/**
 * datagram socket type
 * @see acpSockOpen()
 */
#define ACP_SOCK_DGRAM    SOCK_DGRAM



#if defined(ALTI_CFG_OS_WINDOWS)
#else
/**
 * shutdown read part of a full-duplex connection
 * @see acpSockShutdown()
 */
#define ACP_SHUT_RD       SHUT_RD
/**
 * shutdown write part of a full-duplex connection
 * @see acpSockShutdown()
 */
#define ACP_SHUT_WR       SHUT_WR
/**
 * shutdown all part of a full-duplex connection
 * @see acpSockShutdown()
 */
#define ACP_SHUT_RDWR     SHUT_RDWR
#endif

/*
 * BUGBUG: should define socket option constants
 */


#if defined(MSG_DONTWAIT) || defined(ACP_CFG_DOXYGEN)
/**
 * requests non-blocking operation
 * @see acpSockRecv() acpSockRecvFrom() acpSockSend() acpSockSendTo()
 */
#define ACP_MSG_DONTWAIT  MSG_DONTWAIT
#elif defined(MSG_NONBLOCK)
#define ACP_MSG_DONTWAIT  MSG_NONBLOCK
#else
#define ACP_MSG_DONTWAIT  0x4000
#endif
/**
 * requests operation for out-of-band data
 * that whould not be transmitted in the normal data stream
 * @see acpSockRecv() acpSockRecvAll() acpSockRecvFrom()
 * acpSockSend() acpSockSendAll() acpSockSendTo()
 */
#define ACP_MSG_OOB       MSG_OOB
/**
 * causes the receive operation to return data
 * from the beginning of the receive queue
 * without removing that data from the queue.
 * thus, a subsequent receive call will return the same data
 * @see acpSockRecv() acpSockRecvFrom()
 */
#define ACP_MSG_PEEK      MSG_PEEK

/**
 * default flag value of sockets
 * disables non-blocking operation, out-of-band data,
 * and message peek.
 * @see acpSockRecv() acpSockRecvAll() acpSockRecvFrom()
 * acpSockSend() acpSockSendAll() acpSockSendTo()
 */
#define ACP_MSG_DEFAULT     (0)

#define ACP_SOCK_ERROR          -1
#define ACP_SOCK_INVALID_HANDLE -1
#define ACP_SOCK_SIZE_TYPE

#if !defined(MSG_DONTWAIT) && !defined(MSG_NONBLOCK)
#define ACP_SOCK_DO_IO(aSock, aFlag, aEvent, aOpStmt)                       \
    do                                                                      \
    {                                                                       \
        if ((((aFlag) & ACP_MSG_DONTWAIT) != 0) &&                          \
            ((aSock)->mBlockMode == ACP_TRUE))                              \
        {                                                                   \
            IDS_RC sPollRC;                                               \
                                                                            \
            sPollRC = acpSockPoll((aSock), (aEvent), ACP_TIME_IMMEDIATE);   \
                                                                            \
            if (ACP_RC_IS_SUCCESS(sPollRC))                                 \
            {                                                               \
                (aFlag) &= ~ACP_MSG_DONTWAIT;                               \
                aOpStmt;                                                    \
            }                                                               \
            else if (ACP_RC_IS_ETIMEDOUT(sPollRC))                          \
            {                                                               \
                return ACP_RC_EAGAIN;                                       \
            }                                                               \
            else                                                            \
            {                                                               \
                return sPollRC;                                             \
            }                                                               \
        }                                                                   \
        else                                                                \
        {                                                                   \
            aOpStmt;                                                        \
        }                                                                   \
    } while (0)
#else
#define ACP_SOCK_DO_IO(aSock, aFlag, aEvent, aOpStmt) aOpStmt
#endif


/* socket object */
typedef struct IDC_Sock
{
    IDS_SInt mHandle;
    IDS_Boll mBlockMode;
} IDC_Sock;

/* socket address structure (struct sockaddr) */
typedef struct sockaddr IDC_SockAddr;
/* socket address structure (struct sockaddr_in) */
typedef struct sockaddr_in IDC_SockAddrIn;
/* socket address structure for Unix-Domain */
typedef struct sockaddr_un IDC_SockAddrUn;
/* socket address structure common for IPv6 and IPv4 */
typedef struct sockaddr_storage acp_sock_addr_storage_t;
/* length type for socket address, name, or option */
typedef socklen_t IDC_SockLen;
/* IPv4 multicast request */
typedef struct ip_mreq acp_ip_mreq_t;

IDS_RC acpSockInitialize(void);
IDS_RC acpSockFinalize(void);

/* open/close */
IDS_RC idcSockOpen( IDC_Sock *aSock,
                    IDS_SInt  aFamily,
                    IDS_SInt  aType,
                    IDS_SInt  aProtocol );

IDS_RC idcSockClose(IDC_Sock *aSock);
IDS_RC idcSockShutdown(IDC_Sock *aSock, IDS_SInt aHow);

/* option */
IDS_RC idcSockGetBlockMode(IDC_Sock *aSock, IDS_Bool *aBlockMode);
IDS_RC idcSockSetBlockMode(IDC_Sock *aSock, IDS_Bool  aBlockMode);

IDS_RC idcSockGetOpt( IDC_Sock    *aSock,
                      IDS_SInt     aLevel,
                      IDS_SInt     aOptName,
                      void        *aOptVal,
                      IDC_SockLen *aOptLen );

IDS_RC idcSockSetOpt( IDC_Sock   *aSock,
                      IDS_SInt    aLevel,
                      IDS_SInt    aOptName,
                      const void *aOptVal,
                      IDC_SockLen aOptLen );
/* poll event */
IDS_RC idcSockPoll( IDC_Sock *aSock,
                    IDS_SInt  aEvent,
                    IDS_Time  aTimeout );
/* client socket */
IDS_RC idcSockConnect( IDC_Sock      *aSock,
                       IDC_SockAddr *aAddr,
                       IDC_SockLen   aAddrLen );

IDS_RC idcSockTimedConnect( IDC_Sock     *aSock,
                            IDC_SockAddr *aAddr,
                            IDC_SockLen   aAddrLen,
                            IDS_Time      aTimeout );
/* server socket */
IDS_RC idcSockBind( IDC_Sock           *aSock,
                    const IDC_SockAddr *aAddr,
                    IDC_SockLen         aAddrLen,
                    IDS_Bool            aReuseAddr);

IDS_RC idcSockListen(IDC_Sock *aSock, IDS_SInt aBackLog);

IDS_RC idcSockAccept( IDC_Sock     *aAcceptSock,
                      IDC_Sock     *aListenSock,
                      IDC_SockAddr *aAddr,
                      IDC_SockLen  *aAddrLen );
/* name */
IDS_RC idcSockGetName( IDC_Sock     *aSock,
                       IDC_SockAddr *aName,
                       IDC_SockLen  *aNameLen );

IDS_RC idcSockGetPeerName( IDC_Sock     *aSock,
                           IDC_SockAddr *aName,
                           IDC_SockLen  *aNameLen );
/* recv/send */
IDS_RC acpSockRecv(IDC_Sock   *aSock,
                                void         *aBuffer,
                                IDS_Size    aSize,
                                IDS_Size   *aRecvSize,
                                IDS_SInt  aFlag);
  IDS_RC acpSockSend(IDC_Sock   *aSock,
                                const void   *aBuffer,
                                IDS_Size    aSize,
                                IDS_Size   *aSendSize,
                                IDS_SInt  aFlag);
  IDS_RC acpSockRecvAll(IDC_Sock   *aSock,
                                   void         *aBuffer,
                                   IDS_Size    aSize,
                                   IDS_Size   *aRecvSize,
                                   IDS_SInt  aFlag,
                                   IDS_Time    aTimeout);
  IDS_RC acpSockSendAll(IDC_Sock   *aSock,
                                   const void   *aBuffer,
                                   IDS_Size    aSize,
                                   IDS_Size   *aSendSize,
                                   IDS_SInt  aFlag,
                                   IDS_Time    aTimeout);

  IDS_RC acpSockRecvFrom(IDC_Sock      *aSock,
                                    void            *aBuffer,
                                    IDS_Size       aSize,
                                    IDS_Size      *aRecvSize,
                                    IDS_SInt     aFlag,
                                    IDC_SockAddr *aAddr,
                                    IDC_SockLen  *aAddrLen);
  IDS_RC acpSockSendTo(IDC_Sock            *aSock,
                                  const void            *aBuffer,
                                  IDS_Size             aSize,
                                  IDS_Size            *aSendSize,
                                  IDS_SInt           aFlag,
                                  const IDC_SockAddr *aAddr,
                                  IDC_SockLen         aAddrLen);


ACP_EXTERN_C_END


#endif
