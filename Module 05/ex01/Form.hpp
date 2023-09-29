#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
class   Bureaucrat;

class Form{
    private:
        const   std::string name;
        bool                _signed;  
        const int           grade;
        const int           exec_grade;
    public:
        Form();
        Form(std::string name, bool _signed, int s_grade, int execGrade);
        Form(Form& obj);
        Form& operator=(Form& obj);
        ~Form();
        std::string getName() const;
        bool        isSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;
        void        beSigned(Bureaucrat const & obj);
        class GradeTooHighException:public std::exception{
            public:
                const char *what() const throw();
        };
        class GradeTooLowException:public std::exception{
            public:
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, Form const & obj);

#endif