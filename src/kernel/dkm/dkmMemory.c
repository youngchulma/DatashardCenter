/***********************************************************************
 * Copyright 1999-2016 ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id: dkmMemory.c 34 2016-07-29 09:57:09Z randyma $
 **********************************************************************/

#include <dkmMemory.h>

DKP_RC dkmMemAlloc( void **aAddress, DKP_Size aSize )
{
	DKP_TEST( (aAddress == NULL) || (aSize == 0) );

	*aAddress = malloc(aSize);

	DKP_TEST( *aAddress == NULL );

	return DKP_SUCCESS;

	DKP_EXCEPTION_END;

	return DKP_FAILURE;
}

DKP_RC dkmMemFree( void *aAddr )
{
	DKP_TEST( aAddr == NULL );

	free(aAddr);

	return DKP_SUCCESS;

	DKP_EXCEPTION_END;

	return DKP_FAILURE;
}
