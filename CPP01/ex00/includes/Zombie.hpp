/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:08:58 by codespace         #+#    #+#             */
/*   Updated: 2024/12/11 18:49:02 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(const std::string& name);
		~Zombie( void );
		/**
		 * @brief Announce the presence of the zombie.
		 */
		void	announce() const;

	private:
		std::string	_name;
};

Zombie*	newZombie(const std::string& name);
void	randomChump(const std::string& name);
