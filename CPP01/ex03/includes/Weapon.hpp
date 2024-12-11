/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:13:26 by codespace         #+#    #+#             */
/*   Updated: 2024/12/11 19:39:08 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>

class	Weapon
{
	public:
		Weapon(const std::string &type);
		~Weapon();
		const std::string	&getType() const;
		void				setType(const std::string &newType);

	private:
		std::string	_type;
};
