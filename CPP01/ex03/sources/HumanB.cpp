/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:31:54 by codespace         #+#    #+#             */
/*   Updated: 2024/12/14 13:50:37 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

/**
 * @brief Construct that initializes HumanB with a name.
 * 
 * @param name The name of the human.
 */
HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL){}

HumanB::~HumanB(){}

/**
 * @brief Set the weapon of the human.
 * 
 * @param weapon The weapon of the human.
 */
void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
/**
 * @brief Makes the human attack using their weapon.
 */
void	HumanB::attack() const
{
	if (_weapon)
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack with" << std::endl;
}
