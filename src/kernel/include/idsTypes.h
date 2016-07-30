/***********************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/
#if !defined(_O_DKP_TYPES_H_)
#define _O_DKP_TYPES_H_ 1

#include <dkpConfig.h>

#define DKP_SIZEOF(a) ((UInt)sizeof(a))

/* Character Type */
typedef char                  dkp_schar;
typedef unsigned char         dkp_uchar;

typedef dkp_schar             DKP_SChar;
typedef dkp_uchar             DKP_UChar;

/* Integer Type */
/* 1-byte signed/unsigned integer type */
typedef signed char           dkp_sint8;
typedef unsigned char         dkp_uint8;

typedef dkp_sint8             DKP_SInt8;
typedef dkp_uint8             DKP_UInt8;

/* 2-byte signed/unsigned integer type */
typedef signed short          dkp_sint16;
typedef unsigned short        dkp_uint16;

typedef dkp_sint16            DKP_SShort;
typedef dkp_uint16            DKP_UShort;

/* 4-byte signed/unsigned integer type */
typedef signed int			  dkp_sint32;
typedef unsigned int          dkp_uint32;

typedef dkp_sint32            DKP_SInt;
typedef dkp_uint32            DKP_UInt;

/* 16-byte signed/unsigned integer type */
#if defined(DKP_CFG_OS_WIN)

#else

typedef signed long long      dkp_sint64;
typedef unsigned long long    dkp_uint64;

typedef dkp_sint64            DKP_SLong;
typedef dkp_uint64            DKP_ULong;
#endif

/* Floating Type */
typedef float                 dkp_float;
typedef double                dkp_double;

typedef dkp_float             DKP_Float;
typedef dkp_double            DKP_Double;

/* System Type */
typedef key_t                 DKP_Key;
typedef size_t                DKP_Size;
typedef ssize_t               DKP_Ssize;
typedef off_t                 DKP_Offset;

/* Boolean Type */
typedef dkp_uint8             dkp_bool;
typedef dkp_bool              DKP_Bool;
#define DKP_FALSE             ((dkp_bool)0)
#define DKP_TRUE              ((dkp_bool)1)

/* Return Type */
typedef dkp_sint32            DKP_RC;

/* Printf formats */
#define DKP_INT32_FMT         "d"
#define DKP_UINT32_FMT        "u"
#define DKP_INT64_FMT         "lld"
#define DKP_UINT64_FMT        "llu"

/* Inline function */
#if defined(__GNUC__)
#define DKP_INLINE static __inline__
#elif ((__GNUC__) > 3 || ((__GNUC__ == 3) && (__GNUC_MINOR__ > 0)))
#define DKP_INLINE static __inline__ __attribute__((always_inline))
#else
#define DKP_INLINE static __inline__
#endif

/* MIN / MAX */
#define DKP_MAX(a,b) ((a) > (b) ? (a) : (b))
#define DKP_MIN(a,b) ((a) < (b) ? (a) : (b))

#endif /*_O_DKP_TYPES_H_ */
