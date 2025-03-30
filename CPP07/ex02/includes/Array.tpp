/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:20:27 by codespace         #+#    #+#             */
/*   Updated: 2025/03/30 19:13:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

/**
 * @brief Default constructor - creates an empty array
 */
template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

/**
 * @brief Parametric constructor - creates an array of size n 
 * 
 * @param n The size of the array
 */
template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    _data = new T[n];
}

/**
 * @brief Copy constructor - creates a copy of the array
 * 
 * @param other The array to copy
 * 1. Initializes the size of the new array to the size of the other array.
 * 2. Allocates memory for the new array using new.
 * 3. Copies the elements of the other array into the new array using a for loop.
 * 4. The new array is now a separate copy of the other array.
 */
template <typename T>
Array<T>::Array(const Array<T> &other) : _size(other._size)
{
    _data = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _data[i] = other._data[i];
}

/**
 * @brief Destructor - deletes the array
 * 
 * 1. The destructor is called when an object of the class goes out of scope or is deleted.
 * 2. It deallocates the memory used by the array using delete[].
 * 3. This prevents memory leaks by freeing the memory that was allocated for the array.
 * 4. The destructor does not return any value.
 */
template <typename T>
Array<T>::~Array()
{
    delete[] _data;
}

/**
 * @brief Overload the assignment operator
 * 
 * @param other The array to assign
 * 1. The assignment operator is used to assign one array to another.
 * 2. It first checks if the current object is not the same as the other object.
 * 3. If they are different, it deletes the current array using delete[].
 * 4. It then allocates memory for the new array using new.
 * 5. Finally, it copies the elements of the other array into the new array using a for loop.
 * 6. The assignment operator returns a reference to the current object.
 */
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        delete[] _data;
        _size = other._size;
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
    return (*this);
}

/**
 * @brief Operator of access []
 * 
 * @param index The index of the element to access
 * 1. The operator[] is used to access the elements of the array.
 * 2. It takes an index as a parameter and returns a reference to the element at that index.
 * 3. If the index is out of range, it throws an std::out_of_range exception.
 * 4. The operator[] returns a reference to the element at the specified index.
 */
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return (_data[index]);
}

/**
 * @brief Operator of access [] (const)
 * 
 * @param index The index of the element to access
 * 1. The const version of the operator[] is used to access the elements of the array.
 * 2. It takes an index as a parameter and returns a const reference to the element at that index.
 * 3. If the index is out of range, it throws an std::out_of_range exception.
 * 4. The operator[] returns a const reference to the element at the specified index.
 */
template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return (_data[index]);
}

/**
 * @brief Get the size of the array
 * 
 * @return The size of the array
 */
template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

#endif