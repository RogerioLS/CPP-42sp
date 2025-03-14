/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:47:40 by codespace         #+#    #+#             */
/*   Updated: 2025/03/13 23:57:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>

class Intern {
    public:
        Intern();
        Intern(Intern const &other);
        Intern &operator=(Intern const &other);
        ~Intern();


        AForm *makeForm(std::string const &formName, std::string const &target);
    
    private:
        AForm *makeShrubbery(const std::string &target);
        AForm *makeRobotomy(const std::string &target);
        AForm *makePresidential(const std::string &target);
};