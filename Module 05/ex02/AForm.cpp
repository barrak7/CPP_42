#include "AForm.hpp"

AForm::AForm():name("default"),_signed(false),grade(150),exec_grade(120){}

AForm::AForm(std::string name, bool _signed, int s_grade, int execGrade):name(name),_signed(_signed),grade(s_grade),exec_grade(execGrade){
    if (s_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
    else if (s_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
}

AForm::AForm(AForm& obj):name(obj.name),_signed(obj._signed),grade(obj.grade),exec_grade(obj.exec_grade){}

AForm& AForm::operator=(AForm& obj){
    std::cout << "Copy assignment from " << obj << " Aform" << std::endl;
    return *this;
}


AForm::~AForm(){
    std::cout << *this << " destructed!!" << std::endl;
}

std::string AForm::getName() const{
    return name;
}

int AForm::getSignGrade() const { 
    return grade;
}

int AForm::getExecGrade() const{
    return exec_grade;
}

bool AForm::isSigned() const{
    return _signed;
}

void AForm::beSigned(Bureaucrat const & obj){
    if (obj.getGrade() > grade)
        throw GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream& os, AForm const & obj){
    return os << obj.getName();
}

const char *AForm::GradeTooHighException::what() const throw(){
    return "AForm Exception: The grade is Too High!!";
}

const char *AForm::GradeTooLowException::what() const throw(){
    return "AForm Exception: The grade is Too Low!!";
}

const char *AForm::FormNotSigned::what() const throw(){
    return "AForm Exception: AFormNotSigned!!";
}