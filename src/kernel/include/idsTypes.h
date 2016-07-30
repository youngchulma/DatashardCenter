/***********************************************************************
 * Copyright 1999-2016, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id$
 **********************************************************************/
#if !defined(_O_IDS_TYPES_H_)
#define _O_IDS_TYPES_H_ 1

#include <idsConfig.h>

#define IDS_SIZEOF(a) ((UInt)sizeof(a))

/* Character Type */
typedef char                  ids_schar;
typedef unsigned char         ids_uchar;

typedef ids_schar             IDS_SChar;
typedef ids_uchar             IDS_UChar;

/* Integer Type */
/* 1-byte signed/unsigned integer type */
typedef signed char           ids_sint8;
typedef unsigned char         ids_uint8;

typedef ids_sint8             IDS_SInt8;
typedef ids_uint8             IDS_UInt8;

/* 2-byte signed/unsigned integer type */
typedef signed short          ids_sint16;
typedef unsigned short        ids_uint16;

typedef ids_sint16            IDS_SShort;
typedef ids_uint16            IDS_UShort;

/* 4-byte signed/unsigned integer type */
typedef signed int            ids_sint32;
typedef unsigned int          ids_uint32;

typedef ids_sint32            IDS_SInt;
typedef ids_uint32            IDS_UInt;

/* 16-byte signed/unsigned integer type */
typedef signed long long      ids_sint64;
typedef unsigned long long    ids_uint64;

typedef ids_sint64            IDS_SLong;
typedef ids_uint64            IDS_ULong;

/* Floating Type */
typedef float                 ids_float;
typedef double                ids_double;

typedef ids_float             IDS_Float;
typedef ids_double            IDS_Double;

/* System Type */
typedef key_t                 ids_key;
typedef ids_key               IDS_Key;

typedef size_t                ids_size;
typedef ids_size              IDS_Size;

typedef ssize_t               ids_ssize;
typedef ids_ssize             IDS_Ssize;

typedef off_t                 ids_offset;
typedef ids_offset            IDS_Offset;

/* file and shared memory permission type */
typedef mode_t                ids_mode;
typedef ids_mode              IDS_Mode;

/* Boolean Type */
typedef ids_uint8             ids_bool;
typedef ids_bool              IDS_Bool;
#define IDS_FALSE             ((ids_bool)0)
#define IDS_TRUE              ((ids_bool)1)

/* Return Type */
typedef ids_sint32            IDS_RC;

/* Printf formats */
#define IDS_INT32_FMT         "d"
#define IDS_UINT32_FMT        "u"
#define IDS_INT64_FMT         "lld"
#define IDS_UINT64_FMT        "llu"

#define IDS_UNUSED(aVar) (void)(aVar)

/* Inline function */
#if defined(__GNUC__)
#define IDS_INLINE static __inline__
#elif ((__GNUC__) > 3 || ((__GNUC__ == 3) && (__GNUC_MINOR__ > 0)))
#define IDS_INLINE static __inline__ __attribute__((always_inline))
#else
#define IDS_INLINE static __inline__
#endif

/* MIN / MAX */
#define IDS_MAX(a,b) ((a) > (b) ? (a) : (b))
#define IDS_MIN(a,b) ((a) < (b) ? (a) : (b))

#endif /*_O_IDS_TYPES_H_ */
