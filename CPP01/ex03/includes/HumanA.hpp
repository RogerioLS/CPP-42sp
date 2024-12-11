/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:23:09 by codespace         #+#    #+#             */
/*   Updated: 2024/12/11 19:35:46 by roglopes         ###   ########.fr       */
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
		~HumanA();
		void	attack() const;

	private:
		std::string	_name;
		Weapon		&_weapon;
};
