#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class Intern{
    public:
        Intern();
        Intern(Intern& obj);
        ~Intern();
        Intern& operator=(Intern& obj);
        AForm* makeForm(std::string name, std::string target);
};

#endif