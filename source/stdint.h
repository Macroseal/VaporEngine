#pragma once

#if _MSC_VER && (_MSC_VER < 1300)
#define __STDINT_LONGLONG           __int64
#else
#define __STDINT_LONGLONG           long long
#endif

/* 7.18.1.1  Exact-width integer types */
typedef signed char int8_t;
typedef unsigned char   uint8_t;
typedef short  int16_t;
typedef unsigned short  uint16_t;
typedef int  int32_t;
typedef unsigned   uint32_t;
typedef __STDINT_LONGLONG  int64_t;
typedef unsigned __STDINT_LONGLONG   uint64_t;