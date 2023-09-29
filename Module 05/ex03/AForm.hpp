#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"
class   Bureaucrat;

class AForm{
    private:
        const   std::string name;
        bool                _signed;  
        const int           grade;
        const int           exec_grade;
    public:
        AForm();
        AForm(std::string name, bool _signed, int s_grade, int execGrade);
        AForm(AForm& obj);
        AForm& operator=(AForm& obj);
        virtual ~AForm();
        std::string getName() const;
        bool        isSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;
        void        beSigned(Bureaucrat const & obj);
        virtual void        execute(Bureaucrat const & executor) const = 0;
        class GradeTooHighException:public std::exception{
            public:
                const char *what() const throw();
        };
        class GradeTooLowException:public std::exception{
            public:
                const char *what() const throw();
        };
        class FormNotSigned:public std::exception{
            public:
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, AForm const & obj);

#endif