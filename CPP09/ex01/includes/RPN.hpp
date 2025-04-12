/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:48:59 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 17:54:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <stack>
# include <string>
# include <sstream>
# include <stdexcept>
# include <iostream>

/**
 * @file RPN.hpp
 * @class RPN
 * @brief Header file for the RPN class.
 * @details This file contains the declaration of the RPN class, which is responsible
 * for evaluating mathematical expressions written in Reverse Polish Notation (RPN).
 * It includes methods for validating and applying operators, as well as evaluating
 * the entire expression.
 */
class RPN
{
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        int evaluate(const std::string &expression);
        
    private:
        std::stack<int> operands;
        
        bool isOperator(char c) const;
        void applyOperator(char op);
};

#endif