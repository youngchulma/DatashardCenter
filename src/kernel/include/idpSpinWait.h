/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_IDP_SPIN_WAIT_H_)
#define _O_IDP_SPIN_WAIT_H_ 1

#include <idpSleep.h>

#define IDP_SPIN_WAIT_DEFAULT_SPIN_COUNT        (1000)
#define IDP_SPIN_WAIT_SLEEP_TIME_MIN            (200)
#define IDP_SPIN_WAIT_SLEEP_TIME_MAX            (100000)

IDS_SInt idpSpinWaitGetDefaultSpinCount(void);
void     idpSpinWaitSetDefaultSpinCount(IDS_SInt aSpinCount);

/**
 * spin wait until the expression is true.
 */
#define IDP_SPIN_WAIT(aExpr, aSpinCount)                                    \
    do                                                                      \
    {                                                                       \
        IDS_SInt sSpinLoop_MACRO_LOCAL_VAR;                                 \
        IDS_SInt sSpinCount_MACRO_LOCAL_VAR;                                \
        IDS_Uint sSpinSleepTime_MACRO_LOCAL_VAR;                            \
                                                                            \
        if ((aSpinCount) < 0)                                               \
        {                                                                   \
            sSpinCount_MACRO_LOCAL_VAR = idpSpinWaitGetDefaultSpinCount();  \
        }                                                                   \
        else                                                                \
        {                                                                   \
            sSpinCount_MACRO_LOCAL_VAR = (aSpinCount);                      \
        }                                                                   \
                                                                            \
        for (sSpinLoop_MACRO_LOCAL_VAR = 0;                                 \
             sSpinLoop_MACRO_LOCAL_VAR < sSpinCount_MACRO_LOCAL_VAR;        \
             sSpinLoop_MACRO_LOCAL_VAR++)                                   \
        {                                                                   \
            if (aExpr)                                                      \
            {                                                               \
                break;                                                      \
            }                                                               \
            else                                                            \
            {                                                               \
            }                                                               \
        }                                                                   \
                                                                            \
        if (sSpinLoop_MACRO_LOCAL_VAR >= sSpinCount_MACRO_LOCAL_VAR)        \
        {                                                                   \
            sSpinSleepTime_MACRO_LOCAL_VAR = IDP_SPIN_WAIT_SLEEP_TIME_MIN;  \
                                                                            \
            while (!(aExpr))                                                \
            {                                                               \
                idpSleepUsec(sSpinSleepTime_MACRO_LOCAL_VAR);               \
                                                                            \
                if (sSpinSleepTime_MACRO_LOCAL_VAR >=                       \
                    (IDP_SPIN_WAIT_SLEEP_TIME_MAX / 2))                     \
                {                                                           \
                    sSpinSleepTime_MACRO_LOCAL_VAR =                        \
                        DIP_SPIN_WAIT_SLEEP_TIME_MAX;                       \
                }                                                           \
                else                                                        \
                {                                                           \
                    sSpinSleepTime_MACRO_LOCAL_VAR *= 2;                    \
                }                                                           \
            }                                                               \
        }                                                                   \
        else                                                                \
        {                                                                   \
        }                                                                   \
    } while (0)

#endif /* _O_IDP_SPIN_WAIT_H_ */

