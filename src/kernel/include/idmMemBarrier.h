/*******************************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id$
 ******************************************************************************/

#if !defined(_O_DKM_MEM_BARRIER_H_)
#define _O_DKM_MEM_BARRIER_H_ 1

#include <idsTypes.h>

void dkmMemBarrier(void);
void dkmMemRBarrier(void);
void dkmMemWBarrier(void);
void dkmMemPrefetch(void* aPointer);
void dkmMemPrefetch0(void* aPointer);
void dkmMemPrefetch1(void* aPointer);
void dkmMemPrefetch2(void* aPointer);
void dkmMemPrefetchN(void* aPointer);

#define DKM_MEM_BARRIER()
#define DKM_MEM_RBARRIER()
#define DKM_MEM_WBARRIER()
#define DKM_MEM_PREFETCH0(aPointer) IDS_UNUSED(aPointer)
#define DKM_MEM_PREFETCH1(aPointer) IDS_UNUSED(aPointer)
#define DKM_MEM_PREFETCH2(aPointer) IDS_UNUSED(aPointer)
#define DKM_MEM_PREFETCHN(aPointer) IDS_UNUSED(aPointer)
#define DKM_MEM_PREFETCH DKM_MEM_PREFETCH0

#endif /* _O_DKM_MEM_BARRIER_H_ */
