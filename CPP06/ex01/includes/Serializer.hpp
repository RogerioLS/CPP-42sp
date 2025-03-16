/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:03:03 by roglopes          #+#    #+#             */
/*   Updated: 2025/03/16 16:22:19 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>
# include "Data.hpp"

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