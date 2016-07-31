/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_ids_SYS_H_)
#define _O_ids_SYS_H_

#include <idsError.h>
#include <idsTime.h>
#include <idsStr.h>

#define IDS_SYS_NOLIMIT RLIM_INFINITY

/* length of mac address */
#define IDS_SYS_MAC_ADDR_LEN   (6)
#define IDS_SYS_ID_MAXSIZE     (1024)

/* cpu times information */
typedef struct IDS_CPUTime
{
    IDS_Time mUserTime;   /**< user time   */
    IDS_Time mSystemTime; /**< system time */
} IDS_CPUTime;

/* resource limit */
IDS_RC idsSysGetHandleLimit(IDS_UInt *aHandleLimit);
IDS_RC idsSysSetHandleLimit(IDS_UInt aHandleLimit);

/* system information */
IDS_RC idsSysGetCPUCount(IDS_UInt *aCount);

IDS_RC idsSysGetPageSize(IDS_Size *aPageSize);

IDS_RC idsSysGetBlockSize(IDS_Size *aBlockSize);

IDS_RC idsSysGetHostName(IDS_SChar *aBuffer, IDS_Size aSize);

IDS_RC idsSysGetUserName(IDS_SChar *aBuffer, IDS_Size aSize);

/* process information */
IDS_RC idsSysGetCPUTimes(IDS_CPUTime *idsuTimes);

/* idsSysGetHardwareID : Get hardware ID */
IDS_RC idsSysGetHardwareID(IDS_SChar* aID, IDS_Size  aBufLen);

#endif
