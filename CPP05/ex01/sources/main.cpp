/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:28:48 by codespace         #+#    #+#             */
/*   Updated: 2025/03/13 20:52:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 42);
        Form f1("Tax Form", 50, 100);
        Form f2("Security Clearance", 30, 90);

        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;

        b1.signForm(f1);
        b1.signForm(f2);

        Bureaucrat b2("Bob", 20);
        b2.signForm(f1);
        b2.signForm(f2);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return (0);
}