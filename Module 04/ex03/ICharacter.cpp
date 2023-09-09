#include "ICharacter.hpp"

ICharacter::ICharacter(){
    std::cout << "ICharacter default constructor\n";
    name = "Defualt";
}

ICharacter::ICharacter(std::string str){
    std::cout << "ICharacter parameterized constructor\n";
    name = str;
}

ICharacter::ICharacter(ICharacter& obj){
    std::cout << "ICharacter copy constructor\n";
    name = obj.name;
}

ICharacter& ICharacter::operator=(ICharacter& obj){
    std::cout << "ICharacter copy operator\n";
    name = obj.name;
    return *this;
}