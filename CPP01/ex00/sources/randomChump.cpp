/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:37:41 by codespace         #+#    #+#             */
/*   Updated: 2024/12/05 00:38:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/**
 * @brief Create a new zombie with the given name and announce it.
 * @param name The name of the zombie.
 */
void randomChump(const std::string& name)
{
	Zombie z(name);
	z.announce();
}
