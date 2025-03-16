/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:11:09 by roglopes          #+#    #+#             */
/*   Updated: 2025/03/16 16:22:38 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer() {}


Serializer::~Serializer() {}


Serializer::Serializer(const Serializer &src) {
	(void)src;
}

// Operador de atribuição por cópia
Serializer &Serializer::operator=(const Serializer &rhs) {
	(void)rhs;
	return *this;
}

uintptr_t Serializer::serializer(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserializer(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
