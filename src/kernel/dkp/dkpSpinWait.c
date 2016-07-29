/*******************************************************************************
 * Copyright 1999-2007, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id: acpSpinWait.c 3355 2008-10-21 07:56:38Z djin $
 ******************************************************************************/

#include <acpSpinWait.h>

static acp_sint32_t gAcpSpinWaitDefaultSpinCount =
    ACP_SPIN_WAIT_DEFAULT_SPIN_COUNT;

/*
 * Get Spin Counter
 *   */
ACP_EXPORT acp_sint32_t acpSpinWaitGetDefaultSpinCount(void)
{
    return gAcpSpinWaitDefaultSpinCount;
}

/*
 *  * Set Spin Counter
 *   */
ACP_EXPORT void acpSpinWaitSetDefaultSpinCount(acp_sint32_t aSpinCount)
{
    gAcpSpinWaitDefaultSpinCount = aSpinCount;
}
