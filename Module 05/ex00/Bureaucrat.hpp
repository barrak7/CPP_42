#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <exception>

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
        std::string getName() const;
        int         getGrade() const;
        void         setGrade(int _grade);
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