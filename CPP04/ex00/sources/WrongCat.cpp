/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:03:08 by codespace         #+#    #+#             */
/*   Updated: 2024/12/26 23:04:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

/**
 * @brief Construct a new WrongCat:: WrongCat object
 * 
 * This is the default constructor for the WrongCat class.
 */
WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

/**
 * @brief Destroy the WrongCat:: WrongCat object
 * 
 * This is the destructor for the WrongCat class.
 */
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/**
 * @brief Construct a new WrongCat:: WrongCat object
 * 
 * This is the copy constructor for the WrongCat class.
 * 
 * @param other The WrongCat object to be copied.
 */
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

/**
 * @brief Copy the WrongCat object
 * 
 * This is the copy assignment operator for the WrongCat class.
 * 
 * @param other The WrongCat object to be copied.
 * @return WrongCat& A reference to the copied WrongCat object.
 */
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return *this;
}

/**
 * @brief Make a sound
 * 
 * This method makes a sound.
 */
void WrongCat::makeSound() const
{
	std::cout << "WrongCat meows weirdly!" << std::endl;
}
