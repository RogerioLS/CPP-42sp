/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:28:31 by codespace         #+#    #+#             */
/*   Updated: 2025/03/23 15:05:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include "../includes/Array.tpp"

int main() {
    try {
        Array<int> arr(5);

        for (unsigned int i = 0; i < arr.size(); i++)
            arr[i] = i * 10;

        // Exibindo os valores
        std::cout << "Array values: ";
        for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;

        // Testando cópia
        Array<int> copyArr = arr;
        copyArr[2] = 100; // Modificar a cópia não pode afetar o original
        std::cout << "Original array[2]: " << arr[2] << std::endl;
        std::cout << "Copied array[2]: " << copyArr[2] << std::endl;

        // Testando exceção de acesso inválido
        std::cout << arr[10] << std::endl; // Deve lançar um erro
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return (0);
}