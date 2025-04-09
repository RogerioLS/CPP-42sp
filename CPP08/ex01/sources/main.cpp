/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 00:35:56 by codespace         #+#    #+#             */
/*   Updated: 2025/04/05 17:16:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include "../includes/Span.tpp"

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        Span bigSpan(10000);
        std::vector<int> range(10000);
        for (int i = 0; i < 10000; ++i)
            range[i] = i;
        bigSpan.addRange(range.begin(), range.end());

        std::cout << "Shortest Span in bigSpan: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span in bigSpan: " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return (0);
}