/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 00:45:14 by codespace         #+#    #+#             */
/*   Updated: 2024/12/20 00:56:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main()
{
	std::cout << "Teste básico com FragTrap" << std::endl;
	FragTrap frag("FR4G");
	frag.attack("villain");
	frag.takeDamage(15);
	frag.beRepaired(7);
	frag.highFivesGuys();

	std::cout << "Teste básico com ScavTrap" << std::endl;
	ScavTrap scav("SC4V");
	scav.attack("enemy");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << "Teste básico com ClapTrap" << std::endl;
	ClapTrap clap("CL4P");
	clap.attack("target");
	clap.takeDamage(5);
	clap.beRepaired(3);

	return (0);
}