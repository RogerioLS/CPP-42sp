/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:34:54 by codespace         #+#    #+#             */
/*   Updated: 2025/03/04 15:35:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdexcept>

class Bureaucrat
{
    public:
        //Constructors
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        //Assignment operator
        Bureaucrat &operator=(const Bureaucrat &other);
        //Destructor
        ~Bureaucrat();

        // Public methods
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        // Class Exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};
