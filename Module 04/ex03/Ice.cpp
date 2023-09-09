#include "Ice.hpp"

Ice::Ice(){
    std::cout << "Ice default constructor\n";
    type = "ice";  
}

Ice::Ice(std::string const & name): AMateria(name){
    std::cout << "Ice parameterized constructor\n";
    type = "ice";
}

Ice::Ice(AMateria& obj): AMateria(obj){
    std::cout << "Ice copy constructor\n";
    type = "ice";
}

Ice& Ice::operator=(AMateria& obj){
    std::cout << "Ice assignment operator\n";
    std::cout << "copied a" << obj.getType() << "!" << std::endl;
    type = "ice";
    return *this;
}

Ice::~Ice(){
    std::cout << "Ice destructed\n";
}

AMateria* Ice::clone() const{
    std::cout << "Ice cloned!\n";
    return new Ice(); 
}

void Ice::use(ICharacter & obj){
    std::cout << "* shoots an ice bolt at " << obj.getName() << " *\n";
}