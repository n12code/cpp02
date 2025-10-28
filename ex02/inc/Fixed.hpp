/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:17:35 by nbodin            #+#    #+#             */
/*   Updated: 2025/10/28 19:38:36 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int                 _value;
        static const int    _frac_bits = 8;

    public:
        Fixed();
        Fixed(const int);
        Fixed(const float);
        Fixed(const Fixed &obj);
        ~Fixed();
        
        Fixed&                  operator=(const Fixed& obj);
        
        bool                    operator>(const Fixed& obj) const ;
        bool                    operator<(const Fixed& obj) const ;
        bool                    operator>=(const Fixed& obj) const ;
        bool                    operator<=(const Fixed& obj) const ;
        bool                    operator==(const Fixed& obj) const ;
        bool                    operator!=(const Fixed& obj) const ;

        Fixed                   operator+(const Fixed& obj) const;
        Fixed                   operator-(const Fixed& obj) const;
        Fixed                   operator*(const Fixed& obj) const;
        Fixed                   operator/(const Fixed& obj) const;
        
        Fixed&                  operator++();
        Fixed                   operator++(int);
        Fixed&                  operator--();
        Fixed                   operator--(int);

        int                     getRawBits() const;
        void                    setRawBits(int const raw);
        float                   toFloat(void) const;
        int                     toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif