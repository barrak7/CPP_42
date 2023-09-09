#include "AMateria.hpp"

AMateria::AMateria(){
    type = "defualt";
    std::cout << "Amateria default constructor\n";
}

AMateria::AMateria(std::string const &name){ 
    type = name;
    std::cout << "AMateria parameterized constructor\n";
}

AMateria::AMateria(AMateria& obj){
    type = obj.type;
    std::cout << "AMateria Copy Constructor\n";
}

AMateria& AMateria::operator=(AMateria& obj){
    this->type = obj.type;
    std::cout << "AMateria assignment operator" << std::endl;
    return (*this);
}

AMateria::~AMateria(){
    std::cout << "AMateria Destructor\n";
}


std::string const & AMateria::getType() const{
    return type;
}

void AMateria::use(ICharacter& target){
    std::cout << "Amateria " << type << " was used on " << target.getName() << std::endl;
}