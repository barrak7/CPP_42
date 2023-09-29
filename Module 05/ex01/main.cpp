#include "Bureaucrat.hpp"

int main(){
    Bureaucrat test("mowdaf", 73);
    Form        testForm("document", false, 70, 50);
    try{
        testForm.beSigned(test);
    }
    catch (Form::GradeTooHighException& e){
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException& e){
        std::cout << e.what() << std::endl;
    }
    test.signForm(testForm);
    std::cout << test << std::endl;
    std::cout << testForm << std::endl;
}