#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

class Form;
#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat{
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat& obj);
        Bureaucrat& operator=(Bureaucrat& obj);
        ~Bureaucrat();
        void         setGrade(int _grade);
        std::string getName() const;
        int         getGrade() const;
        void        signForm(Form& form) const;
        class GradeTooHigh:public std::exception{
            public:
                const char *what() const throw();
        };
        class GradeTooLow:public std::exception{
            public:
                const char *what() const throw();
        };
        Bureaucrat& operator++();
        Bureaucrat& operator--();
        Bureaucrat operator++(int);
        Bureaucrat operator--(int); 
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const & obj);

#endif