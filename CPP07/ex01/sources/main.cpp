/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:00:40 by codespace         #+#    #+#             */
/*   Updated: 2025/03/22 17:51:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

template <typename T>
void printElement(T element)
{
    std::cout << element << std::endl;
}

void increment(int &element)
{
    element++;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << "Array original: ";
    iter(intArr, intSize, printElement<int>);
    std::cout << "\n";

    std::cout << "Array increment: ";
    iter(intArr, intSize, increment);
    iter(intArr, intSize, printElement<int>);
    std::cout << "\n";

    char charArr[] = {'A', 'B', 'C', 'D', 'E'};
    size_t charSize = sizeof(charArr) / sizeof(charArr[0]);

    std::cout << "Array of character: ";
    iter(charArr, charSize, printElement<char>);
    std::cout << "\n";

    return (0);
}