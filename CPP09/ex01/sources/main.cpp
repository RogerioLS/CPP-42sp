/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:28:04 by codespace         #+#    #+#             */
/*   Updated: 2025/04/11 17:56:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

/**
 * @file main.cpp
 * @brief Entry point for the RPN program.
 * @details This file contains the main function, which reads an RPN expression
 * from the command line, evaluates it using the RPN class, and prints the result.
 *
 * @brief Main function of the RPN program.
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return 0 on success, 1 on error.
 */
int main(int argc, char **argv) 
{
    if (argc != 2) {
        std::cerr << "Usage: ./RPN <expression>" << std::endl;
        return (1);
    }

    try {
        RPN rpn;
        int result = rpn.evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}