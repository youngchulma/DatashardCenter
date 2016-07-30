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
IDS_INLINE IDS_RC idmMemSet( void *aAddress, IDS_UInt8 aValue, IDS_Size aSize )
{
    IDS_TEST_RAISE( (aAddress == NULL) || (aSize <= 0), ERR_EINVAL );

	memset(aAddress, (ids_sint32)aValue & 0xFF, aSize);

	return IDS_SUCCESS;

	IDS_EXCEPTION(ERR_EINVAL)
	{
		return IDS_EINVAL;
	}
	IDS_EXCEPTION_END;

	return IDS_FAILURE;
}

/* Copy the memory */
IDS_INLINE IDS_RC idmMemCpy( void *aDest, const void *aSrc, IDS_Size aSize )
{
	IDS_TEST_RAISE( (aDest == NULL) || (aSize <= 0), ERR_EINVAL );

	memcpy(aDest, aSrc, aSize);

	return IDS_SUCCESS;

	IDS_EXCEPTION(ERR_EINVAL)
	{
    	return IDS_EINVAL;
	}
	IDS_EXCEPTION_END;

	return IDS_FAILURE;
}

/* Compares bytes in memory */
IDS_INLINE IDS_RC idmMemCmp( const void *aAddr1, const void *aAddr2, IDS_Size aSize )
{
	IDS_TEST_RAISE( (aAddr1 == NULL) || (aAddr2 == NULL) || (aSize <= 0), ERR_EINVAL );

	memcmp(aAddr1, aAddr2, aSize);

	return IDS_SUCCESS;

	IDS_EXCEPTION(ERR_EINVAL)
	{
    	return IDS_EINVAL;
	}
	IDS_EXCEPTION_END;

	return IDS_FAILURE;
}

#endif /* _O_IDM_MEMORY_H_ */
