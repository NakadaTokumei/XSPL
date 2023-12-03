#ifndef __DEF_H__
#define __DEF_H__

#define _WEAK           __attribute__((weak))

typedef void            VOID, *PVOID;

typedef bool            BOOL;

typedef signed char     INT8;
typedef signed short    INT16;
typedef signed long     INT32;

typedef unsigned char   UINT8;
typedef unsigned short  UINT16;
typedef unsigned long   UINT32;

#define BIT_CLEAR(IN, VAL, POS) (IN &= ~(VAL << POS))
#define BIT_FILL(IN, VAL, POS) (IN |= (VAL << POS))

namespace xdef
{

inline UINT32 
bitShift(UINT32 pos)
{
    return static_cast<UINT32>(0x01 << pos);
}

inline UINT32
integerShift(
    UINT32 val, 
    UINT32 pos)
{
    return static_cast<UINT32>(val << pos);   
}

using nullptr_t = decltype(nullptr);

}

#endif