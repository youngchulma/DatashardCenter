/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 *******************************************************************************/

#include <idcPoll.h>
#include <idcSock.h>

IDS_RC idcSockInitialize(void)
{
    return IDS_RC_SUCCESS;
}

IDS_RC idcSockFinalize(void)
{
    return IDS_RC_SUCCESS;
}

/* opens a socket */
IDS_RC idcSockOpen( IDC_Sock *aSock,
                    IDS_SInt  aFamily,
                    IDS_SInt  aType,
                    IDS_SInt  aProtocol )
{
    aSock->mHandle = socket(aFamily, aType, aProtocol);

    if (aSock->mHandle == IDC_SOCK_INVALID_HANDLE)
    {
        return IDS_RC_GET_NET_ERROR();
    }
    else
    {
        aSock->mBlockMode = IDS_TRUE;

        return IDS_RC_SUCCESS;
    }
}

/* closes a socket */
IDS_RC idcSockClose(IDC_Sock *aSock)
{
    IDS_SInt sRet;

    sRet = close(aSock->mHandle);

    if (sRet == 0)
    {
        return IDS_RC_SUCCESS;
    }
    else
    {
        return IDS_RC_GET_NET_ERROR();
    }
}

/* shutdowns one or both of read/write part of full-duplex connection */
IDS_RC idcSockShutdown(IDC_Sock *aSock, IDS_SInt aHow)
{
    IDS_SInt sRet;

    sRet = shutdown(aSock->mHandle, aHow);

    if (sRet == 0)
    {
        return IDS_RC_SUCCESS;
    }
    else
    {
        return IDS_RC_GET_NET_ERROR();
    }
}

/* gets the blocking mode of a socket */
IDS_RC idcSockGetBlockMode(IDC_Sock *aSock, IDS_Bool *aBlockMode)
{
    *aBlockMode = aSock->mBlockMode;

    return IDS_RC_SUCCESS;
}

/* sets the blocking mode of a socket */
IDS_RC idcSockSetBlockMode(IDC_Sock *aSock, IDS_Bool aBlockMode)
{
    IDS_SInt sRet;

    sRet = fcntl(aSock->mHandle, F_GETFL, 0);

    if (sRet == IDC_SOCK_ERROR)
    {
        return IDS_RC_GET_NET_ERROR();
    }
    else
    {
        switch (aBlockMode)
        {
            case IDS_FALSE:
                sRet |= O_NONBLOCK;
                break;
            case IDS_TRUE:
            default:
                sRet &= ~O_NONBLOCK;
                break;
        }

        sRet = fcntl(aSock->mHandle, F_SETFL, sRet);

        if (sRet == IDC_SOCK_ERROR)
        {
            return IDS_RC_GET_NET_ERROR();
        }
        else
        {
            aSock->mBlockMode = aBlockMode;

            return IDS_RC_SUCCESS;
        }
    }
}

/* gets the option of a socket */
IDS_RC idcSockGetOpt(IDC_Sock    *aSock,
                     IDS_SInt     aLevel,
                     IDS_SInt     aOptName,
                     void        *aOptVal,
                     IDC_SockLen *aOptLen)
{
    IDS_SInt sRet;
    sRet = getsockopt(aSock->mHandle, aLevel, aOptName, aOptVal, aOptLen);

    if (sRet == 0)
    {
        if ((aLevel == SOL_SOCKET) && (aOptName == SO_ERROR))
        {
            IDS_SInt *sError = (IDS_SInt *)aOptVal;

            *sError = IDS_RC_FROM_SYS_ERROR(*sError);
        }
        else
        {
            /* do nothing */
        }

        return IDS_RC_SUCCESS;
    }
    else
    {
        return IDS_RC_GET_NET_ERROR();
    }
}

/* sets the option of a socket */
IDS_RC idcSockSetOpt(IDC_Sock    *aSock,
                     IDS_SInt     aLevel,
                     IDS_SInt     aOptName,
                     const void  *aOptVal,
                     IDC_SockLen  aOptLen)
{
    IDS_SInt sRet;

    sRet = setsockopt(aSock->mHandle, aLevel, aOptName, aOptVal, aOptLen);

    if (sRet == 0)
    {
        return IDS_RC_SUCCESS;
    }
    else
    {
        return IDS_RC_GET_NET_ERROR();
    }
}

/* binds an address to a socket */
IDS_RC idcSockBind(IDC_Sock           *aSock,
                   const IDC_SockAddr *aAddr,
                   IDC_SockLen         aAddrLen,
                   IDS_Bool            aReuseAddr)
{
    IDS_SInt sReuseOpt = 1;
    IDS_SInt sRet;
    IDS_RC     sRC;

    if (aReuseAddr == IDS_TRUE)
    {
        sRC = idcSockSetOpt(aSock,
                            SOL_SOCKET,
                            SO_REUSEADDR,
                            &sReuseOpt,
                            (IDC_SockLen)sizeof(sReuseOpt));
    }
    else
    {
        sRC = IDS_RC_SUCCESS;
    }

    if (IDS_RC_IS_SUCCESS(sRC))
    {
        sRet = bind(aSock->mHandle, aAddr, aAddrLen);

        if (sRet == 0)
        {
            sRC = IDS_RC_SUCCESS;
        }
        else
        {
            sRC = IDS_RC_GET_NET_ERROR();
        }
    }
    else
    {
        /* do nothing */
    }

    return sRC;
}

/* listens a connection */
IDS_RC idcSockListen(IDC_Sock *aSock,IDS_SInt aBackLog)
{
    IDS_SInt sRet;

    sRet = listen(aSock->mHandle, aBackLog);

    if (sRet == 0)
    {
        return IDS_RC_SUCCESS;
    }
    else
    {
        return IDS_RC_GET_NET_ERROR();
    }
}

/* accepts a connection from a listening socket */
IDS_RC idcSockAccept(IDC_Sock     *aAcceptSock,
                     IDC_Sock     *aListenSock,
                     IDC_SockAddr *aAddr,
                     IDC_SockLen  *aAddrLen)
{
    IDS_RC sRC;
    
    aAcceptSock->mHandle = accept(aListenSock->mHandle, aAddr, aAddrLen);

    if (aAcceptSock->mHandle == IDC_SOCK_INVALID_HANDLE)
    {
        return IDS_RC_GET_NET_ERROR();
    }
    else
    {
        /* Accepted socket will inherit mBlockMode of listening socket */
        sRC = idcSockSetBlockMode(aAcceptSock, aListenSock->mBlockMode);
        if (IDS_RC_NOT_SUCCESS(sRC) && aAcceptSock->mHandle != IDC_SOCK_INVALID_HANDLE)
        {
            (void)idcSockClose(aAcceptSock);
        }
        else
        {
            /* do nothing */
        }
    }
    
    return sRC;
}

/* gets the address of remote peer of the socket */
IDS_RC idcSockGetName(IDC_Sock     *aSock,
                      IDC_SockAddr *aName,
                      IDC_SockLen  *aNameLen)
{
    IDS_SInt sRet;
    sRet = getsockname(aSock->mHandle, aName, aNameLen);

    if (sRet == 0)
    {
        return IDS_RC_SUCCESS;
    }
    else
    {
        return IDS_RC_GET_NET_ERROR();
    }
}

/* gets the address of remote peer of the socket */
IDS_RC idcSockGetPeerName(IDC_Sock     *aSock,
                          IDC_SockAddr *aName,
                          IDC_SockLen  *aNameLen)
{
    IDS_SInt sRet;

    sRet = getpeername(aSock->mHandle, aName, aNameLen);

    if (sRet == 0)
    {
        return IDS_RC_SUCCESS;
    }
    else
    {
        return IDS_RC_GET_NET_ERROR();
    }
}

