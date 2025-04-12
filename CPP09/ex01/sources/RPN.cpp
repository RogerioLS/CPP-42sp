/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:53:41 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 17:55:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

/**
 * @brief Default constructor for the RPN class.
 */
RPN::RPN() {}

/**
 * @brief Copy constructor for the RPN class.
 * @param other The RPN object to copy from.
 */
RPN::RPN(const RPN &other)
{
    this->operands = other.operands;
}

/**
 * @brief Assignment operator for the RPN class.
 * @param other The RPN object to assign from.
 * @return A reference to the assigned RPN object.
 */
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->operands = other.operands;
    
    return (*this); 
}

/**
 * @brief Destructor for the RPN class.
 */
RPN::~RPN() {}

/**
 * @brief Checks if a character is a valid operator.
 * @param c The character to check.
 * @return True if the character is a valid operator, false otherwise.
 */
bool RPN::isOperator(char c) const 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

/**
 * @brief Applies an operator to the top two operands in the stack.
 * @param op The operator to apply.
 * @throws std::runtime_error If there are not enough operands or if the operator is invalid.
 */
void RPN::applyOperator(char op)
{
    if (operands.size() < 2)
        throw std::runtime_error("Error: not enough operands");

    int b = operands.top();
    operands.pop();
    int a = operands.top();
    operands.pop();

    switch (op)
    {
        case '+':
            operands.push(a + b);
            break;
        case '-':
            operands.push(a - b);
            break;
        case '*':
            operands.push(a * b);
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: division by zero");
            operands.push(a / b);
            break;
        default:
            throw std::runtime_error("Error: invalid operator");
    }
}

/**
 * @brief Evaluates a mathematical expression in Reverse Polish Notation.
 * @param expression The RPN expression as a string.
 * @return The result of the evaluation as an integer.
 * @throws std::runtime_error If the expression is invalid.
 */
int RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (token.size() == 1 && isOperator(token[0]))
        {
            applyOperator(token[0]);
        }
        else
        {
            int number;
            std::istringstream tokenStream(token);
            if (!(tokenStream >> number))
                throw std::runtime_error("Error: invalid token");
            operands.push(number);
        }
    }
    
    if (operands.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    
    return (operands.top());
}