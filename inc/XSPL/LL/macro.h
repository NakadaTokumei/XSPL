#ifndef __LL_MACRO_H__
#define __LL_MACRO_H__

#define __packed        __attribute__((packed))
#define __weak          __attribute__((weak))

#define __nop           __asm__ volatile("nop":::)
#define __nop_return    return 0

#define _IO volatile

typedef void            VOID, *PVOID;

typedef signed char     INT8;
typedef signed short    INT16;
typedef signed long     INT32;

typedef unsigned char   UINT8;
typedef unsigned short  UINT16;
typedef unsigned long   UINT32;


#endif