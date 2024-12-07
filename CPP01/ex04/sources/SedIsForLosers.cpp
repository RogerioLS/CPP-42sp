/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:47:24 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/07 11:13:00 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/SedIsForLosers.hpp"

/**
 * @brief Processes the replacement of s1 with s2 in the specified file.
 * 
 * @param filename The name of the file to process.
 * @param s1 The string to be replaced.
 * @param s2 The string to replace with.
 * @return true if the operation was successful, false otherwise.
 */
bool	SedIsForLosers::replace(std::string &filename, const std::string &s1, const std::string &s2)
{
	if (s1.empty() || s2.empty())
	{
		std::cerr << "Error: Strings cannot be empty." << std::endl;
		return (false);
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open the file: " << filename << std::endl;
		return (false);
	}
	std::string content((std::istreambuf_iterator<char>(inputFile)),
						std::istreambuf_iterator<char>());
	inputFile.close();
	std::string modifiedContent = replaceOccurrences(content, s1, s2);
	std::ofstream outputFile((filename + ".replace").c_str());

	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create the output file." << std::endl;
		return (false);
	}
	outputFile << modifiedContent;
	outputFile.close();
	return (true);
}

/**
 * @brief Replaces all occurrences of s1 with s2 in the content string.
 * 
 * @param content The original content of the file.
 * @param s1 The string to be replaced.
 * @param s2 The string to replace with.
 * @return The updated content string.
 */
std::string SedIsForLosers::replaceOccurrences(const std::string &content, const std::string &s1, const std::string &s2)
{
	std::string result;
	size_t start = 0;
	size_t pos;

	while ((pos = content.find(s1, start)) != std::string::npos)
	{
		result.append(content, start, pos - start);
		result.append(s2);
		start = pos + s1.length();
	}
	result.append(content, start, content.length() - start);
	return (result);
}
