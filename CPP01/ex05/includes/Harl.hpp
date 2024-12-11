/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:41:51 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/11 19:27:47 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

/**
 * @brief A class that automates Harl's complaints based on severity level.
 */
class	Harl
{
	public:
		/**
		 * @brief Calls the appropriate function based on the given complaint level.
		 * 
		 * @param level The level of complaint ("DEBUG", "INFO", "WARNING", or "ERROR").
		*/
		void	complain(const std::string &level);

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		// Define the type for a member function pointer inside the Harl class.
		typedef void (Harl::*HarlFunc)( void );
};
