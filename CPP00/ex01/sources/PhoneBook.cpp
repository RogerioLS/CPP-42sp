/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:43:57 by codespace         #+#    #+#             */
/*   Updated: 2024/12/02 23:58:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

/**
 * @brief Default constructor for PhoneBook.
 * 
 * Initializes a PhoneBook object with an empty contact list.
 * Sets the current index and contact count to 0.
 */
PhoneBook::PhoneBook() : index(0), contactsCount(0) {}

/**
 * @brief Destructor for PhoneBook.
 * 
 * Cleans up resources for the PhoneBook object.
 */
PhoneBook::~PhoneBook() {}

/**
 * @brief Adds a new contact to the phonebook.
 * 
 * Prompts the user to enter contact details, including first name, last name, 
 * nickname, phone number, and darkest secret. If any field is empty, the contact 
 * is not added. If the phonebook has 8 contacts, the oldest contact is replaced.
 * 
 * @details The method cycles through the contact list, ensuring no more than 8 
 * contacts are stored at any time.
 */
void PhoneBook::addContact()
{
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);
	
	if (firstName.empty() || lastName.empty() || nickname.empty() ||
		phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "Error: All fields must be filled." << std::endl;
		return;
	}

	contacts[index].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	index = (index + 1) % 8;
	if (contactsCount < 8)
		contactsCount++;
}

/**
 * @brief Searches and displays contact information from the phonebook.
 * 
 * Displays a table of saved contacts, showing the index, first name, last name, 
 * and nickname. Prompts the user to select a contact by index to view full details.
 * 
 * @details The table format ensures each column is 10 characters wide. If the user 
 * selects an invalid index, an error message is displayed.
 */
void PhoneBook::searchContact() const
{
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << "|" << std::setw(10) << "First Name" << "|";
	std::cout << "|" << std::setw(10) << "Last Name" << "|";
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << std::endl;

	for (int i = 0; i < contactsCount; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		contacts[i].displayContactShort();
	}

	int choice;
	std::cout << "Enter index to view details: ";
	std::cin >> choice;

	if (choice >= 0 && choice < contactsCount)
		contacts[choice].displayContact();
	else
		std::cout << "Error: Invalid index." << std::endl;
}
