/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertVector.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 00:10:38 by codespace         #+#    #+#             */
/*   Updated: 2025/04/13 17:58:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/**
* @brief Sorts a vector of integers using the Merge-Insert Sort algorithm.
* 
* This function implements a hybrid sorting algorithm that combines merge sort 
* and insertion sort. It is optimized for small arrays by using insertion sort 
* directly when the size is less than or equal to 16. For larger arrays, it 
* recursively sorts the larger elements of pairs and inserts the smaller 
* elements using a binary search approach. The algorithm also utilizes 
* Jacobsthal numbers to determine the optimal insertion sequence.
* 
* @param arr A reference to the vector of integers to be sorted.
* 
* @details
* - Step 1: Forms pairs of elements and ensures the larger element is first 
*   in each pair.
* - Step 2: Extracts the larger elements of each pair and recursively sorts them.
* - Step 3: Inserts the smaller elements into the sorted sequence using binary 
*   search, following the Jacobsthal sequence for optimal insertion order.
* - Step 4: Handles any odd element (if the array size is odd) by inserting it 
*   into the sorted sequence.
* 
* @note The function uses debugPrint statements to log the progress of the 
*       algorithm for debugging purposes.
* 
* @warning The input vector is modified in place.
*/
void PmergeMe::mergeInsertSortVector(std::vector<int>& arr)
{
    // Base case: if the array has 1 or fewer elements, it's already sorted
    if (arr.size() == 1)
    {
        debugPrint(GREEN + std::string("Vector is already sorted (size <= 1)") + RESET);
        return ;
    }
    
    // Step 1: Form pairs and ensure larger element is first in each pair
    debugPrint(MAGENTA + std::string("Step 1: Forming pairs") + RESET);
    int par = 1;
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        
        std::ostringstream pairStr;
        pairStr << "Created " << par << "° pair: ( " << pairs.back().first << " <-----> " << pairs.back().second << " )";
        debugPrint(pairStr.str());
        par++;
    }

    // Handle odd element if array size is odd
    bool hasOdd = (arr.size() % 2 != 0);
    int oddElement = 0;
    if (hasOdd) 
    {
        oddElement = arr[arr.size() - 1];
        std::ostringstream oddStr;
        oddStr << "Handling odd element: " << oddElement;
        debugPrint(YELLOW + oddStr.str());
    }
    
    // Step 2: Extract the larger elements of each pair 
    debugPrint(MAGENTA + std::string("Step 2: Merging pairs") + RESET);
    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        largerElements.push_back(pairs[i].first);
        std::ostringstream largerStr;
        largerStr << "Larger element: " << pairs[i].first;
        debugPrint(largerStr.str());
    }

    // Step 3: Recursively sort the larger elements
    debugPrint(MAGENTA + std::string("Step 3: Recursively sorting larger elements") + RESET);
    mergeInsertSortVector(largerElements);

    // Step 4: Insert the smaller elements using binary search
    debugPrint(MAGENTA + std::string("Step 4: Inserting smaller elements using binary search") + RESET);
    std::vector<int> result;

    // Add the first pair's elements (both larger and smaller of first pair)
    result.push_back(pairs[0].second);
    result.push_back(largerElements[0]);

    std::ostringstream initStr;
    initStr << "Initialized result with first pair: " << pairs[0].second << ", " << largerElements[0];
    debugPrint(initStr.str());

    // Calculate Jacobsthal numbers for optimal insertion sequence
    debugPrint(CYAN + std::string("Calculating Jacobsthal numbers for insertion order") + RESET);
    std::vector<int> jacobsthalIndices;

    // Pre-compute a few Jacobsthal numbers (enough for our purpose)
    int j1 = 1, j2 = 3;
    jacobsthalIndices.push_back(1); // Start with index 1

    while (j2 < static_cast<int>(pairs.size()))
    {
        jacobsthalIndices.push_back(j2);
        int temp = j2;
        j2 = 2 * j1 + j2;
        j1 = temp;
    }

    std::string jacobsthalStr = "Jacobsthal indices: ";
    for (size_t i = 0; i < jacobsthalIndices.size(); i++)
    {
        std::ostringstream indStr;
        indStr << jacobsthalIndices[i];
        jacobsthalStr += indStr.str() + " ";
        if (i < jacobsthalIndices.size() - 1)
            jacobsthalStr += ", ";
    }
    debugPrint(MAGENTA + jacobsthalStr);

    // Add remaining indices in ascending order
    debugPrint(YELLOW + std::string("Adding remaining indices in ascending order") + RESET);
    for (size_t i = 1; i < pairs.size(); i++)
    {
        if (std::find(jacobsthalIndices.begin(), jacobsthalIndices.end(), i) == jacobsthalIndices.end())
        {
            jacobsthalIndices.push_back(i);
            std::ostringstream indStr;
            indStr << "Added index: " << i;
            debugPrint(indStr.str());
        }
    }

    // Insert elements according to the Jacobsthal sequence
    debugPrint(YELLOW + std::string("Inserting elements according to Jacobsthal sequence") + RESET);
    for (size_t idx = 0; idx < jacobsthalIndices.size(); idx++)
    {
        int i = jacobsthalIndices[idx];

        // Skip the first pair which is already in the result
        if (i == 0 || i >= static_cast<int>(pairs.size()))
            continue ;
        
        int largerElement = largerElements[i];
        int smallerElement = pairs[i].second;

        // Find where to insert the smaller element using binary search
        std::vector<int>::iterator smallerIt = std::lower_bound(result.begin(), result.end(), smallerElement);
        result.insert(smallerIt, smallerElement);

        // Find where to insert the larger element using binary search
        std::vector<int>::iterator largerIt = std::lower_bound(result.begin(), result.end(), largerElement);
        result.insert(largerIt, largerElement);

        std::ostringstream pairInsertStr;
        pairInsertStr << "Inserted pair: (" << smallerElement << ", " << largerElement << ")";
        debugPrint(pairInsertStr.str());
    }

    // Handle the odd element if present
    if (hasOdd)
    {
        std::ostringstream oddInsertStr;
        oddInsertStr << "Inserting odd element: " << oddElement;
        debugPrint(YELLOW + oddInsertStr.str());

        std::vector<int>::iterator it = std::lower_bound(result.begin(), result.end(), oddElement);
        result.insert(it, oddElement);
    }

    arr = result;
    debugPrint(GREEN + std::string("Merge-Insert Sort completed successfully") + RESET);
}
