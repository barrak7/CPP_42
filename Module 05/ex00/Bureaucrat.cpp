#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int _grade): name(name){
    if (_grade < 1){
        throw GradeTooHigh();
    }
    else if (_grade > 150){
        throw GradeTooLow();
    }
    grade = _grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& obj){
    grade = obj.grade;
}

Bureaucrat&  Bureaucrat::operator=(Bureaucrat& obj){
    grade = obj.grade;
    return *this;
}
 
std::string Bureaucrat::getName() const{
    return name;
}

int Bureaucrat::getGrade() const{
    return grade;
}

const char *Bureaucrat::GradeTooHigh::what() const throw(){
    return "Grade Too high!!";
}

const char *Bureaucrat::GradeTooLow::what() const throw(){
    return "Grade Too Low!!"; 
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const & obj){
    return os<<obj.getName();
}

Bureaucrat& Bureaucrat::operator++(){
    grade--;
    if (grade<1)
        throw GradeTooHigh();
    return *this;
}
Bureaucrat& Bureaucrat::operator--(){
    grade++;
    if (grade > 150)
        throw GradeTooLow();    
    return *this;
}

Bureaucrat Bureaucrat::operator++(int){
    Bureaucrat tmp = *this;
    grade--;
    if (grade<1)
        throw GradeTooHigh();
    return tmp;
}
Bureaucrat Bureaucrat::operator--(int){
    Bureaucrat tmp = *this;
    grade++;
    if (grade > 150)
        throw GradeTooLow();    
    return tmp;
}

void Bureaucrat::setGrade(int _grade){
    if (_grade < 1)
        throw GradeTooHigh();
    if (_grade > 150)
        throw GradeTooLow();
    grade = _grade;
}