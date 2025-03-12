/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:19:37 by codespace         #+#    #+#             */
/*   Updated: 2025/03/11 23:23:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        std::cout << "\n=== Created Bureaucrats ===\n";
        Bureaucrat highRank("Alice", 1);
        Bureaucrat midRank("Bob", 50);
        Bureaucrat lowRank("Charlie", 150);

        std::cout << "\n=== Created Form ===\n";
        ShrubberyCreationForm shrubForm("Home");
        RobotomyRequestForm robotForm("Bender");
        PresidentialPardonForm pardonForm("Zaphod");

        std::cout << "\n=== Attempting to sign the forms ===\n";
        lowRank.signForm(shrubForm);   
        midRank.signForm(robotForm);   
        highRank.signForm(shrubForm); 
        highRank.signForm(robotForm); 
        highRank.signForm(pardonForm);

        std::cout << "\n=== Attempting to execute the forms ===\n";
        lowRank.executeForm(shrubForm);
        midRank.executeForm(robotForm);
        highRank.executeForm(shrubForm);
        highRank.executeForm(robotForm);
        highRank.executeForm(pardonForm);

    } catch (std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
    return (0);
}
