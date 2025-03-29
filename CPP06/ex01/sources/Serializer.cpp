/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:11:09 by roglopes          #+#    #+#             */
/*   Updated: 2025/03/29 14:32:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

/**
 * @brief Default constructor for the Serializer class.
 */
Serializer::Serializer() {}

/**
 * @brief Destructor for the Serializer class.
 */
Serializer::~Serializer() {}

/**
 * @brief Copy constructor for the Serializer class.
 * 
 * @param src The source Serializer object to copy from.
 */
Serializer::Serializer(const Serializer &src) {
	(void)src;
}

/**
 * @brief Assignment operator for the Serializer class.
 * 
 * @param rhs The right-hand side Serializer object to assign from.
 * @return A reference to the current Serializer object.
 */
Serializer &Serializer::operator=(const Serializer &rhs) {
	(void)rhs;
	return *this;
}

/**
 * @brief Serializes a pointer to a Data object into a uintptr_t.
 * 
 * @param ptr The pointer to the Data object to serialize.
 * @return The serialized uintptr_t representation of the pointer.
 */
uintptr_t Serializer::serializer(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * @brief Deserializes a uintptr_t back into a pointer to a Data object.
 * 
 * @param raw The uintptr_t to deserialize.
 * @return The deserialized pointer to the Data object.
 */
Data* Serializer::deserializer(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}