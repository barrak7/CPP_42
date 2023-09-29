#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
    private:
        static int i;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm& obj);
        RobotomyRequestForm(std::string name, bool _signed);
        RobotomyRequestForm& operator=(RobotomyRequestForm& obj);
        ~RobotomyRequestForm(); 
        void execute(Bureaucrat const & executor) const; 
};

#endif