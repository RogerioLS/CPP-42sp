/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:16:56 by roglopes          #+#    #+#             */
/*   Updated: 2025/03/16 16:23:14 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int main()
{
	Data data("Hello World!");

	uintptr_t raw = Serializer::serializer(&data);

	Data *deserializedData = Serializer::deserializer(raw);

	if (&data == deserializedData)
		std::cout << "Test Passed: The original pointer and the deserialized pointer are the same!" << std::endl;
	else
		std::cout << "Test Failed: The pointers are not the same!" << std::endl;

	std::cout << "Data content: " << deserializedData->str << std::endl;

	return (0);
}
