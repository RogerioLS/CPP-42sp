/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:57:00 by codespace         #+#    #+#             */
/*   Updated: 2025/03/05 19:23:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    public:
        //Constructors
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        //Assignment operator
        Form &operator=(const Form &other);
        //Destructor
        ~Form();

        //Class Exceptions
        class GradeTooHighException : public std::exception {
            public: 
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public: 
                const char* what() const throw();
        };
    
        //Public methods
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat &b);

    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
        
};

std::ostream &operator<<(std::ostream &out, const Form &f);