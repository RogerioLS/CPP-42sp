/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:33:01 by codespace         #+#    #+#             */
/*   Updated: 2024/12/19 00:43:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/**
 * @brief ScavTrap Constructor
 * Initializes attributes and displays a message.
 */
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << "ScavTrap " << this->_name << " constructed!" << std::endl;
}

/**
 * @brief ScavTrap Destructor
 * Displays a message upon destruction.
 */
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destructed!" << std::endl;
}

/**
 * @brief Redefined attack method
 * Displays a specific message when ScavTrap attacks.
 */
void ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name
				  << " attacks " << target << ", causing " 
				  << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name
				  << " cannot attack due to insufficient energy or health!" << std::endl;
	}
}

/**
 * @brief Activates Gate Keeper mode
 * Displays a message indicating ScavTrap's special ability.
 */
void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name
			  << " is now in Gate Keeper mode!" << std::endl;
}
