/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:33:00 by codespace         #+#    #+#             */
/*   Updated: 2024/12/06 23:35:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/**
 * @brief Construct a new Zombie:: Zombie object
 */
Zombie::Zombie()
{
	std::cout << "Zombie created" << std::endl;
}

/**
 * @brief Destroy the Zombie:: Zombie object
 */
Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

/**
 * @brief Set the name of the zombie.
 * @param name The name of the zombie.
 */
void	Zombie::setName(const std::string& name)
{
	this->_name = name;
}

/**
 * @brief Announce the presence of the zombie.
 */
void	Zombie::announce() const
{
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}