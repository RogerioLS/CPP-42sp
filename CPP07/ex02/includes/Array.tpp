/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:20:27 by codespace         #+#    #+#             */
/*   Updated: 2025/03/23 15:03:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

// Default constructor - creates an empty array
template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

// Parametric constructor - creates an array of size n
template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    _data = new T[n];
}

// Copy constructor - creates a copy of the array
template <typename T>
Array<T>::Array(const Array<T> &other) : _size(other._size)
{
    _data = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _data[i] = other._data[i];
}

// Destructor - deletes the array
template <typename T>
Array<T>::~Array()
{
    delete[] _data;
}

// Overload the assignment operator
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

// Overload the [] operator to access the elements of the array
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return (_data[index]);
}

// Operator of access [] const
template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return (_data[index]);
}

// Method size
template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

#endif