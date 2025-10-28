/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:17:39 by nbodin            #+#    #+#             */
/*   Updated: 2025/10/28 19:19:07 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <iostream>
#include <cmath>


//CONSTRUCTORS, COPY CONSTRUCTORS, DESTRUCTORS
Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int n) : _value(n << _frac_bits) {}

Fixed::Fixed(const float n) : _value(roundf(n * (1 << _frac_bits))) {}

Fixed::Fixed(const Fixed &obj) : _value(obj._value) {}

Fixed::~Fixed() {}

//FUNCTIONS
int Fixed::getRawBits() const
{
    return (this->_value);            
}

void   Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float   Fixed::toFloat(void) const
{
    return ((float)this->_value / (1 << this->_frac_bits));
}

int   Fixed::toInt(void) const
{
    return (this->_value >> this->_frac_bits);
}


//OPERATOR OVERLOADS
Fixed&  Fixed::operator=(const Fixed& obj)
{
    this->_value = obj._value;
    return (*this);
}

std::ostream&   operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return (os);
}

bool  Fixed::operator>(const Fixed& obj) const
{
    return (this->_value > obj._value);
}

bool  Fixed::operator<(const Fixed& obj) const
{
    return (!(*this > obj) && *this != obj);
}

bool  Fixed::operator>=(const Fixed& obj) const
{
    return (*this > obj || *this == obj);
}

bool  Fixed::operator<=(const Fixed& obj) const
{
    return (*this < obj || *this == obj);
}

bool  Fixed::operator==(const Fixed& obj) const
{
    return (this->_value == obj._value);
}

bool  Fixed::operator!=(const Fixed& obj) const
{
    return (!(*this == obj));
}

Fixed Fixed::operator+(const Fixed& obj) const
{
    Fixed result;
    
    result.setRawBits(this->_value + obj._value);
    return (result);
}

Fixed Fixed::operator-(const Fixed& obj) const
{
    Fixed result;
    
    result.setRawBits(this->_value - obj._value);
    return (result);
}

Fixed Fixed::operator*(const Fixed& obj) const
{
    Fixed result;
    
    result.setRawBits((this->_value * obj._value) >> this->_frac_bits);
    return (result);
}

Fixed Fixed::operator/(const Fixed& obj) const
{
    Fixed result;
    
    result.setRawBits((this->_value << this->_frac_bits) / obj._value);
    return (result);
}

Fixed&  Fixed::operator++()
{
    this->_value += 1;
    return (*this);
}

Fixed  Fixed::operator++(int)
{
    Fixed  temp(*this);
    ++(*this);
    return (temp);
}

Fixed&  Fixed::operator--()
{
    this->_value -= 1;
    return (*this);
}

Fixed  Fixed::operator--(int)
{
    Fixed   temp(*this);
    --(*this);
    return (temp);
}