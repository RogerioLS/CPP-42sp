/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:12:43 by codespace         #+#    #+#             */
/*   Updated: 2024/12/05 00:36:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/**
 * @brief Construct a new Zombie:: Zombie object with the given name.
 * @param name The name of the zombie.
 */
Zombie::Zombie(const std::string& name) : _name(name) {}

/**
 * @brief Destroy the Zombie:: Zombie object.
 * Prints a debug message indicating that the zombie is being destroyed.
 */
Zombie::~Zombie()
{
	std::cout << _name << " is being destroyed." << std::endl;
}
/**
 * @brief Announce the zombie with a specific message.
 */
void	Zombie::announce() const
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
