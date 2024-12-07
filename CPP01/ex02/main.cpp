/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:53:50 by codespace         #+#    #+#             */
/*   Updated: 2024/12/07 00:04:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/**
 * @brief Demonstrates the use of pointers and references in C++
 */
int	main()
{
	// Initialize a string variable
	std::string str = "HI THIS IS BRAIN";
	// Create a pointer to the string variable
	std::string *stringPTR = &str;
	// Create a reference to the string variable
	std::string &stringREF = str;

	// Print the memory addresses of the string variable, the pointer, and the reference
	std::cout << "Memory address of the string variable: " << &str << std::endl;
	std::cout << "Memory address held by the stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by the stringREF: " << &stringREF << std::endl;

	// Print the values of the string variable, the pointer, and the reference
	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value pointed to by the stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by the stringREF: " << stringREF << std::endl;

	return (0);
}