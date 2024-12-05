/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:36:36 by codespace         #+#    #+#             */
/*   Updated: 2024/12/05 00:37:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/**
 * @brief Create a new zombie with the given name.
 * @param name The name of the zombie.
 * @return A pointer to the new zombie.
 */
Zombie* newZombie(const std::string& name)
{
	return new Zombie(name);
}