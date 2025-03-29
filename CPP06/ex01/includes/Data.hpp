/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:04:40 by roglopes          #+#    #+#             */
/*   Updated: 2025/03/29 14:29:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

# include <string>

/**
 * @brief The Data class represents a simple data structure that contains 
 * a string.
 * 
 * The class has a constructor that initializes the string member variable.
 * It can be used to store and manipulate string data.
 */
struct Data
{
	std::string str;
	Data(const std::string &s = "") : str(s) {}
};

#endif