/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:42:19 by roglopes          #+#    #+#             */
/*   Updated: 2025/03/16 14:55:30 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <cstdlib>
# include <cctype>

/**
 * @brief Class to convert scalar values
 * 
 * @details This class is responsible for converting scalar values
 * 			from string to int, float, double and char.
 * 			Also, it will print the values in the four types.
 * 			For the conversion, it will use the functions
 * 			atoi, atof and static_cast.
 */
class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &operator=(ScalarConverter const &src);
		~ScalarConverter();

	public:
		static void convert(std::string const &input);
};

#endif