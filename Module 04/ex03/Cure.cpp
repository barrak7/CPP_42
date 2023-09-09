#include "Cure.hpp"

Cure::Cure(){
    std::cout << "Cure default constructor\n";
    type = "cure";   
}

Cure::Cure(std::string const & name): AMateria(name) {
    std::cout << "Cure parameterized constructor\n";
    type = "cure";
}

Cure::Cure(AMateria& obj): AMateria(obj){
    std::cout << "Cure copy constructor called!\n";
    type = "cure";
}

Cure& Cure::operator=(AMateria& obj){
    std::cout << "copied a" << obj.getType() << "!" << std::endl;
    type = "cure";  
    return *this;
}

Cure::~Cure(){
    std::cout << "Cure default destructor\n";
}

AMateria* Cure::clone() const{
    std::cout << "Cure cloned!\n";
    return new Cure(type);
}

void Cure::use(ICharacter & obj){
    std::cout << "* heals "<< obj.getName() <<"'s wounds *\n";
}