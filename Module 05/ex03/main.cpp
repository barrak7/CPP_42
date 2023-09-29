#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
    Bureaucrat Bastard;
    Bureaucrat Bastardx;
    ShrubberyCreationForm test;
    Intern slave;
    try{
        Bastard.setGrade(170);
    }
    catch (Bureaucrat::GradeTooLow &e){
        std::cout << Bastard << ": " << e.what() << std::endl;
    }
    try{
        Bastard.executeForm(test);
    }
    catch(AForm::FormNotSigned &e){
        std::cout << e.what() << std::endl;
    }
    Bastard.setGrade(145); 
    test.beSigned(Bastard);
    Bastard.setGrade(137);
    try{
        Bastard.executeForm(test);
    }
    catch(...){
        std::cout << "Something went wrong!\n";
    }
    AForm *form = slave.makeForm("robotomy request", "master");
    Bastardx.setGrade(72);
    form->beSigned(Bastardx);
    Bastardx.setGrade(45);
    form->execute(Bastardx);
    form->execute(Bastardx);
    delete form;
}