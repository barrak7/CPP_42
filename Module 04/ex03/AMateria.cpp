#include "AMateria.hpp"

AMateria::AMateria(){
    type = "defualt";
}

AMateria::AMateria(std::string const &name){
    type = name;
}

AMateria::AMateria(AMateria& obj){
    type = obj.type;
}

AMateria& AMateria::operator=(AMateria& obj){
    this->type = obj.type;
    return (*this);
}

AMateria::~AMateria(){}


std::string const & AMateria::getType() const{
    return type;
}

void AMateria::use(ICharacter& target){
    std::cout << "Amateria " << type << " was used on " << target.getName() << std::endl;
}