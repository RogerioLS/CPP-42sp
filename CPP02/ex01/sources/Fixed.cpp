/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:58:54 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/15 14:08:43 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/**
 * @brief Construct a new Fixed:: Fixed object
 */
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 */
Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = intValue << _fractionalBits;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 */
Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 * @param other
 */
Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_fixedPointValue = other._fixedPointValue;
}

/**
 * @brief Destroy the Fixed:: Fixed object
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Returns the raw value of the fixed point value
 * 
 * @return int
 */
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fixedPointValue = other._fixedPointValue;

	return (*this);
}

/**
 * @brief Returns the raw value of the fixed point value
 * 
 * @return int
 */
float Fixed::toFloat() const
{
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

/**
 * @brief Returns the integer value of the fixed point value
 * 
 * @return int
 */
int Fixed::toInt() const
{
	return _fixedPointValue >> _fractionalBits;
}

/**
 * @brief Returns the raw value of the fixed point value
 * 
 * @return int 
 */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
