/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:47:57 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/08 13:37:23 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

/**
 * @brief Outputs a debug-level messges.
 */
void	Harl::debug( void )
{
	std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
/**
 * @brief Outputs an info-level messges.
 */
void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
/**
 * @brief Outputs a warning-level messges.
 */
void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

/**
 * @brief Outputs an error-level messges.
 */
void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/**
 * @brief Calls the appropriate function based on the given complaint level.
 * 
 * @param level The level of complaint ("DEBUG", "INFO", "WARNING", or "ERROR").
 */
void	Harl::complain(const std::string &level )
{
	HarlFunc			funcs[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	const std::string	levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << "[UNKNOWN] Level not recognized. Harl remains silent." << std::endl;
}
