#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name, bool _signed):AForm(name, _signed, 72, 45)
{} 

PresidentialPardonForm::PresidentialPardonForm():AForm("PPdfl", false, 72,45){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& obj):AForm(obj){}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& obj){
    std::cout << "Assigned Robotomy from " << obj << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << *this << " Destroyed!" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    if (executor.getGrade() > getExecGrade()) 
        throw GradeTooLowException(); 
    if (!this->isSigned()) 
        throw FormNotSigned();                 
    std::cout << executor << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}