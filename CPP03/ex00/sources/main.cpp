/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:23:09 by codespace         #+#    #+#             */
/*   Updated: 2024/12/18 01:24:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap1("Clappy");
	ClapTrap claptrap2("Trappy");

	claptrap1.attack("Enemy1");
	claptrap2.attack("Enemy2");

	claptrap1.takeDamage(5);
	claptrap2.takeDamage(7);

	claptrap1.beRepaired(3);
	claptrap2.beRepaired(4);

	claptrap1.attack("Another Enemy");
	claptrap2.takeDamage(10);

	return (0);
}
