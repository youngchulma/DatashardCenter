/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#include <idcPoll.h>
#include <idcSock.h>

/* connects to the specified address */
IDS_RC idcSockConnect(IDC_Sock     *aSock,
                      IDC_SockAddr *aAddr,
                      IDC_SockLen   aAddrLen)
{
    IDS_RC sRc;

    sRc = connect(aSock->mHandle, aAddr, aAddrLen);
    IDS_TEST( sRc != IDS_RC_SUCCESS );

    return IDS_RC_SUCCESS;

    IDS_EXCEPTION_END;

    return IDS_RC_GET_NET_ERROR();
}

/* connects to the specified address with timeout */
IDS_RC idcSockTimedConnect(IDC_Sock     *aSock,
                           IDC_SockAddr *aAddr,
                           IDC_SockLen   aAddrLen,
                           IDS_Time      aTimeout)
{
    return IDS_RC_SUCCESS;
}
