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

    template<u8 pr, u8 po, bool s>
    friend std::ostream& operator<<(std::ostream& o, const Fixed<pr, po, s>&);

public:
    static constexpr itype s_unity = itype(1) << post;

    Fixed(): Base() {}

    Fixed(const double value);

};

template<u8 pre, u8 post, bool is_signed>
Fixed<pre, post, is_signed>::Fixed(const double value):
    Base{round<double, itype>(value) * s_unity}
{
    
}

template<u8 pre, u8 post, bool is_signed>
std::ostream& operator<<(std::ostream& o, const Fixed<pre, post, is_signed>& f)
{
    using Fixed = Fixed<pre, post, is_signed>;
    using Base = typename Fixed::Base;

    const Base* base = reinterpret_cast<const Base *>(&f);

    o << double(base->m_data)/double(Fixed::s_unity);
    return o;
}


#endif