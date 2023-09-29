#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm& obj);
        PresidentialPardonForm(std::string name, bool _signed);
        PresidentialPardonForm& operator=(PresidentialPardonForm& obj);
        ~PresidentialPardonForm(); 
        void execute(Bureaucrat const & executor) const; 
};

#endif