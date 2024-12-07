/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:54:52 by codespace         #+#    #+#             */
/*   Updated: 2024/12/02 23:56:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/PhoneBook.hpp"

/**
 * @brief Main entry point of the program.
 * 
 * This function creates a PhoneBook object and enters a loop where it waits for
 * user input. The user can enter one of three commands: ADD, SEARCH, or EXIT.
 * ADD allows the user to add a new contact to the phone book, SEARCH allows the
 * user to search for a contact, and EXIT exits the program.
 * 
 * @return 0 on successful completion.
 */
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