/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:42:16 by codespace         #+#    #+#             */
/*   Updated: 2025/04/13 19:14:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define BOLD    "\033[1m"

/**
 * @include <vector> this header is included to use the std::vector container.
 * @include <deque> this header is included to use the std::deque container.
 * @include <iostream> this header is included to use the std::cout and std::cerr streams.
 * @include <sstream> this header is included to use the std::stringstream class.
 * @include <ctime> this header is included to use the std::clock function.
 * @include <cstdlib> this header is included to use the std::atoi function.
 * @include <cstring> this header is included to use the std::strcmp function.
 * @include <stdexcept> this header is included to use the std::invalid_argument exception.
 * @include <iomanip> this header is included to use the std::setprecision function.
 * @include <algorithm> this header is included to use the std::sort function.
 * @include <string> this header is included to use the std::string class.
 * @include <limits.h> this header is included to use the INT_MAX constant.
 * @include <set> this header is included to use the std::set container.
 */
# include <vector>
# include <deque>
# include <iostream>
# include <sstream>
# include <ctime>
# include <cstdlib>
# include <cstring>
# include <stdexcept>
# include <iomanip>
# include <algorithm>
# include <string>
# include <limits.h>
# include <set>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
        bool debugMode;
        
        // Time measurement variables
        double vecTime;
        double deqTime;

        // Parse the input arguments into integers
        void parseArgs(char **argv);

        // Validate that all inputs are positive integers
        bool validateInput(const std::string& input);

        // Vector
        void mergeInsertSortVector(std::vector<int> &arr);

        // Deque
        void mergeInsertSortDeque(std::deque<int> &deq);
 
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        // Process the arguments and sort using both containers
        void processArgs(char **argv);

        // Display the results
        void displayResults(int count);

        // Enable or disable debug mode
        void setDebugMode(bool mode);
        
        // Print the current state (for debugging)
        void debugPrint(const std::string& message) const;

        // Getters for the sorted containers
        const std::vector<int> &getVector() const;
        const std::deque<int> &getDeque() const;
};

#endif