/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:41:55 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/15 15:55:53 by roglopes         ###   ########.fr       */
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