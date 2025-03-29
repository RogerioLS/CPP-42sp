/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:43:22 by codespace         #+#    #+#             */
/*   Updated: 2025/03/29 15:08:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

/**
 * @brief Main function to test the polymorphic behavior of the Base class and its derived classes.
 * 
 * @return int
 */
int main() {
    Base* obj = generate();
    
    std::cout << "Identify via pointer: ";
    identify(obj);

    std::cout << "Identify via reference: ";
    identify(*obj);

    delete obj;
    return (0);
}
