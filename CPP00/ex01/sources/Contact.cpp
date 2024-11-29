/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:28:05 by codespace         #+#    #+#             */
/*   Updated: 2024/11/29 01:12:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

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

void Contact::displayContact() const
{
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone Number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
}

std::string Contact::truncateString(const std::string &str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::displayContactShort() const 
{
	std::cout << "|" << std::setw(10) << truncateString(this->firstName);
	std::cout << "|" << std::setw(10) << truncateString(this->lastName);
	std::cout << "|" << std::setw(10) << truncateString(this->nickname) << "|" << std::endl;
}

std::string Contact::getFirstName() const
{
	return this->firstName;
}

std::string Contact::getLastName() const
{
	return this->lastName;
}

std::string Contact::getNickname() const
{
	return this->nickname;
}