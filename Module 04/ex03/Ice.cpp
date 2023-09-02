#include "Ice.hpp"

Ice::Ice(){
    type = "ice";  
}

Ice::Ice(std::string const & name): AMateria(name){
    type = "ice";
}

Ice::Ice(AMateria& obj): AMateria(obj){
    type = "ice";
}

Ice& Ice::operator=(AMateria& obj){
    std::cout << "copied a" << obj.getType() << "!" << std::endl;
    type = "ice";
    return *this;
}

Ice::~Ice(){}

AMateria* Ice::clone() const{
    return new Ice(); 
}

void Ice::use(ICharacter & obj){
    std::cout << "* shoots an ice bolt at " << obj.getName() << " *\n";
}