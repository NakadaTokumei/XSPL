#ifndef __LL_MACRO_H__
#define __LL_MACRO_H__

#define __packed        __attribute__((packed))
#define __weak          __attribute__((weak))

#define __nop           __asm__ volatile("nop":::)
#define __nop_return    return 0

#define _IO volatile


#endif