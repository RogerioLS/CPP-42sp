/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:18:12 by roglopes          #+#    #+#             */
/*   Updated: 2025/03/29 14:47:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

/**
 * @brief Construct a new Scalar Converter:: Scalar Converter object
 */
ScalarConverter::ScalarConverter() {}

/**
 * @brief Construct a new Scalar Converter:: Scalar Converter object
 * 
 * @param copy
 */
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

/**
 * @brief Copy assignment operator
 * 
 * @param copy
 * @return ScalarConverter&
 */
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void) copy;
	return (*this);
}

/**
 * @brief Destroy the Scalar Converter:: Scalar Converter object
 */
ScalarConverter::~ScalarConverter() {}

/**
 * @brief Print the value as char
 * 
 * @param n
 */
void	printAsChar(double n)
{
	if (std::isnan(n) || std::isinf(n) || n < std::numeric_limits<char>::min() || n > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(static_cast<char>(n)))
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else 
		std::cout << "char: Non displayable" << std::endl;
}

 /**
  * @brief Print the value as int
  * 
  * @param n
  */
void	printAsInt(double n)
{
	if (std::isnan(n) || std::isinf(n) || n < std::numeric_limits<int>::min() ||
	n > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
}

/**
 * @brief Print the value as float
 * 
 * @param n
 */
void	printAsFloat(double n)
{
	if (std::isnan(n) || std::isinf(n) || n < -std::numeric_limits<float>::max() ||
	n > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(n) << (static_cast<int>(n) == n ? ".0f" : "f") << std::endl;
}

/**
 * @brief Print the value as double
 * 
 * @param n
 */
void	printAsDouble(double n)
{
	if (std::isnan(n) || std::isinf(n) || n < -std::numeric_limits<double>::max() ||
	n > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(n) << (static_cast<int>(n) == n ? ".0" : "") << std::endl;
}

/**
 * @brief Convert the value from string to char, int, float and double
 * 
 * @param str
 * 
 * @details This function will convert the value from string to char, int, float and double.
 * 			It will check if the value is valid and if it is not, it will print "impossible".
 * 
 */
void ScalarConverter::convert(const std::string& str)
{
	double n;
	char *endptr = NULL;

	if (str.size() == 1 && !std::isdigit(str[0]))
		n = static_cast<char>(str[0]);
	else if (str == "-inff" || str == "+inff" || str == "nanf")
		n = std::strtof(str.c_str(), &endptr);
	else if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
		n = std::strtod(str.c_str(), &endptr);
	else
	{
		n = std::strtod(str.c_str(), &endptr);
		if (*endptr != '\0') {
			std::cout << "Invalid input" << std::endl;
			return ;
		}
	}

	printAsChar(n);
	printAsInt(n);
	printAsFloat(n);
	printAsDouble(n);
}
