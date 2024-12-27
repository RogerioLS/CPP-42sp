/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:43:52 by codespace         #+#    #+#             */
/*   Updated: 2024/12/26 22:46:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/**
 * @brief Construct a new Animal:: Animal object
 * 
 * This is the default constructor for the Animal class.
 */
Animal::Animal() : _type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

/**
 * @brief Destroy the Animal:: Animal object
 * 
 * This is the destructor for the Animal class.
 */
Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

/**
 * @brief Construct a new Animal:: Animal object
 * 
 * This is the copy constructor for the Animal class.
 * 
 * @param other The Animal object to be copied.
 */
Animal::Animal(const Animal &other) {
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

/**
 * @brief Copy the Animal object
 * 
 * This is the copy assignment operator for the Animal class.
 * 
 * @param other The Animal object to be copied.
 * @return Animal& A reference to the copied Animal object.
 */
Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
	this->_type = other._type;
	}
	std::cout << "Animal copy assignment operator called" << std::endl;
	return *this;
}

/**
 * @brief Make a sound
 * 
 * This is a virtual method that makes a generic sound.
 */
void Animal::makeSound() const {
	std::cout << "Animal makes a generic sound" << std::endl;
}

/**
 * @brief Get the type of the Animal object
 * 
 * This method returns the type of the Animal object.
 * 
 * @return std::string The type of the Animal object.
 */
std::string Animal::getType() const {
	return this->_type;
}
