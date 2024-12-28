/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:08:57 by codespace         #+#    #+#             */
/*   Updated: 2024/12/28 12:44:44 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main() {
	// Cannot instantiate AAnimal directly.
	// Animal animal; // This line will cause a compilation error.

	Animal* dog = new Dog();
	Animal* cat = new Cat();

	std::cout << dog->getType() << " ";
	dog->makeSound();

	std::cout << cat->getType() << " ";
	cat->makeSound();

	delete dog;
	delete cat;

	return (0);
}
