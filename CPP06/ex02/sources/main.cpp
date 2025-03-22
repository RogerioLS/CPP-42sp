/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:43:22 by codespace         #+#    #+#             */
/*   Updated: 2025/03/21 23:43:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main() {
    Base* obj = generate();
    
    std::cout << "Identificando via ponteiro: ";
    identify(obj);

    std::cout << "Identificando via referência: ";
    identify(*obj);

    delete obj;
    return (0);
}
