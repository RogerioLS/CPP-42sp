/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:48:12 by codespace         #+#    #+#             */
/*   Updated: 2025/03/30 19:08:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

/**
 * @brief Applies a function to each element of an array.
 * 
 * @tparam T The type of the elements in the array.
 * @tparam Func The type of the function to apply.
 * @param array The array to iterate over.
 * @param length The length of the array.
 * @param function The function to apply to each element of the array.
 * 
 * This function takes an array and a function as arguments and applies
 * the function to each element of the array. It uses a for loop to iterate
 * over the elements of the array and calls the function on each element.
 */
template <typename T, typename Func>
void iter(T *array, size_t length, Func function)
{
    for (size_t i = 0; i < length; i++)
        function(array[i]);
}

#endif