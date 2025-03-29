/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:41:59 by codespace         #+#    #+#             */
/*   Updated: 2025/03/29 15:10:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Generates a random object of type A, B, or C.
 * 
 * @return Base* Pointer to the generated object.
 */
Base* generate() {
    std::srand(std::time(0));
    int random = rand() % 3;
    
    if (random == 0) 
        return new A();
    if (random == 1) 
        return new B();
    return new C();
}

/**
 * @brief Identifies the type of the object pointed to by p.
 * 
 * @param p Pointer to the object to identify.
 */
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) 
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) 
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) 
        std::cout << "C" << std::endl;
    else 
        std::cerr << "Error: Unknown type" << std::endl;
}

/**
 * @brief Identifies the type of the object referenced by p.
 * 
 * @param p Reference to the object to identify.
 *  1. Uses dynamic_cast to check if p is of type A, B, or C.
 *  2. If successful, prints the type name.
 *  3. If all checks fail, prints an error message.
 * 
 * @param p Reference to the object to identify.
 * 
 */
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception&) {}
    std::cerr << "Error: Unknown type" << std::endl;
}