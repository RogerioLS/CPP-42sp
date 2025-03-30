/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:30:20 by codespace         #+#    #+#             */
/*   Updated: 2025/03/30 19:07:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/**
 * @brief Swaps the values of two variables.
 * 
 * @tparam T The type of the variables.
 * @param a The first variable.
 * @param b The second variable.
 * 
 * This function swaps the values of two variables of the same type.
 * It uses a temporary variable to store the value of one of the variables
 * while the other variable is assigned the value of the first variable.
 */
template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

/**
 * @brief Returns the minimum of two variables.
 * 
 * @tparam T The type of the variables.
 * @param a The first variable.
 * @param b The second variable.
 * 
 * This function returns the minimum of two variables of the same type.
 * It uses the less than operator to compare the two variables.
 */
template <typename T>
T min(T &a, T &b)
{
    return (a < b ? a : b);
}

/**
 * @brief Returns the maximum of two variables.
 * 
 * @tparam T The type of the variables.
 * @param a The first variable.
 * @param b The second variable.
 * 
 * This function returns the maximum of two variables of the same type.
 * It uses the greater than operator to compare the two variables.
 */
template <typename T>
T max(T &a, T &b)
{
    return (a > b ? a : b);
}

#endif