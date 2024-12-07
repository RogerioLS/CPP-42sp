/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:41:23 by codespace         #+#    #+#             */
/*   Updated: 2024/12/06 23:48:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main()
{
	int	N;

	N = 5;
	std::string name = "Zombie";

	Zombie* horde = zombieHorde(N, name);
	if (horde != NULL)
	{
		for (int i = 0; i < N; i++)
		{
			horde[i].announce();
		}
		delete[] horde;
	}
	return (0);
}
