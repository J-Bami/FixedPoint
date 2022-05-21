#ifndef UNDERLYING_FIXED_POINT_TYPES_H
#define UNDERLYING_FIXED_POINT_TYPES_H

#include "Util.h"
/*&
Our fixed point types will be of the type 
Fixed<u8 pre, u8 post, bool signed>

and must use the smallest integer type that can house it
*/

template<u8 bit_count, bool is_signed>
struct FixedBase
{
    using itype = int; //for intellisense reasons
    //static_assert(0, "Fixed point numbers only work with a maximum number of 64 bits");
};

template<>
struct FixedBase<8, 0>{using itype = u8; u8 m_data;};

template<>
struct FixedBase<8, 1>{using itype = i8; i8 m_data;};

template<>
struct FixedBase<16, 0>{using itype = u16; u16 m_data;};

template<>
struct FixedBase<16, 1>{using itype = i16; i16 m_data;};

template<>
struct FixedBase<32, 0>{using itype = u32; u32 m_data;};

template<>
struct FixedBase<32, 1>{using itype = i32; i32 m_data;};

template<>
struct FixedBase<64, 0>{using itype = u64; u64 m_data;};

template<>
struct FixedBase<64, 1>{using itype = i64; i64 m_data;};


#endif 