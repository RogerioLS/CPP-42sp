/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:28:05 by codespace         #+#    #+#             */
/*   Updated: 2024/12/02 23:54:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

/**
 * @brief Default constructor for Contact.
 * 
 * Initializes an empty Contact object.
 */
Contact::Contact() {}

/**
 * @brief Destructor for Contact.
 * 
 * Cleans up resources for Contact object.
 */
Contact::~Contact() {}

/**
 * @brief Sets the details of the contact.
 * 
 * This method sets the first name, last name, nickname, phone number, 
 * and darkest secret of the contact.

 * @param firsName The first name of the contact.
 * @param lastName The last name of the contact.
 * @param nickname The nickname of the contact.
 * @param phoneNumber The phone number of the contact.
 * @param darkestSecret The darkest secret of the contact.
 */
void Contact::setContact(const std::string &firsName, const std::string &lastName,
						const std::string &nickname, const std::string &phoneNumber,
						const std::string &darkestSecret)
{
	this->firstName = firsName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}
/**
 * @brief Displays the details of the contact.
 * 
 * Prints the contact's details (first name, last name, nickname, phone number, 
 * and darkest secret) to the standard output.
 */
void Contact::displayContact() const
{
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone Number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
}

/**
 * @brief Truncates a string to 10 characters.
 * 
 * If the string length exceeds 10 characters, it truncates the string and 
 * appends a dot (`.`). Otherwise, it returns the original string.
 * 
 * @param str The string to truncate.
 * @return The truncated string or the original string if it's less than or 
 * equal to 10 characters.
 */
std::string Contact::truncateString(const std::string &str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

/**
 * @brief Displays a summarized version of the contact.
 * 
 * Prints the first name, last name, and nickname in a tabular format.
 * Each field is right-aligned and limited to 10 characters.
 */
void Contact::displayContactShort() const 
{
	std::cout << "|" << std::setw(10) << truncateString(this->firstName);
	std::cout << "|" << std::setw(10) << truncateString(this->lastName);
	std::cout << "|" << std::setw(10) << truncateString(this->nickname) << "|" << std::endl;
}

/**
 * @brief Gets the first name of the contact.
 * 
 * @return The first name of the contact.
 */
std::string Contact::getFirstName() const
{
	return this->firstName;
}

/**
 * @brief Gets the last name of the contact.
 * 
 * @return The last name of the contact.
 */
std::string Contact::getLastName() const
{
	return this->lastName;
}

/**
 * @brief Gets the nickname of the contact.
 * 
 * @return The nickname of the contact.
 */
std::string Contact::getNickname() const
{
	return this->nickname;
}
