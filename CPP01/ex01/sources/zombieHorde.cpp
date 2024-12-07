/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:37:55 by codespace         #+#    #+#             */
/*   Updated: 2024/12/06 23:48:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/**
 * @brief Create a horde of zombies.
 * @param N The number of zombies.
 * @param name The name of the zombies.
 * @return A pointer to the first zombie in the horde.
 */
Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "Invalid number of zombies" << std::endl;
		return (NULL);
	}
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return (horde);
}
