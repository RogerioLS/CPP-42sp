/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:52:39 by codespace         #+#    #+#             */
/*   Updated: 2024/12/26 22:53:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/**
 * @brief Construct a new Cat:: Cat object
 * 
 * This is the default constructor for the Cat class.
 */
Cat::Cat() {
	this->_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

/**
 * @brief Destroy the Cat:: Cat object
 * 
 * This is the destructor for the Cat class.
 */
Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

/**
 * @brief Construct a new Cat:: Cat object
 * 
 * This is the copy constructor for the Cat class.
 * 
 * @param other The Cat object to be copied.
 */
Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
}

/**
 * @brief Copy the Cat object
 * 
 * This is the copy assignment operator for the Cat class.
 * 
 * @param other The Cat object to be copied.
 * @return Cat& A reference to the copied Cat object.
 */
Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat copy assignment operator called" << std::endl;
	return *this;
}

/**
 * @brief Make a sound
 * 
 * This method makes a sound.
 */
void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}
