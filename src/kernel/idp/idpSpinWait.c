/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#include <idpSpinWait.h>

static IDS_SInt gIdpSpinWaitDefaultSpinCount = IDP_SPIN_WAIT_DEFAULT_SPIN_COUNT;

IDS_SInt idpSpinWaitGetDefaultSpinCount(void)
{
    return gIdpSpinWaitDefaultSpinCount;
}

void idpSpinWaitSetDefaultSpinCount( IDS_SInt aSpinCount )
{
    gIdpSpinWaitDefaultSpinCount = aSpinCount;
}
