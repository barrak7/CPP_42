#include "Form.hpp"

Form::Form():name("default"),_signed(false),grade(150),exec_grade(120){}

Form::Form(std::string name, bool _signed, int s_grade, int execGrade):name(name),_signed(_signed),grade(s_grade),exec_grade(execGrade){
    if (s_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
    else if (s_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
}

Form::Form(Form& obj):name(obj.name),_signed(obj._signed),grade(obj.grade),exec_grade(obj.exec_grade){}

Form& Form::operator=(Form& obj){
    std::cout << "Copy assignment from " << obj << " form" << std::endl;
    return *this;
}


Form::~Form(){
    std::cout << *this << " destructed!!" << std::endl;
}

std::string Form::getName() const{
    return name;
}

int Form::getSignGrade() const{
    return grade;
}

int Form::getExecGrade() const{
    return exec_grade;
}

bool Form::isSigned() const{
    return _signed;
}

void Form::beSigned(Bureaucrat const & obj){
    if (obj.getGrade() > grade) 
        throw GradeTooLowException();
    _signed = true;
}

std::ostream &operator<<(std::ostream& os, Form const & obj){
    return os << obj.getName();
}

const char *Form::GradeTooHighException::what() const throw(){
    return "Form Exception: The grade is Too High!!";
}

const char *Form::GradeTooLowException::what() const throw(){
    return "Form Exception: The grade is Too Low!!";
}