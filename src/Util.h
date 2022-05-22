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

template<typename itype>
constexpr bool is_signed()
{
    return ((itype(0) - 1) < 0);
}


//allows left shifting such that the sign remains the same for signed integers
template<typename itype>
inline constexpr itype lshift(const itype value, const u8 amount)
{
    if(is_signed<itype>())
    {
        const itype sign = value < 0? -1:1;
        return ((value*sign) << amount) * sign;
    }
    return value << amount;
}


//allows right shifting such that the sign remains the same for signed integers
template<typename itype>
inline constexpr itype rshift(const itype value, const u8 amount)
{
    if(is_signed<itype>())
    {
        const itype sign = value < 0? -1:1;
        return ((value*sign) >> amount) * sign;
    }
    return value >> amount;
}


//shifts the upper half down
template<typename itype>
inline constexpr itype upper_half(const itype val)
{
    return rshift<itype>(val, sizeof(itype) << 2);
}

template<typename itype>
inline constexpr itype lower_half(const itype val)
{
    return lshift<itype>(val, sizeof(itype) << 2);
}

#endif