#include "Cure.hpp"

Cure::Cure(){
    type = "cure";  
}

Cure::Cure(std::string const & name){
    type = "cure";
}

Cure::Cure(AMateria& obj){
    type = "cure";
}

Cure& Cure::operator=(AMateria& obj){
    type = "cure";
    return *this;
}

Cure::~Cure(){}

AMateria* Cure::clone() const{
    return new Cure(type);
}

void Cure::use(ICharacter & obj){
    std::cout << "Cure: \"* heals "<< obj.getName() <<"'s wounds *\"\n";
}