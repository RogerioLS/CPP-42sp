/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:11:26 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/15 12:11:35 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

/**
 * @brief Class that represents a fixed point number.
 * 
 * The number is represented using 8 bits for the fractional part.
 * The number is represented using 23 bits for the integer part.
 * 
 * The number is represented using the following formula:
 * 
 * value = _fixedPointValue / (1 << _fractionalBits)
 * 
 * The number is stored in a 32 bits integer.
 */
class	Fixed
{
	public:
		Fixed();
		~Fixed();
		// Copy constructor from the object Fixed a(b)
		Fixed(const Fixed &other);
		// Assignment operator a = b
		Fixed	&operator=(const Fixed &other);
		int		getRawBits() const;
		void	setRawBits(int const raw);
	
	private:
		// The raw value of the fixed point number.
		int					_fixedPointValue;
		// The number of bits used for the fractional part.
		static const int	_fractionalBits = 8;
};