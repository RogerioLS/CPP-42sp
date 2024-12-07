/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:52:52 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/07 10:54:51 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/SedIsForLosers.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" 
				<< std::endl;
		return (1);
	}
	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	if (!SedIsForLosers::replace(filename, s1, s2))
		return (1);
	std::cout << "Replacement successful. Output written to " 
			<< filename << ".replace" << std::endl;
	return (0);
}