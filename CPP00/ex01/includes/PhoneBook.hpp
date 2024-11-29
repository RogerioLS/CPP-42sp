/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:23:26 by codespace         #+#    #+#             */
/*   Updated: 2024/11/29 00:27:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <string>

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact() const;
		void displayContacts() const;

	private:
		Contact contacts[8];
		int index;
		int contactsCount;
};

#endif