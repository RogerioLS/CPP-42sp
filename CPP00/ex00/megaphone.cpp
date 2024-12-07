/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 00:15:05 by codespace         #+#    #+#             */
/*   Updated: 2024/12/02 23:45:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/**
 * @brief Entry point of the Megaphone program.
 * 
 * This function reads command-line arguments, converts them to uppercase,
 * and prints them. If no arguments are passed, it prints a default message.
 * 
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return int Exit status of the program.
 */
int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		std::cout << static_cast<char>(toupper(argv[i][j]));
	}
	std::cout << std::endl;
	return (0);
}