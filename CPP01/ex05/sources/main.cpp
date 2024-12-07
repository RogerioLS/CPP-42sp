/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:55:00 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/07 17:57:05 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Harl.hpp"

int	main( void )
{
	Harl	harl;

	std::cout << "Testing with DEBUG level:" << std::endl;
	harl.complain("DEBUG");

	std::cout << "Testing with INFO level:" << std::endl;
	harl.complain("INFO");

	std::cout << "Testing with WARNING level:" << std::endl;
	harl.complain("WARNING");

	std::cout << "Testing with ERROR level:" << std::endl;
	harl.complain("ERROR");

	std::cout << "Testing with unknown level:" << std::endl;
	harl.complain("UNKNOWN");

	return (0);
}