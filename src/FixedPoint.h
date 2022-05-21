#ifndef FIXED_POINT_TYPES_H
#define FIXED_POINT_TYPES_H

#include "Base.h"
#include <iostream>

template<u8 pre, u8 post, bool is_signed>
class Fixed: public FixedBase<bit_count(pre + post), is_signed>
{
    static constexpr u8 n_bits = bit_count(pre + post);

    using Base = FixedBase<n_bits, is_signed>;
    using itype = typename Base::itype;

    static constexpr itype s_unity = itype(1) << post;

    Fixed();

    template<typename numeric>
    Fixed(const numeric value);
};

template<u8 pre, u8 post, bool is_signed>
std::ostream& operator<<(std::ostream& o, const Fixed<pre, post, is_signed>& f)
{
    using Fixed = Fixed<pre, post, is_signed>;
    return o;
}


#endif