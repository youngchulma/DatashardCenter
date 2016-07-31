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
    IDS_RC sRc;

    IDS_TEST_RAISE( aSize == 0, ERR_EINVAL );

	*aAddress = malloc(aSize);

	IDS_TEST_RAISE( *aAddress == NULL, ERR_ENOMEM );

	return IDS_RC_SUCCESS;

    IDS_EXCEPTION( ERR_EINVAL )
    {
        sRc = IDS_RC_EINVAL;
    }
    IDS_EXCEPTION( ERR_ENOMEM )
    {
        sRc = IDS_RC_ENOMEM;
    }
	IDS_EXCEPTION_END;

	return sRc;
}

IDS_RC idmMemCalloc( void **aAddress, 
                     IDS_Size aElement, 
                     IDS_Size aSize )
{
    IDS_RC sRc;

    IDS_TEST_RAISE( (aElement == 0) || (aSize == 0), ERR_EINVAL );

    *aAddress = calloc(aElement, aSize);
    IDS_TEST_RAISE( *aAddress == NULL, ERR_ENOMEM );

    return IDS_RC_SUCCESS;

    IDS_EXCEPTION( ERR_EINVAL )
    {
        sRc = IDS_RC_EINVAL;
    }
    IDS_EXCEPTION( ERR_ENOMEM )
    {
        sRc = IDS_RC_ENOMEM;
    }
    IDS_EXCEPTION_END;

    return sRc;
}

IDS_RC idmMemRealloc( void **aAddress,
                      IDS_Size aSize )
{
    void *sNewAddress = NULL;
    IDS_RC sRc;

    IDS_TEST_RAISE( aSize == 0, ERR_EINVAL );

    sNewAddress = realloc(*aAddress, aSize);
    IDS_TEST_RAISE( sNewAddress == NULL, ERR_ENOMEM );

    *aAddress = sNewAddress;

    return IDS_RC_SUCCESS;

    IDS_EXCEPTION( ERR_EINVAL )
    {
        sRc = IDS_RC_EINVAL;
    }
    IDS_EXCEPTION( ERR_ENOMEM )
    {
        sRc = IDS_RC_ENOMEM;
    }
    IDS_EXCEPTION_END;

    return sRc;
}

IDS_RC idmMemFree( void *aAddr )
{
	free(aAddr);

	return IDS_RC_SUCCESS;
}
