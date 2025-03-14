/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:49:58 by codespace         #+#    #+#             */
/*   Updated: 2025/03/13 23:57:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

// ✅ Construtor padrão
Intern::Intern() {}

// ✅ Construtor de cópia
Intern::Intern(const Intern &other) { (void)other; }

// ✅ Operador de atribuição
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }

// ✅ Destrutor
Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    // ✅ Criamos um array de ponteiros para métodos membros
    AForm *(Intern::*formCreators[3])(const std::string &) = {
        &Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Error: Form name '" << formName << "' not recognized." << std::endl;
    return NULL;
}

// ✅ Métodos privados para criar cada formulário
AForm *Intern::makeShrubbery(const std::string &target) { return new ShrubberyCreationForm(target); }
AForm *Intern::makeRobotomy(const std::string &target) { return new RobotomyRequestForm(target); }
AForm *Intern::makePresidential(const std::string &target) { return new PresidentialPardonForm(target); }