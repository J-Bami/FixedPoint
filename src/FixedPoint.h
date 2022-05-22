#ifndef FIXED_POINT_TYPES_H
#define FIXED_POINT_TYPES_H

#include "Base.h"
#include <iostream>

template<u8 pre, u8 post, bool is_signed>
class Fixed: public FixedBase<bit_count(pre + post), is_signed>
{
    static constexpr u8 n_bits = bit_count(pre + post + is_signed);

    using Base = FixedBase<n_bits, is_signed>;
    using itype = typename Base::itype;

    template<u8 pr, u8 po, bool s>
    friend std::ostream& operator<<(std::ostream& o, const Fixed<pr, po, s>&);

public:
    static constexpr itype s_unity = itype(1) << post;

    Fixed(): Base() {}

    Fixed(const double value);

    Fixed(const itype data); //this should really be protected.

    //define conversions to numeric types
    operator float() const;

    operator double() const;

    //define arithmetic and comparison operators
    template<u8 pr, u8 po, bool s>
    friend Fixed<pr, po, s> operator+(const Fixed<pr, po, s>, const Fixed<pr, po, s>);

    template<u8 pr, u8 po, bool s>
    friend Fixed<pr, po, s> operator-(const Fixed<pr, po, s>, const Fixed<pr, po, s>);

    template<u8 pr, u8 po, bool s>
    friend Fixed<pr, po, s> operator*(const Fixed<pr, po, s>, const Fixed<pr, po, s>);

    template<u8 pr, u8 po, bool s>
    friend Fixed<pr, po, s> operator/(const Fixed<pr, po, s>, const Fixed<pr, po, s>);

};


template<u8 pre, u8 post, bool is_signed>
Fixed<pre, post, is_signed>::Fixed(const double value):
    Base{round<double, itype>(value * s_unity)}
{

}


template<u8 pre, u8 post, bool is_signed>
Fixed<pre, post, is_signed>::Fixed(const itype data):
    Base{data}
{

}


template<u8 pre, u8 post, bool is_signed>
Fixed<pre, post, is_signed>::operator float()const
{
    return float(this->m_data)/float(s_unity);
}

template<u8 pre, u8 post, bool is_signed>
Fixed<pre, post, is_signed>::operator double()const
{
    return double(this->m_data)/double(s_unity);
}

template<u8 pre, u8 post, bool is_signed>
Fixed<pre, post, is_signed> operator+(
    const Fixed<pre, post, is_signed> f1,
    const Fixed<pre, post, is_signed> f2)
{
    using Fixed = Fixed<pre, post, is_signed>;
    using itype = typename Fixed::itype;
    itype result = f1.m_data + f2.m_data;
    return Fixed(result);
}


template<u8 pre, u8 post, bool is_signed>
Fixed<pre, post, is_signed> operator-(
    const Fixed<pre, post, is_signed> f1,
    const Fixed<pre, post, is_signed> f2)
{
    using Fixed = Fixed<pre, post, is_signed>;
    using itype = typename Fixed::itype;
    const itype result = f1.m_data - f2.m_data;
    return Fixed(result);
}


template<u8 pre, u8 post, bool is_signed>
Fixed<pre, post, is_signed> operator*(
    const Fixed<pre, post, is_signed> f1,
    const Fixed<pre, post, is_signed> f2)
{
    using Fixed = Fixed<pre, post, is_signed>;
    using itype = typename Fixed::itype;
    constexpr u8 half_n = Fixed::n_bits >> 1;

    //decompose the inputs
    const itype upper1 = upper_half(f1.m_data);
    const itype upper2 = upper_half(f2.m_data);
    const itype lower1 = lower_half(f1.m_data);
    const itype lower2 = lower_half(f2.m_data);

    const itype upper = upper1 * upper2;
    const itype middle1 = upper1 * lower2;
    const itype middle2 = upper2 * lower1;
    const itype lower = lower2 * lower1;

    //the full result is this
    const itype result = lshift(upper, pre) + (middle1 + middle2) + rshift(lower, post);
    return Fixed(result);
}




template<u8 pre, u8 post, bool is_signed>
std::ostream& operator<<(std::ostream& o, const Fixed<pre, post, is_signed>& f)
{
    o << double(f);
    return o;
}


#endif