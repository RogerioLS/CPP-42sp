/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 00:39:24 by codespace         #+#    #+#             */
/*   Updated: 2025/04/04 00:47:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
    if (std::distance(begin, end) > static_cast<int>(_size - _numbers.size()))
        throw std::overflow_error("Not enough space to add all numbers");
    _numbers.insert(_numbers.end(), begin, end);
}

#endif