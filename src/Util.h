#ifndef FIXED_POINT_UTIL
#define FIXED_POINT_UTIL

#include <stdint.h>

typedef uint8_t u8;
typedef int8_t  i8;
typedef uint16_t u16;
typedef int16_t  i16;
typedef uint32_t u32;
typedef int32_t  i32;
typedef uint64_t u64;
typedef int64_t  i64;

constexpr u8 bit_count(const u8 n_bits)
{
    constexpr u8 reference [8] = 
    {
        8, 16, 32, 32, 64, 64, 64, 64
    };

    return n_bits? reference[(n_bits >> 3) + bool(n_bits & 7) - 1]: 0;
}

template<typename ftype, typename itype>
constexpr itype round(const ftype val)
{
    return static_cast<itype>(val + ftype(0.5));
}

#endif