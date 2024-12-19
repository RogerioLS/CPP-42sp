/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:25:10 by codespace         #+#    #+#             */
/*   Updated: 2024/12/19 00:33:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ClapTrap.hpp"
# include <iostream>

/**
 * @brief ScavTrap class, derived from ClapTrap
 * Represents a specialized ClapTrap with additional functionality.
 */
class ScavTrap : public ClapTrap
{
	// Constructor and Destructor
	public:
		ScavTrap(const std::string &name);
		~ScavTrap();
		
		// Methods
		void	attack(const std::string &target);
		void	guardGate();
};
