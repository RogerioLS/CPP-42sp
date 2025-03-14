/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:19:37 by codespace         #+#    #+#             */
/*   Updated: 2025/03/13 23:55:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm *form1;
    AForm *form2;
    AForm *form3;
    AForm *invalidForm;

    form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
    form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    form3 = someRandomIntern.makeForm("presidential pardon", "Zaphod");
    invalidForm = someRandomIntern.makeForm("unknown form", "Nobody");

    Bureaucrat alice("Alice", 1);
    
    if (form1) {
        alice.signForm(*form1);
        alice.executeForm(*form1);
        delete form1;
    }
    if (form2) {
        alice.signForm(*form2);
        alice.executeForm(*form2);
        delete form2;
    }
    if (form3) {
        alice.signForm(*form3);
        alice.executeForm(*form3);
        delete form3;
    }
    if (invalidForm) {
        delete invalidForm;
    }

    return 0;
}
