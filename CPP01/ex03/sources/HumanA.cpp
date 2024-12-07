/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:25:46 by codespace         #+#    #+#             */
/*   Updated: 2024/12/07 00:28:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

/**
 * @brief Construct that initializes HumanA with a name and a weapon.
 * 
 * @param name The name of the human.
 * @param weapon The weapon of the human.
 */
HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon){}

/**
 * @brief Makes the human attack using their weapon.
 */
void	HumanA::attack() const
{
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
