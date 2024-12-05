/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:39:06 by codespace         #+#    #+#             */
/*   Updated: 2024/12/05 00:44:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main()
{
	std::cout << "Creating a new zombie on the stack..." << std::endl;
	Zombie* headZombie = newZombie("Head Zombie");
	headZombie->announce();
	delete headZombie;

	std::cout << std::endl << "Creating a stack zombie..." << std::endl;
	randomChump("Stack Zombie");
	return (0);
}
