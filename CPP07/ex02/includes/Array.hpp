/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:14:25 by codespace         #+#    #+#             */
/*   Updated: 2025/03/30 19:08:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <exception>

/**
 * @brief A template class that represents a dynamic array.
 * 
 * @tparam T The type of the elements in the array.
 * 
 * This class provides a dynamic array implementation with basic operations
 * such as construction, destruction, assignment, and element access.
 */
template <typename T>
class Array
{
    private:
        T*				_data;      // Pointer to the array data
        unsigned int	_size;      // Size of the array

    public:
        // Constructors
        Array();                    // Default constructor
        Array(unsigned int n);      // Parametric constructor
        Array(const Array &copy);   // Copy constructor 
        ~Array();                   // Destructor

        // Overload the assignment operator    
        Array &operator=(const Array &copy); 

        // Overload the [] operator to access the elements of the array
        T &operator[](unsigned int index);

        // Get the size of the array
        const T &operator[](unsigned int index) const;

        unsigned int size() const;
};

# include "Array.tpp"

#endif