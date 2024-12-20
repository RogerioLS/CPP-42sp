/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:31:03 by codespace         #+#    #+#             */
/*   Updated: 2024/12/20 00:41:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

/**
 * @brief Construct a new FragTrap:: FragTrap object
 */
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructed with "
			  << this->_hitPoints << " hit points, " << this->_energyPoints
			  << " energy points and " << this->_attackDamage 
			  << " attack damage!." << std::endl;
}

/**
 * @brief Destroy the FragTrap:: FragTrap object
 */
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destructed!" << std::endl;
}

/**
 * @brief Request a positive high five.
 */
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name 
			  << " requests a positive high five! 🙌" << std::endl;
}
