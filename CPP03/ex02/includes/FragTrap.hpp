/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:09:21 by codespace         #+#    #+#             */
/*   Updated: 2024/12/20 00:52:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ClapTrap.hpp"

/**
 * @brief The FragTrap class is a child class of the ClapTrap class.
 * 
 * The FragTrap class has the following attributes:
 * - _name (string, private)
 * - _hitPoints (int, private)
 * - _energyPoints (int, private)
 * - _attackDamage (int, private)
 * 
 */
class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string &name);
		~FragTrap(void);

		// Setters and Getters for the private attributes
		void	highFivesGuys(void);
};