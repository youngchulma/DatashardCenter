/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_DKS_SLEEP_H_)
#define _O_DKS_SLEEP_H_ 1

#include <dkpTypes.h>

/* sleeps aSec second(s) */
DKP_INLINE void dksSleepSec(DKP_UInt aSec)
{
    struct timeval sTimeVal;

    sTimeVal.tv_sec  = aSec;
    sTimeVal.tv_usec = 0;

    (void)select(0, NULL, NULL, NULL, &sTimeVal);
}

/* sleeps @a aMsec millisecond(s) */
DKP_INLINE void dksSleepMsec(DKP_UInt aMsec)
{
    struct timeval sTimeVal;

    sTimeVal.tv_sec  = aMsec / 1000;
    sTimeVal.tv_usec = (aMsec % 1000) * 1000;

    (void)select(0, NULL, NULL, NULL, &sTimeVal);
}

/* sleeps @a aUsec microsecond(s) */
DKP_INLINE void dksSleepUsec(DKP_UInt aUsec)
{
    struct timeval sTimeVal;

    sTimeVal.tv_sec  = aUsec / 1000000;
    sTimeVal.tv_usec = aUsec % 1000000;

    (void)select(0, NULL, NULL, NULL, &sTimeVal);
}

#endif /* _O_DKS_SLEEP_H_ */
