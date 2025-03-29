/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:40:08 by codespace         #+#    #+#             */
/*   Updated: 2025/03/29 15:11:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

/**
 * @brief Base class for polymorphic behavior.
 * 
 * This class serves as a base class for other classes in the hierarchy.
 * It contains a virtual destructor to ensure proper cleanup of derived classes.
 */
class Base
{
    public:
        virtual ~Base() {}
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif