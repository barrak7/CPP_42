#include "Ice.hpp"

Ice::Ice(){
    type = "ice";  
}

Ice::Ice(std::string const & name){
    type = name;
}

Ice::Ice(AMateria& obj){
    type = "ice";
}

Ice& Ice::operator=(AMateria& obj){
    type = "ice";
}

Ice::~Ice(){}

AMateria* Ice::clone() const{
    return new Ice();
}

void Ice::use(ICharacter & obj){
    std::cout << "Ice: \"* shoots an ice bolt at " << obj.getName() << " *\"\n";
}