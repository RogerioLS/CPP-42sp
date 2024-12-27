/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:49:00 by codespace         #+#    #+#             */
/*   Updated: 2024/12/26 22:50:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

/**
 * @brief Construct a new Dog:: Dog object
 * 
 * This is the default constructor for the Dog class.
 */
Dog::Dog() {
	this->_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

/**
 * @brief Destroy the Dog:: Dog object
 * 
 * This is the destructor for the Dog class.
 */
Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

/**
 * @brief Construct a new Dog:: Dog object
 * 
 * This is the copy constructor for the Dog class.
 * 
 * @param other The Dog object to be copied.
 */
Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

/**
 * @brief Copy the Dog object
 * 
 * This is the copy assignment operator for the Dog class.
 * 
 * @param other The Dog object to be copied.
 * @return Dog& A reference to the copied Dog object.
 */
Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

/**
 * @brief Make a sound
 * 
 * This method makes a sound.
 */
void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}
