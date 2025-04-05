/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:18:21 by codespace         #+#    #+#             */
/*   Updated: 2025/04/05 01:01:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <list>
#include <stack>
#include <iterator>
#include <deque>

/**
 * @brief A stack that allows iteration over its elements.
 * 
 * This class inherits from std::stack and provides additional functionality
 * to iterate over the elements in the stack using iterators.
 * It uses a container type
 * (default is std::deque) to store the elements.
 * 
 * @tparam T The type of elements in the stack.
 * @tparam Container The container type used to store the elements (default is std::deque). 
 */
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack() : std::stack<T, Container>() {}
        MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}
        ~MutantStack() {}
        MutantStack &operator=(const MutantStack &other)
        {
            if (this != &other)
            std::stack<T, Container>::operator=(other);
            return (*this);
        }

        typedef typename std::stack<T, Container>::container_type::iterator iterator;
        typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
        
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }   
};

#endif