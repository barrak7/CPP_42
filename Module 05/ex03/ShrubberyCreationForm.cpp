#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, bool _signed):AForm(name, _signed, 145, 137)
{} 

ShrubberyCreationForm::ShrubberyCreationForm():AForm("SHdfl", false, 145,137){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& obj):AForm(obj){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& obj){
    std::cout << "Assigned Shrubbery from " << obj << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << *this << " Destroyed!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{   
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    if (!this->isSigned()) 
        throw FormNotSigned();
    std::string tree = "              v .   ._, |_  .,\n\
           `-._\\/  .  \\ /    |/_\n\
               \\  _\\, y | \\//\n\
         _\\_.___\\, \\/ -.\\|| \n\
           `7-,--.`._||  / / ,\n\
           /'     `-. `./ / |/_.'\n\
                     |    |//\n\
                     |_    /\n\
                     |-   |\n\
                     |   =|\n\
                     |    |\n\
--------------------/ ,  . \\--------._";
    std::ofstream file((executor.getName() + "_shrubbery").c_str());
    file << tree << std::endl;
    file.close();
}
    