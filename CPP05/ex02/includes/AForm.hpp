/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:57:12 by codespace         #+#    #+#             */
/*   Updated: 2025/03/11 23:18:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        //Constructors
        AForm();
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &other);
        //Assignment operator
        AForm &operator=(const AForm &other);
        //Virtual Destructor
        virtual ~AForm();

        // Public methods
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat &b);

        // Pure Virtual Methods Abstract
        virtual void execute(Bureaucrat const & executor) const = 0;
        
        // Class Exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };

    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

};

std::ostream &operator<<(std::ostream &out, const AForm &form);