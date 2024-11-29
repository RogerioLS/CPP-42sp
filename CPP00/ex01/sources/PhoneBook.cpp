/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:43:57 by codespace         #+#    #+#             */
/*   Updated: 2024/11/29 00:54:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), contactsCount(0) {}

PhoneBook::~PhoneBook() {}

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
