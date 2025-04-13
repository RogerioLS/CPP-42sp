/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:59:23 by codespace         #+#    #+#             */
/*   Updated: 2025/04/13 18:27:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/**
 * @brief Default constructor for the PmergeMe class.
 */
PmergeMe::PmergeMe() : debugMode(false), vecTime(0), deqTime(0) {}

/**
 * @brief Copy constructor for the PmergeMe class.
 * @param other The object to copy from.
 */
PmergeMe::PmergeMe(const PmergeMe& other) : 
    vec(other.vec),
    deq(other.deq),
    debugMode(other.debugMode),
    vecTime(other.vecTime),
    deqTime(other.deqTime) {}

/**
 * @brief Assignment operator for the PmergeMe class.
 * @param other The PmergeMe object to assign from.
 * @return A reference to the assigned PmergeMe object.
 */
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        vec = other.vec;
        deq = other.deq;
        debugMode = other.debugMode;
        vecTime = other.vecTime;
        deqTime = other.deqTime;
    }
    return (*this);
}

/**
 * @brief Destructor for the PmergeMe class.
 */
PmergeMe::~PmergeMe() {}

/**
 * @brief Validates that the input string contains a positive integer.
 * @param input The string to validate.
 * @return True if the input is a positive integer, false otherwise.
 */
bool PmergeMe::validateInput(const std::string &input)
{
    if (input.empty())
        return (false);

    for (size_t i = 0; i < input.length(); ++i)
    {
        if (!isdigit(input[i]))
            return (false);
    }

    try
    {
        long num = std::atol(input.c_str());
        if (num < 0 || num > INT_MAX)
            return (false);
    }
    catch(const std::exception &e)
    {
        return (false);
    }

    return (true);
}

/**
 * @brief Parses the command line arguments and populates the vector and list.
 * @param argv The command line arguments.
 * @throws std::runtime_error If an argument is not a positive integer.
 */
void PmergeMe::parseArgs(char *argv[])
{
    vec.clear();
    deq.clear();

    debugPrint(YELLOW + std::string("Starting to parse arguments..."));
    
    std::set<int> uniqueValues;
    int i = 1;
    while (argv[i])
    {
        std::string arg = argv[i];
        
        debugPrint("Parsing argument: " + arg);

        std::istringstream iss(arg);
        std::string token;

        while (iss >> token)
        {
            if (!validateInput(token))
            {
                debugPrint(RED + std::string("Invalid input: ") + token);
                throw std::runtime_error(RED + std::string("Error") + RESET);
            }         
            int num = atoi(token.c_str());
            if (uniqueValues.find(num) != uniqueValues.end())
            {
                debugPrint(YELLOW + std::string("Warning: Duplicate value found: ") + token);
                //throw std::runtime_error(RED + std::string("Error") + RESET);
            }
            uniqueValues.insert(num);

            vec.push_back(num);
            deq.push_back(num);
            // Creating a string manually in place of std::to_string
            std::ostringstream numStr;
            numStr << num;
            debugPrint("Parsed number: " + numStr.str());
        }
        i++;
    }

    if (vec.empty())
    {
        debugPrint(RED + std::string("No valid integers provided."));
        throw std::runtime_error(RED + std::string("Error") + RESET);
    }
    // Creating a string manually in place of std::to_string
    std::ostringstream sizeStr;
    sizeStr << vec.size();
    debugPrint("Parsing complete. Total numbers: " + sizeStr.str());
}


/**
 * @brief Processes the command line arguments and sorts the vector and list.
 * @param argv The command line arguments.
 */
void PmergeMe::processArgs(char **argv)
{
    // Parse arguments into both containers
    parseArgs(argv);

    debugPrint(YELLOW + std::string("Processing arguments and preparing to sort..."));

    std::cout << YELLOW << BOLD << "Before: " << RESET;
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // TODO: Implement sorting algorithms for both containers
    // For now, we will just sort the vector and list using std::sort
    debugPrint(MAGENTA + std::string("Sorting with vector (temporary std::sort implementation)"));
    clock_t start = std::clock();
    mergeInsertSortVector(vec);
    clock_t end = std::clock();
    vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
    debugPrint(GREEN + std::string("Vector sorting completed successfully"));
    
    debugPrint(MAGENTA + std::string("Sorting with list (temporary std::sort implementation)"));
    start = std::clock();
    mergeInsertSortDeque(deq);
    end = std::clock();
    deqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
    debugPrint(GREEN + std::string("List sorting completed successfully"));
    
    // Display sorted results
    std::cout << GREEN << BOLD << "After: " << RESET;
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

/**
 * @brief Displays the results of the sorting operations.
 * @param count The number of elements sorted.
 */
void PmergeMe::displayResults(int count)
{
    debugPrint(YELLOW + std::string("Displaying timing results..."));

    std::cout << BLUE << BOLD << "Time to process a range of " << count 
              << " elements with std::vector : " << RESET
              << std::fixed << std::setprecision(5) << vecTime << " us" << std::endl;
    
    std::cout << BLUE << BOLD << "Time to process a range of " << count 
              << " elements with std::Deque : " << RESET
              << std::fixed << std::setprecision(5) << deqTime << " us" << std::endl;
}

/**
 * @brief Sets the debug mode.
 * @param mode True to enable debug mode, false to disable.
 */
void PmergeMe::setDebugMode(bool mode) {
    debugMode = mode;
    if (debugMode)
        std::cout << GREEN << BOLD << "Debug mode enabled" << RESET << std::endl;
}

/**
 * @brief Prints a debug message if debug mode is enabled.
 * @param message The message to print.
 */
void PmergeMe::debugPrint(const std::string& message) const {
    if (debugMode)
        std::cout << CYAN << "[DEBUG]: " << message << RESET << std::endl;
}

/**
 * @brief Gets the sorted vector.
 * @return The sorted vector.
 */
const std::vector<int>& PmergeMe::getVector() const {
    return vec;
}

/**
 * @brief Gets the sorted list.
 * @return The sorted list.
 */
const std::deque<int>& PmergeMe::getDeque() const {
    return deq;
}

