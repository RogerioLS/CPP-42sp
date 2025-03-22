/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:48:12 by codespace         #+#    #+#             */
/*   Updated: 2025/03/22 17:23:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

template <typename T, typename Func>
void iter (T *array, size_t length, Func function)
{
    for (size_t i = 0; i < length; i++)
        function(array[i]);
}

#endif