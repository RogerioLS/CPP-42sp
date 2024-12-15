/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:04:38 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/14 16:13:22 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/**
 * @brief Set the raw value of the fixed point number.
 */
int	main() {
	std::cout << "DEFAULT CONSTRUCTOR:" << std::endl;
	Fixed a;
	std::cout << std::endl;

	std::cout << "COPY CONSTRUCTOR:" << std::endl;
	Fixed b(a);
	std::cout << std::endl;

	std::cout << "DEFAULT CONSTRUCTOR + ASSIGNMENT OPERATOR:" << std::endl;
	Fixed c;
	c = b;
	std::cout << std::endl;

	std::cout << "GET RAW BITS:" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << "SET RAW BITS:" << std::endl;
	a.setRawBits(42);
	b.setRawBits(21);
	c.setRawBits(84);
	std::cout << std::endl;

	std::cout << "GET RAW BITS:" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << "DESTRUCTOR:" << std::endl;
	
	return (0);
}
