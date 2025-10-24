/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:48:09 by nbodin            #+#    #+#             */
/*   Updated: 2025/10/24 18:40:12 by nbodin           ###   ########lyon.fr   */
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
        ~Fixed();
        Fixed(const Fixed &obj);
        Fixed &operator=(const Fixed& obj);
        int     getRawBits() const;
        void    setRawBits(int const raw);
};




#endif