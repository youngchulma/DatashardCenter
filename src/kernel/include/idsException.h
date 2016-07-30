/***********************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#if !defined(_O_IDS_EXCEPTION_H_)
#define _O_IDS_EXCEPTION_H_ 1

#define IDS_EXCEPTION( aLabel )            \
    goto IDS_EXCEPTION_END_LABEL;          \
    aLabel:

#define IDS_EXCEPTION_END                  \
    IDS_EXCEPTION_END_LABEL:;

#define IDS_TEST( aExpr )                  \
{                                          \
    if ( aExpr )                           \
    {                                      \
        goto IDS_EXCEPTION_END_LABEL;      \
    }                                      \
}

#define IDS_TEST_RAISE( aExpr, aLabel )    \
{                                          \
    if ( aExpr )                           \
    {                                      \
        goto aLabel;                       \
    }                                      \
}

#define IDS_RAISE( aLabel )                \
    goto aLabel;

#endif /*_O_IDS_EXCEPTION_H_ */
