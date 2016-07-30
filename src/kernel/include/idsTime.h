/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_IDS_TIME_H_)
#define _O_IDS_TIME_H_ 1

#include <idsError.h>
#include <idsException.h>

/* number of microseconds since 00:00:00 january 1, 1970 UTC */
typedef IDS_SLong IDS_Time;

/* number of nanoseconds since 00:00:00 january 1, 1970 UTC */
typedef IDS_SLong IDS_HrTime;

/* structure for broken-out time information */
typedef struct IDS_TimeExp
{
    IDS_SInt mUsec;      /**< microseconds (0 - 999,999) */
    IDS_SInt mSec;       /**< seconds (0 - 60)           */
    IDS_SInt mMin;       /**< minutes (0 - 59)           */
    IDS_SInt mHour;      /**< hours (0 - 23)             */
    IDS_SInt mDay;       /**< day of month (1 - 31)      */
    IDS_SInt mMonth;     /**< month of year (1 - 12)     */
    IDS_SInt mYear;      /**< year                       */
    IDS_SInt mDayOfWeek; /**< day of week (Sunday = 0)   */
    IDS_SInt mDayOfYear; /**< day of year (1 - 366)      */
} IDS_Time_Exp;

/* indicates whether the time value is absolute or relative */
typedef enum IDS_TimeType
{
    IDS_TIME_ABS = 0, /**< the time value is absolute */
    IDS_TIME_REL      /**< the time value is relative */
} IDS_TimeType;

/* no-wait timeout value */
#define IDS_TIME_IMMEDIATE ((IDS_Time)0)

/* infinite timeout value */
#define IDS_TIME_INFINITE  ((IDS_Time)IDS_SINT64_MAX)

/* MICRO SECONDS BASED FUNCTIONS */

/* gets the second portion of the time value */
IDS_INLINE IDS_SLong idsTimeGetSec( IDS_Time aTime )
{
    return ((aTime / IDS_SINT64_LITERAL(1000000)) % IDS_SINT64_LITERAL(60));
}

/* gets the millisecond portion of the time value */
IDS_INLINE IDS_SLong idsTimeGetMsec( IDS_Time aTime )
{
    return ((aTime / IDS_SINT64_LITERAL(1000)) % IDS_SINT64_LITERAL(1000));
}

/* gets the microsecond portion of the time value */
IDS_INLINE IDS_SLong idsTimeGetUsec( IDS_Time aTime )
{
    return (aTime % IDS_SINT64_LITERAL(1000000));
}

/* gets the time value in seconds */
IDS_INLINE IDS_SLong idsTimeToSec( IDS_Time aTime )
{
    return (aTime / IDS_SINT64_LITERAL(1000000));
}

/* gets the time value in milliseconds */
IDS_INLINE IDS_SLong idsTimeToMsec( IDS_Time aTime )
{
    return (aTime / IDS_SINT64_LITERAL(1000));
}

/* gets the time value in microseconds */
IDS_INLINE IDS_SLong idsTimeToUsec( IDS_Time aTime )
{
    return aTime;
}

/* makes time value from seconds */
IDS_INLINE IDS_Time idsTimeFromSec( IDS_SLong aSec )
{
    return ((IDS_Time)aSec * IDS_SINT64_LITERAL(1000000));
}

/* makes time value from milliseconds */
IDS_INLINE IDS_Time idsTimeFromMsec( IDS_SLong aMsec )
{
    return ((IDS_Time)aMsec * IDS_SINT64_LITERAL(1000));
}

/* makes time value from microseconds */
IDS_INLINE IDS_Time idsTimeFromUsec( IDS_SLong aUsec )
{
    return (IDS_Time)aUsec;
}

/* makes time value from seconds and microseconds */
IDS_INLINE IDS_Time idsTimeFrom( IDS_SLong aSec, IDS_SLong aUsec )
{
    return (IDS_Time)(aSec * IDS_SINT64_LITERAL(1000000) + aUsec);
}

/* NANO SECONDS BASED FUNCTIONS */
/* gets the second portion of the time value */
IDS_INLINE IDS_SLong idsTimeHiResGetSec( IDS_HrTime aTime )
{
    return (aTime / IDS_SINT64_LITERAL(1000000000));
}

/* gets the millisecond portion of the time value */
IDS_INLINE IDS_SLong idsTimeHiResGetMsec( IDS_HrTime aTime )
{
    return ((aTime / IDS_SINT64_LITERAL(1000000))
            % IDS_SINT64_LITERAL(1000));
}

/* gets the microsecond portion of the time value */
IDS_INLINE IDS_SLong idsTimeHiResGetUsec( IDS_HrTime aTime )
{
    return ((aTime / IDS_SINT64_LITERAL(1000))
            % IDS_SINT64_LITERAL(1000000));
}

/* gets the time value in seconds */
IDS_INLINE IDS_SLong idsTimeHiResToSec( IDS_HrTime aTime )
{
    return (aTime / IDS_SINT64_LITERAL(1000000000));
}

/* gets the time value in milliseconds */
IDS_INLINE IDS_SLong idsTimeHiResToMsec( IDS_HrTime aTime )
{
    return (aTime / IDS_SINT64_LITERAL(1000000));
}

/* gets the time value in microseconds */
IDS_INLINE IDS_SLong idsTimeHiResToUsec( IDS_HrTime aTime )
{
    return (aTime / IDS_SINT64_LITERAL(1000));
}

/* gets the time value in nanoseconds */
IDS_INLINE IDS_SLong idsTimeHiResToNsec( IDS_HrTime aTime )
{
    return aTime;
}

/* makes time value from seconds */
IDS_INLINE IDS_HrTime idsTimeHiResFromSec( IDS_SLong aSec )
{
    return ((IDS_HrTime)aSec * IDS_SINT64_LITERAL(1000000000));
}

/* makes time value from milliseconds */
IDS_INLINE IDS_HrTime idsTimeHiResFromMsec( IDS_SLong aMsec )
{
    return ((IDS_HrTime)aMsec * IDS_SINT64_LITERAL(1000000));
}

/* makes time value from microseconds */
IDS_INLINE IDS_HrTime idsTimeHiResFromUsec( IDS_SLong aUsec )
{
    return ((IDS_HrTime)aUsec * IDS_SINT64_LITERAL(1000));
}

/* makes time value from seconds and microseconds */
IDS_INLINE IDS_HrTime idsTimeHiResFrom( IDS_SLong aSec, IDS_SLong aNsec )
{
    return (IDS_HrTime)(aSec * IDS_SINT64_LITERAL(1000000000) + aNsec);
}

#endif
