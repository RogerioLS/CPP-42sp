/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:50:59 by codespace         #+#    #+#             */
/*   Updated: 2024/12/26 23:52:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

/**
 * @brief Construct a new Brain:: Brain object
 */
Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

/**
 * @brief Construct a new Brain:: Brain object
 * 
 * @param other
 */
Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

/**
 * @brief Assignment operator
 * 
 * @param other
 * @return Brain&
 */
Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

/**
 * @brief Destroy the Brain:: Brain object
 */
Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

/**
 * @brief Set the Idea object
 * 
 * @param index
 * @param idea
 */
void Brain::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
}

/**
 * @brief Get the Idea object
 * 
 * @param index
 * @return std::string
 */
std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return _ideas[index];
	return "";
}
