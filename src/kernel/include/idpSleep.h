/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_IDP_SLEEP_H_)
#define _O_IDP_SLEEP_H_ 1

#include <idsTypes.h>

/* sleeps aSec second(s) */
IDS_INLINE void idpSleepSec(IDS_UInt aSec)
{
    struct timeval sTimeVal;

    sTimeVal.tv_sec  = aSec;
    sTimeVal.tv_usec = 0;

    (void)select(0, NULL, NULL, NULL, &sTimeVal);
}

/* sleeps @a aMsec millisecond(s) */
IDS_INLINE void idpSleepMsec(IDS_UInt aMsec)
{
    struct timeval sTimeVal;

    sTimeVal.tv_sec  = aMsec / 1000;
    sTimeVal.tv_usec = (aMsec % 1000) * 1000;

    (void)select(0, NULL, NULL, NULL, &sTimeVal);
}

/* sleeps @a aUsec microsecond(s) */
IDS_INLINE void idpSleepUsec(IDS_UInt aUsec)
{
    struct timeval sTimeVal;

    sTimeVal.tv_sec  = aUsec / 1000000;
    sTimeVal.tv_usec = aUsec % 1000000;

    (void)select(0, NULL, NULL, NULL, &sTimeVal);
}

#endif /* _O_IDP_SLEEP_H_ */
