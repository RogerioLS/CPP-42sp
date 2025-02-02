/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:15:39 by codespace         #+#    #+#             */
/*   Updated: 2024/12/14 13:50:07 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

/**
 * @brief Construct that initializes the type of weapon.
 * @param type The type of weapon.
 */
Weapon::Weapon(const std::string &type) : _type(type){}

Weapon::~Weapon(){}

/**
 * @brief Get the type of weapon.
 * @return const std::string& The type of weapon.
 */
const std::string	&Weapon::getType() const
{
	return (_type);
}

/**
 * @brief Set the type of weapon.
 * @param type The type of weapon.
 */
void	Weapon::setType(const std::string &newType)
{
	_type = newType;
}
