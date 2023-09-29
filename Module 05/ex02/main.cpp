#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
    Bureaucrat Bastard;
    Bureaucrat Bastardx;
    ShrubberyCreationForm test;
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
}