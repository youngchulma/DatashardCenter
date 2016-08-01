/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#include <idcPoll.h>
#include <idcSock.h>

/* sends data to a socket */
IDS_RC idcSockSend(IDC_Sock   *aSock,
                   const void *aBuffer,
                   IDS_Size    aSize,
                   IDS_Size   *aSendSize,
                   IDS_SInt    aFlag)
{
    return IDS_RC_SUCCESS;
}

/* sends data with size from a socket */
IDS_RC idcSockSendAll(IDC_Sock   *aSock,
                      const void *aBuffer,
                      IDS_Size    aSize,
                      IDS_Size   *aSendSize,
                      IDS_SInt    aFlag,
                      IDS_Time    aTimeout)
{
    return IDS_RC_SUCCESS;
}

/* sends data to a socket */
IDS_RC idcSockSendTo(IDC_Sock           *aSock,
                     const void         *aBuffer,
                     IDS_Size            aSize,
                     IDS_Size           *aSendSize,
                     IDS_SInt            aFlag,
                     const IDC_SockAddr *aAddr,
                     IDC_SockLen         aAddrLen)
{
    return IDS_RC_SUCCESS;
}
