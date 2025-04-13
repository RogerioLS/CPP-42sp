/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:08:09 by codespace         #+#    #+#             */
/*   Updated: 2025/04/13 19:14:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/**
 * @file main.cpp
 * @brief Entry point for the PmergeMe program.
 * @details This file contains the main function for the PmergeMe program,
 * which sorts a sequence of positive integers using the Merge-Insert Sort
 * algorithm with two different containers and compares their performance.
 */

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << RED << BOLD << "Usage: ./PmergeMe [--debug] [positive integers]" << RESET << std::endl;
        return (1);
    }
    
    bool debugMode = false;
    int startIndex = 1;
    
    // Check for debug flag
    if (strcmp(argv[1], "--debug") == 0) {
        debugMode = true;
        startIndex = 2;
        
        if (argc < 3) {
            std::cerr << RED << BOLD << "Usage: ./PmergeMe [--debug] [positive integers]" << RESET << std::endl;
            return (1);
        }
    }
    
    try {
        PmergeMe sorter;
        // Enable debug mode if requested
        if (debugMode)
            sorter.setDebugMode(true);
        // Process arguments starting at the correct index
        sorter.processArgs(argv + (startIndex - 1));
        sorter.displayResults(sorter.getVector().size());
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    
    return (0);
}