#include "RobotomyRequestForm.hpp"

int RobotomyRequestForm::i = 0;

RobotomyRequestForm::RobotomyRequestForm(std::string name, bool _signed):AForm(name, _signed, 72, 45)
{} 

RobotomyRequestForm::RobotomyRequestForm():AForm("RRdfl", false, 72,45){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& obj):AForm(obj){}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& obj){
    std::cout << "Assigned Robotomy from " << obj << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << *this << " Destroyed!" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    if (executor.getGrade() > getExecGrade()) 
        throw GradeTooLowException(); 
    if (!this->isSigned()) 
        throw FormNotSigned();                 
    std::cout << "Bzzzzzzzzzz..." << std::endl;
    if (i%2)
        std::cout << executor << " has been robotimized successfully!" << std::endl;
    else
        std::cout << "Robotmy failed!" << std::endl;
    i++;
}