/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id:
 ******************************************************************************/

#include <idmMemBarrier.h>

void dkmMemBarrier()
{
    DKM_MEM_BARRIER();
}

void dkmMemRBarrier()
{
    DKM_MEM_RBARRIER();
}

void dkmMemWBarrier()
{
    DKM_MEM_WBARRIER();
}

void dkmMemPrefetch0(void* aPointer)
{
    DKM_MEM_PREFETCH0(aPointer);
}

void dkmMemPrefetch1(void* aPointer)
{
    DKM_MEM_PREFETCH1(aPointer);
}

void dkmMemPrefetch2(void* aPointer)
{
    DKM_MEM_PREFETCH2(aPointer);
}

void dkmMemPrefetchN(void* aPointer)
{
    DKM_MEM_PREFETCHN(aPointer);
}

void dkmMemPrefetch(void* aPointer)
{
    DKM_MEM_PREFETCH(aPointer);
}
