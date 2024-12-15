/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:36:43 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/15 15:45:33 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		~Fixed();

		// Operators overload
		Fixed	&operator=(const Fixed &other);

		// Comparison operators
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		// Arithmetic operators
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		// Increment and decrement operators
		Fixed	&operator++(); // prefix
		Fixed	operator++(int); // postfix
		Fixed	&operator--(); // prefix
		Fixed	operator--(int); // postfix

		// Methods to convert Fixed to int or float
		int		toInt() const;
		float	toFloat() const;

		// Static methods
		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		// Getters and setters
		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

// Non-member functions
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);