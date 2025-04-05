/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 00:18:43 by codespace         #+#    #+#             */
/*   Updated: 2025/04/04 00:41:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

/**
 * @file Span.hpp
 * @brief Header file for the Span class.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <limits>

/**
 * @class Span
 * @brief A class that represents a span of integers.
 */
class Span
{
    private:
        unsigned int _size; ///< The maximum size of the span.
        std::vector<int> _numbers; ///< The vector of integers in the span.
        
    public:
        /**
         * @brief Default constructor.
         */
        Span();

        /**
         * @brief Constructor with size parameter.
         * @param n The maximum size of the span.
         */
        Span(unsigned int n);

        /**
         * @brief Copy constructor.
         * @param other The Span object to copy from.
         */
        Span(const Span &other);

        /**
         * @brief Destructor.
         */
        ~Span();

        /**
         * @brief Assignment operator.
         * @param other The Span object to assign from.
         * @return A reference to this object.
         */
        Span &operator=(const Span &other);

        /**
         * @brief Adds a number to the span.
         * @param number The number to add.
         */
        void addNumber(int number);

        /**
         * @brief Adds a range of numbers to the span.
         * @param begin The beginning iterator of the range.
         * @param end The ending iterator of the range.
         */
        template <typename Iterator>
        void addRange(Iterator begin, Iterator end);

        /**
         * @brief Finds the shortest span in the span.
         * @return The shortest span.
         */
        int shortestSpan() const;

        /**
         * @brief Finds the longest span in the span.
         * @return The longest span.
         */
        int longestSpan() const;

};

#include "Span.tpp"

#endif