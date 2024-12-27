/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:08:22 by codespace         #+#    #+#             */
/*   Updated: 2024/12/26 23:12:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	// Test class Polymorphism
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "Type of dog: " << dog->getType() << std::endl;
	std::cout << "Type of cat: " << cat->getType() << std::endl;

	dog->makeSound();
	cat->makeSound();
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;

	std::cout << "----------------------------------" << std::endl;

	// testing WrongAnimal and WrongCat not using virtual and polymorphism
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "Type of wrongCat: " << wrongCat->getType() << std::endl;

	wrongMeta->makeSound(); // call the method of WrongAniml
	wrongCat->makeSound(); // call the method of WrongCat

	delete wrongMeta;
	delete wrongCat;

	return (0);
}
