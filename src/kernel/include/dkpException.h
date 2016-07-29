/***********************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/

#if !defined(_O_DKP_EXCEPTION_H_)
#define _O_DKP_EXCEPTION_H_ 1

#define DKP_EXCEPTION( aLabel )            \
    goto DKP_EXCEPTION_END_LABEL;          \
    aLabel:

#define DKP_EXCEPTION_END                  \
    DKP_EXCEPTION_END_LABEL:;

#define DKP_TEST( aExpr )                  \
{                                          \
    if ( aExpr )                           \
    {                                      \
        goto DKP_EXCEPTION_END_LABEL;      \
    }                                      \
}

#define DKP_TEST_RAISE( aExpr, aLabel )    \
{                                          \
    if ( aExpr )                           \
    {                                      \
        goto aLabel;                       \
    }                                      \
}

#define DKP_RAISE( aLabel )                \
    goto aLabel;

#endif /*_O_DKP_EXCEPTION_H_ */
