#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm& obj);
        ShrubberyCreationForm(std::string name, bool _signed);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm& obj);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
        
};
 
#endif