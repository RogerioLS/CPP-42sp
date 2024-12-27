/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:08:57 by codespace         #+#    #+#             */
/*   Updated: 2024/12/27 00:11:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main()
{
	const Animal* animals[4];

	// half Dogs, half Cats
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// show sons
	for (int i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
	}

	// deleting the animals
	for (int i = 0; i < 4; i++)
	{
		delete animals[i];
	}

	return (0);
}
