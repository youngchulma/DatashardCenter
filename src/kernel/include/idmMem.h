/***********************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#if !defined(_O_IDM_MEMORY_H_)
#define _O_IDM_MEMORY_H_ 1

#include <idsTypes.h>
#include <idsError.h>
#include <idsException.h>

IDS_RC idmMemAlloc( void **aAddress, IDS_Size aSize );
IDS_RC idmMemCalloc( void **aAddress, IDS_Size aElements, IDS_Size aSize );
IDS_RC idmMemRealloc( void **aAddress, IDS_Size aSize );

IDS_RC idmMemFree( void *aAddr );

/* Fills the memory with val */
IDS_INLINE void idmMemSet( void *aAddress, 
                           IDS_UInt8 aValue, 
                           IDS_Size aSize )
{
    if ( aSize > 0 )
    {
	    memset(aAddress, (ids_sint32)aValue & 0xFF, aSize);
    }
    else
    {
        /* DO NOTHING */
    }
}

/* Copy the memory */
IDS_INLINE void idmMemCpy( void *aDest, 
                           const void *aSrc, 
                           IDS_Size aSize )
{
    if ( aSize > 0 )
    {
	    memcpy(aDest, aSrc, aSize);
    }
    else
    {
        /* DO NOTHING */
    }
}

/* Compares bytes in memory */
IDS_INLINE IDS_RC idmMemCmp( const void *aAddr1, 
                             const void *aAddr2, 
                             IDS_Size aSize )
{
    IDS_RC sRc;

    if ( aSize > 0 )
    {
	    sRc = memcmp(aAddr1, aAddr2, aSize);
    }
    else
    {
        sRc = 0;
    }
    
    return sRc;
}

/* Copy memory */
IDS_INLINE void idsMemMove( void *aDest,
                            const void *aSrc,
                            IDS_Size aSize )
{
    if ( aSize > 0 )
    {
        memmove(aDest, aSrc, aSize);
    }
    else
    {
        /* DO NOTHING */
    }
}

#endif /* _O_IDM_MEMORY_H_ */
