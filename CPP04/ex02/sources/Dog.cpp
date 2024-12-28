/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:49:00 by codespace         #+#    #+#             */
/*   Updated: 2024/12/27 00:05:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/**
 * @brief Construct a new Dog:: Dog object and initialize the Brain object
 * 
 * @param brain
 * @param type
 */
Dog::Dog() : _brain(new Brain())
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

/**
 * @brief Copy constructor for Dog object and initialize the Brain object
 * 
 * @param other
 */
Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

/**
 * @brief Assignment operator for Dog object and initialize the Brain object
 * 
 * @param other
 * @return Dog&
 */
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	return *this;
}

/**
 * @brief Destroy the Dog:: Dog object and delete the Brain object
 * 
 * @param brain
 */
Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

/**
 * @brief Make a sound
 * 
 */
void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

/**
 * @brief Get the Brain object
 * 
 * @return Brain*
 */
Brain *Dog::getBrain() const
{
	return _brain;
}
