/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:13:26 by codespace         #+#    #+#             */
/*   Updated: 2024/12/07 00:22:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>

class	Weapon
{
	public:
		Weapon(const std::string &type);
		const std::string	&getType() const;
		void				setType(const std::string &newType);

	private:
		std::string	_type;
};
