/*******************************************************************************
 * Copyright 1999-2007, ALTIBASE Corporation or its subsidiaries.
 * All rights reserved.
 ******************************************************************************/

/*******************************************************************************
 * $Id:
 ******************************************************************************/

#if !defined(_O_IDP_ATOMIC_H_)
#define _O_IDP_ATOMIC_LINUX_H_ 1

#include<idsTypes.h> 

IDS_INLINE IDS_SShort idpAtomicCas16( volatile void      *aAddr,
                                      volatile IDS_SShort aWith,
                                      volatile IDS_SShort aCmp )
{
    IDS_SShort sPrev;
    __asm__ __volatile__ ("lock; cmpxchgw %1,%2"
                          : "=a"(sPrev)
                          : "q"(aWith),
                            "m"(*(volatile IDS_SShort *)aAddr),
                            "0"(aCmp)
                          : "memory");
    return sPrev;
}

IDS_INLINE IDS_SShort idpAtomicSet16( volatile void      *aAddr,
                                      volatile IDS_SShort aVal )
{
    __asm__ __volatile__ ("xchgw %0,%1"
                          : "=r"(aVal)
                          : "m"(*(volatile IDS_SShort *)aAddr), "0"(aVal)
                          : "memory");
    return aVal;
}

IDS_INLINE IDS_SShort idpAtomicAdd16( volatile void      *aAddr,
                                      volatile IDS_SShort aVal )
{
    IDS_SShort sTemp = aVal;
    __asm__ __volatile__ ("lock; xaddw %0,%1"
                          : "+r"(sTemp), "+m"(*(volatile IDS_SShort *)aAddr)
                          :
                          : "memory");
    return sTemp + aVal;
}

IDS_INLINE IDS_SInt idpAtomicCas32( volatile void      *aAddr,
                                    volatile IDS_SShort aWith,
                                    volatile IDS_SShort aCmp )
{
    IDS_SInt sPrev;

    __asm__ __volatile__ ("lock; cmpxchgl %1,%2"
                          : "=a"(sPrev)
                          : "r"(aWith),
                            "m"(*(volatile IDS_SInt *)aAddr),
                            "0"(aCmp)
                          : "memory");
    return sPrev;
}

IDS_INLINE IDS_SInt idpAtomicSet32( volatile void    *aAddr,
                                    volatile IDS_SInt aVal )
{
    __asm__ __volatile__ ("xchgl %0,%1"
                          : "=r"(aVal)
                          : "m"(*(volatile IDS_SInt *)aAddr), "0"(aVal)
                          : "memory");
    return aVal;
}

IDS_INLINE IDS_SInt idpAtomicAdd32( volatile void    *aAddr,
                                    volatile IDS_SInt aVal )
{
    IDS_SInt sTemp = aVal;
    __asm__ __volatile__ ("lock; xaddl %0,%1"
                          : "+r"(sTemp), "+m"(*(volatile IDS_SInt *)aAddr)
                          :
                          : "memory");
    return sTemp + aVal;
}

IDS_INLINE IDS_SLong idpAtomicCas64( volatile void         *aAddr,
                                     volatile IDS_SLong  aWith,
                                     volatile IDS_SLong  aCmp)
{
    IDS_SLong sPrev;
    __asm__ __volatile__ ("lock; cmpxchgq %1,%2"
                          : "=a"(sPrev)
                          : "r"(aWith),
                            "m"(*(volatile IDS_SLong *)aAddr),
                            "0"(aCmp)
                          : "memory");
    return sPrev;
}

IDS_INLINE IDS_SLong idpAtomicGet64( volatile void *aAddr )
{
    //IDP_MEM_BARRIER();

    return *(volatile IDS_SLong *)aAddr;
}

IDS_INLINE IDS_SLong idpAtomicSet64( volatile void     *aAddr,
                                     volatile IDS_SLong aVal )
{
    __asm__ __volatile__ ("xchgq %0,%1"
                          : "=r"(aVal)
                          : "m"(*(volatile IDS_SLong *)aAddr), "0"(aVal)
                          : "memory");
    return aVal;
}

IDS_INLINE IDS_SLong idpAtomicAdd64( volatile void     *aAddr,
                                     volatile IDS_SLong aVal )
{
    IDS_SLong sPrev = aVal;
    __asm__ __volatile__ ("lock; xaddq %0,%1"
                          : "+r"(sPrev), "+m"(*(volatile IDS_SLong *)aAddr)
                          :
                          : "memory");
    return sPrev + aVal;
}

#endif
