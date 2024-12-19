/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:53:01 by codespace         #+#    #+#             */
/*   Updated: 2024/12/18 01:16:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

/**
 * @brief Construct a new Clap Trap:: Clap Trap object
 * 
 */
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " default constructor" << std::endl;
}

/**
 * @brief Construct a new Clap Trap:: Clap Trap object
 */
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " created" << std::endl;
}

/**
 * @brief Copy constructor
 */
ClapTrap::ClapTrap(const ClapTrap &other) 
	: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " copied" << std::endl;
}

/**
 * @brief Destroy the Clap Trap:: Clap Trap object
 */
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

/**
 * @brief Assignment operator
 */
ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap " << _name << " assigned" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

/**
 * @brief Attack method
 */
void	ClapTrap::attack(std::string const &target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't attack because it has no hit points or energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target 
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

/**
 * @brief Take damage method
 */
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is already dead and can't take more damage!" << std::endl;
		return ;
	}

	if (amount > _hitPoints) {
		amount = _hitPoints;
	}

	_hitPoints -= amount;

	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

/**
 * @brief Be repaired method
 */
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " can't be repaired because it has no hit points or energy points" << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repaired itself for " << amount << " points. Current HP:" << _hitPoints << std::endl;
}