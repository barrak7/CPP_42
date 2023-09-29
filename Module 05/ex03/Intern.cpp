#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Intern default constructor!\n";
}

Intern::Intern(Intern& obj){
    std::cout << "Intern Copy construction from: " << &obj << std::endl; 
}

Intern& Intern::operator=(Intern &obj){
    std::cout << "Intern Copy operator from: " << &obj << std::endl; 
    return *this;
}

Intern::~Intern(){
    std::cout << "Intern destructed!" << std::endl;
}

AForm *Intern::makeForm(std::string name, std::string target){
    std::string names[3] = {"robotomy request", "shurbbery creation","presidential pardon"};
    int index = -1;
    for (int i = 0; i < 3; i++){
        if (name == names[i])
            index = i;
    }
    if (index == -1){
        std::cout << "No such form!" << std::endl;
        return NULL;
    }
    AForm *form;
    switch (index){
        case 0:
            form = new RobotomyRequestForm(target, false);
            std::cout << "Intern creates " << *form << std::endl;
            break;
        case 1:
            form = new ShrubberyCreationForm(target, false);
            std::cout << "Intern creates " << *form <<std::endl;
            break;
        case 2:
            form = new PresidentialPardonForm(target, false);
            std::cout << "Intern creates "<<*form<<std::endl;
            break;
        default:
            std::cout << "Form creation failed!\nNo such form!\n";
            form = NULL;
    }
    return form;
}