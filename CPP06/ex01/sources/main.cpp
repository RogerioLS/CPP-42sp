/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:16:56 by roglopes          #+#    #+#             */
/*   Updated: 2025/03/29 14:31:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

/**
 * @brief The main function demonstrates the serialization and deserialization
 * of a Data object using the Serializer class.
 * 
 * It creates a Data object, serializes it, and then deserializes it back to
 * a pointer. It checks if the original pointer and the deserialized pointer
 * are the same and prints the result.
 * 
 * ```cpp
 * int main()
 * {
 *    // Create a Data object
 *   Data data("Hello World!");
 * }
 * ```
 *
 * @return int
 */
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
