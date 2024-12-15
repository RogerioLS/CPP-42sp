/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:51:09 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/15 14:08:37 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(Fixed const &other);
		~Fixed();

		Fixed & operator=(Fixed const & rhs);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);