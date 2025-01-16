#ifndef NONSTD_TYPE_H
#define NONSTD_TYPE_H
#define __NEED_size_t



typedef signed char i8;
typedef signed short int i16;
typedef signed int i32;
typedef signed long long int i64;
typedef signed __int128 i128;
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64; /* https://gcc.gnu.org/onlinedocs/gcc-12.2.0/gcc/Long-Long.html#Long-Long */
typedef unsigned __int128 u128;

typedef unsigned long int size_t;
typedef unsigned char byte;
#endif
