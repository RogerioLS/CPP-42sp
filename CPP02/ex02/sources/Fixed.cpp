/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:41:55 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/16 23:43:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 * @param value 
 */
Fixed::Fixed(): _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 * @param value 
 */
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 * @param value 
 */
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 * @param other 
 */
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/**
 * @brief Destroy the Fixed:: Fixed object
 * 
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return (*this);
}

/**
 * @brief Get the raw bits object
 */
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

/**
 * @brief Set the raw bits object
 * 
 * @param raw 
 */
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

/**
 * @brief Convert Fixed to float
 * 
 * @return float
 */
float Fixed::toFloat() const
{
	return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

/**
 * @brief Convert Fixed to int
 * 
 * @return int 
 */
int Fixed::toInt() const
{
	return this->_fixedPointValue >> _fractionalBits;
}

/**
 * @brief Comparison operator
 */
/**
 * @brief Comparison operator
 * 
 * @param other
 * @return true
 */
bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_fixedPointValue > other._fixedPointValue);
}

/**
 * @brief Comparison operator
 * 
 * @param other
 * @return true
 */
bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_fixedPointValue < other._fixedPointValue);
}

/**
 * @brief Comparison operator
 * 
 * @param other
 * @return true
 */
bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixedPointValue >= other._fixedPointValue);
}

/**
 * @brief Comparison operator
 * 
 * @param other
 * @return true
 */
bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixedPointValue <= other._fixedPointValue);
}

/**
 * @brief Comparison operator
 * 
 * @param other
 * @return true
 */
bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_fixedPointValue == other._fixedPointValue);
}

/**
 * @brief Comparison operator
 * 
 * @param other
 * @return true
 */
bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixedPointValue != other._fixedPointValue);
}

/**
 * @brief Arithmetic operator
 */
/**
 * @brief Arithmetic operator
 * 
 * @param other
 * @return Fixed
 */
Fixed	Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

/**
 * @brief Arithmetic operator
 * 
 * @param other
 * @return Fixed
 */
Fixed	Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

/**
 * @brief Arithmetic operator
 * 
 * @param other
 * @return Fixed
 */
Fixed	Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

/**
 * @brief Arithmetic operator
 * 
 * @param other
 * @return Fixed
 */
Fixed	Fixed::operator/(const Fixed &other) const
{
	if (other._fixedPointValue == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

/**
 * @brief Increment operator
 */
/**
 * @brief Increment operator
 * 
 * @return Fixed&
 */
Fixed	&Fixed::operator++()
{
	this->_fixedPointValue++;
	return (*this);
}

/**
 * @brief Increment operator
 * 
 * @param int
 * @return Fixed
 */
Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue++;
	return (tmp);
}

/**
 * @brief Decrement operator
 */
/**
 * @brief Decrement operator
 * 
 * @return Fixed&
 */
Fixed	&Fixed::operator--()
{
	this->_fixedPointValue--;
	return (*this);
}

/**
 * @brief Decrement operator
 * 
 * @param int
 * @return Fixed
 */
Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedPointValue--;
	return (tmp);
}

/**
 * @brief Min and Max static methods
 */
/**
 * @brief Min and Max static methods
 * 
 * @param a
 * @param b
 * @return Fixed&
 */
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

/**
 * @brief Min and Max static methods
 * 
 * @param a
 * @param b
 * @return const Fixed&
 */
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

/**
 * @brief Min and Max static methods
 * 
 * @param a
 * @param b
 * @return Fixed&
 */
Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

/**
 * @brief Min and Max static methods
 * 
 * @param a
 * @param b
 * @return const Fixed&
 */
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

/**
 * @brief Output stream operator
 */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
