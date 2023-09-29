#include "Bureaucrat.hpp"

int main(){
    try{
        Bureaucrat test("name", 151);
    }
    catch(Bureaucrat::GradeTooLow& e){
        std::cout << e.what() << std::endl;
    }
    catch (...){
        std::cout << "Cought" << std::endl;
    }
    Bureaucrat test;
    try{
        std::cout << "before "<<test.getGrade() << std::endl;
        test++;
        std::cout << "after " <<test.getGrade() << std::endl;
    }
    catch(std::exception& e){
        std::cout <<e.what()<<std::endl;
    }
    Bureaucrat low("low", 120);
    try{
        for (int i = 0; i < 100; i++){
            low--;
        }
    }
    catch (Bureaucrat::GradeTooLow& e){
        std::cout << e.what() << std::endl;
    }
    Bureaucrat high("high", 10);
    try{
        for (int i = 0; i < 100; i++){
            high++;
        }
    }
    catch (Bureaucrat::GradeTooLow &e){
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHigh &e){
        std::cout << high << " " << e.what() << std::endl;
    }

    try{
        throw 10;
    }
    catch (std::exception &e){
        std::cout << "Caught exception!" << std::endl;
    }
    catch (double code){
        std::cout << code << std::endl;
    }
    catch (...){
        std::cout << "caught unkown exception\n";
    }
}