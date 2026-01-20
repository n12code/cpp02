/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:29:18 by nbodin            #+#    #+#             */
/*   Updated: 2026/01/20 16:25:34 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0)
{
    std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _value(n << _frac_bits)
{
    std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _value(roundf(n * (1 << _frac_bits)))
{
    std::cout << "float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) : _value(obj._value)
{
    std::cout << "copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << "copy assignement operator called" << std::endl;
    this->_value = obj._value;
    return (*this);
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);            
}

void   Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return (os);
}