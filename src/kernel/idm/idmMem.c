/***********************************************************************
 * Copyright 1999-2016 ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#include <idmMem.h>

IDS_RC idmMemAlloc( void **aAddress, IDS_Size aSize )
{
	IDS_TEST( (aAddress == NULL) || (aSize == 0) );

	*aAddress = malloc(aSize);

	IDS_TEST( *aAddress == NULL );

	return IDS_SUCCESS;

	IDS_EXCEPTION_END;

	return IDS_FAILURE;
}

IDS_RC idmMemFree( void *aAddr )
{
	IDS_TEST( aAddr == NULL );

	free(aAddr);

	return IDS_SUCCESS;

	IDS_EXCEPTION_END;

	return IDS_FAILURE;
}
