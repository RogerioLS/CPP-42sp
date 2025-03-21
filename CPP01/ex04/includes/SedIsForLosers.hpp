/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:43:06 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/07 10:48:02 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <fstream>
# include <iostream>

/**
 * @brief Class to replace all occurrences of a string in a file
 */
class	SedIsForLosers
{
	public:
		static bool	replace(std::string &filename, const std::string &s1, const std::string &s2);

	private:
		static std::string	replaceOccurrences(const std::string &content, const std::string &s1, const std::string &s2);
};
