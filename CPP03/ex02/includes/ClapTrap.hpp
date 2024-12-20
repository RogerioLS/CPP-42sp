/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:45:15 by codespace         #+#    #+#             */
/*   Updated: 2024/12/20 00:52:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

/**
 * @brief The ClapTrap class is a base class for the FragTrap and ScavTrap classes.
 * 
 * The ClapTrap class has the following attributes:
 * - _name (string, private)
 * - _hitPoints (int, private)
 * - _energyPoints (int, private)
 * - _attackDamage (int, private)
 * 
 */
class ClapTrap
{
	public:
		ClapTrap(void);
		// Copy constructor from the object ClapTrap a(b)
		ClapTrap(const ClapTrap &other);
		// Constructor with name
		ClapTrap(const std::string &name);
		// Destructor
		~ClapTrap(void);
		// Assignment operator b = a
		ClapTrap	&operator=(const ClapTrap &other);

		// Setters and Getters for the private attributes
		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};