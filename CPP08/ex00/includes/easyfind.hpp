/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 00:37:18 by codespace         #+#    #+#             */
/*   Updated: 2025/04/03 01:28:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  EASYFIND_HPP
#define  EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <stdexcept>
# include <iostream>
# include <vector>
# include <list>

/**
 * * @brief Searches for a value in a container and returns an iterator to it.
 * 
 * * @tparam T The container type (e.g., std::vector, std::list).
 * * @param container The container to search in.
 * * @param value The value to search for.
 * * @return An iterator to the found value.
 * * @throws std::runtime_error if the value is not found in the container.
 */
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in the container");
    return it;
}

#endif