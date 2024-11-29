/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:23:36 by codespace         #+#    #+#             */
/*   Updated: 2024/11/29 01:13:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact {
	public:
		Contact();
		~Contact();
		void setContact(const std::string &firsName, const std::string &lastName,
						const std::string &nickname, const std::string &phoneNumber,
						const std::string &darkestSecret);

		void displayContact() const;
		void displayContactShort() const;

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;

	private:
		std::string truncateString(const std::string &str) const;
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif