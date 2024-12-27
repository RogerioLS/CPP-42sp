/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:52:39 by codespace         #+#    #+#             */
/*   Updated: 2024/12/27 00:08:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/**
 * @brief Construct a new Cat:: Cat object and initialize the Brain object
 * 
 * @param brain
 * @param type
 */
Cat::Cat() : _brain(new Brain())
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

/**
 * @brief Copy constructor for Cat object and initialize the Brain object
 * 
 * @param other
 */
Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

/**
 * @brief Assignment operator for Cat object and initialize the Brain object
 * 
 * @param other
 * @return Cat&
 */
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	return *this;
}

/**
 * @brief Destroy the Cat:: Cat object and delete the Brain object
 * 
 * @param brain
 */
Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

/**
 * @brief Make sound method
 * 
 */
void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

/**
 * @brief Get the Brain object
 * 
 * @return Brain*
 */
Brain *Cat::getBrain() const
{
	return _brain;
}
