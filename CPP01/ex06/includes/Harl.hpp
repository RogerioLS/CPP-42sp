/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:43:53 by roglopes          #+#    #+#             */
/*   Updated: 2024/12/08 13:48:54 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

/**
 * @brief Class Harl with message filtering based on log levels.
 */
class	Harl
{
	/**
	 * @brief Filter levels.
	 * 
	 * @param level the minimum level to be displayed.
	 */
	public:
		void	complain(const std::string &level);

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};
