/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:23:09 by codespace         #+#    #+#             */
/*   Updated: 2024/12/07 00:26:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>
# include "Weapon.hpp"

/**
 * @brief Represents a human that always has a weapon.
 */
class	HumanA
{
	public:
		HumanA(const std::string &name, Weapon &weapon);
		void	attack() const;

	private:
		std::string	_name;
		Weapon		&_weapon;
};
