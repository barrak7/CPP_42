#include "Cure.hpp"

Cure::Cure(){
    type = "cure";   
}

Cure::Cure(std::string const & name): AMateria(name) { 
    type = "cure";
}

Cure::Cure(AMateria& obj): AMateria(obj){
    type = "cure";
}

Cure& Cure::operator=(AMateria& obj){
    std::cout << "copied a" << obj.getType() << "!" << std::endl;
    type = "cure";  
    return *this;
}

Cure::~Cure(){}

AMateria* Cure::clone() const{
    return new Cure(type);
}

void Cure::use(ICharacter & obj){
    std::cout << "* heals "<< obj.getName() <<"'s wounds *\n";
}