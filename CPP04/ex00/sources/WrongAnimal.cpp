/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 22:59:33 by codespace         #+#    #+#             */
/*   Updated: 2024/12/26 23:01:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

/**
 * @brief Construct a new WrongAnimal:: WrongAnimal object
 * 
 * This is the default constructor for the WrongAnimal class.
 */
WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

/**
 * @brief Destroy the WrongAnimal:: WrongAnimal object
 * 
 * This is the destructor for the WrongAnimal class.
 */
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/**
 * @brief Construct a new WrongAnimal:: WrongAnimal object
 * 
 * This is the copy constructor for the WrongAnimal class.
 * 
 * @param other The WrongAnimal object to be copied.
 */
WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

/**
 * @brief Copy the WrongAnimal object
 * 
 * This is the copy assignment operator for the WrongAnimal class.
 * 
 * @param other The WrongAnimal object to be copied.
 * @return WrongAnimal& A reference to the copied WrongAnimal object.
 */
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other)
		this->type = other.type;
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	return *this;
}

/**
 * @brief Make a sound
 * 
 * This method makes a sound.
 */
void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes a strange sound!" << std::endl;
}

/**
 * @brief Get the type
 * 
 * This method returns the type of the WrongAnimal object.
 * 
 * @return std::string The type of the WrongAnimal object.
 */
std::string WrongAnimal::getType() const {
	return this->type;
}
