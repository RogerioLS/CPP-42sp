/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:03:03 by roglopes          #+#    #+#             */
/*   Updated: 2025/03/29 14:29:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>
# include "Data.hpp"

/**
 * @brief The Serializer class provides methods to serialize and deserialize
 * a pointer to a Data object.
 * 
 * The class contains static methods to convert a pointer to a Data object
 * into a uintptr_t and vice versa.
 * 
 * The class is designed to be used for serialization and deserialization
 * of data pointers.
 * 
 * @see Data
 */
class Serializer
{
	public:
		Serializer();
		~Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &rhs);

		static uintptr_t serializer(Data *ptr);
		static Data* deserializer(uintptr_t raw);
};

#endif