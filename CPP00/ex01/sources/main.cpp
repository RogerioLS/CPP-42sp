/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:54:52 by codespace         #+#    #+#             */
/*   Updated: 2024/11/29 00:56:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else
			std::cout << "Error: Invalid command." << std::endl;
	}
	return (0);
}