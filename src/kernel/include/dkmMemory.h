/***********************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#if !defined(_O_DKM_MEMORY_H_)
#define _O_DKM_MEMORY_H_ 1

#include <dkpTypes.h>
#include <dkpError.h>
#include <dkpException.h>

DKP_RC dkmMemAlloc( void **aAddress, DKP_Size aSize );
DKP_RC dkmMemCalloc( void **aAddress, DKP_Size aElements, DKP_Size aSize );
DKP_RC dkmMemRealloc( void **aAddress, DKP_Size aSize );

DKP_RC dkmMemFree( void *aAddr );

/* Fills the memory with val */
DKP_INLINE DKP_RC dkmMemSet( void *aAddress, DKP_UInt8 aValue, DKP_Size aSize )
{
    DKP_TEST_RAISE( (aAddress == NULL) || (aSize <= 0), ERR_EINVAL );

	memset(aAddress, (dkp_sint32)aValue & 0xFF, aSize);

	return DKP_SUCCESS;

	DKP_EXCEPTION(ERR_EINVAL)
	{
		return DKP_EINVAL;
	}
	DKP_EXCEPTION_END;

	return DKP_FAILURE;
}

/* Copy the memory */
DKP_INLINE DKP_RC dkmMemCpy( void *aDest, const void *aSrc, DKP_Size aSize )
{
	DKP_TEST_RAISE( (aDest == NULL) || (aSize <= 0), ERR_EINVAL );

	memcpy(aDest, aSrc, aSize);

	return DKP_SUCCESS;

	DKP_EXCEPTION(ERR_EINVAL)
	{
    	return DKP_EINVAL;
	}
	DKP_EXCEPTION_END;

	return DKP_FAILURE;
}

/* Compares bytes in memory */
DKP_INLINE DKP_RC dkmMemCmp( const void *aAddr1, const void *aAddr2, DKP_Size aSize )
{
	DKP_TEST_RAISE( (aAddr1 == NULL) || (aAddr2 == NULL) || (aSize <= 0), ERR_EINVAL );

	memcmp(aAddr1, aAddr2, aSize);

	return DKP_SUCCESS;

	DKP_EXCEPTION(ERR_EINVAL)
	{
    	return DKP_EINVAL;
	}
	DKP_EXCEPTION_END;

	return DKP_FAILURE;
}

#endif /* _O_DKM_MEMORY_H_ */
