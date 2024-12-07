/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:28:44 by codespace         #+#    #+#             */
/*   Updated: 2024/12/07 00:32:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>
# include "Weapon.hpp"

/**
 * @brief Represents a human that may or may not have a weapon.
 */
class	HumanB
{
	public:
		HumanB(const std::string &name);
		void	setWeapon(Weapon &weapon);
		void	attack() const;

	private:
		std::string	_name;
		Weapon		*_weapon;
};