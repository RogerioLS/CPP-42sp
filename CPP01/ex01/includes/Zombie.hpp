/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:22:00 by codespace         #+#    #+#             */
/*   Updated: 2024/12/06 23:43:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

/**
 * @brief Zombie class declaration and capacity to announce itself.
 */
class Zombie
{
	public:
		Zombie(); // Default constructor
		~Zombie(); // Default destructor

		void	setName(const std::string& name); // Set the name of the zombie.
		void	announce() const;  // Announce the presence of the zombie.

	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name); // Create a horde of zombies.
