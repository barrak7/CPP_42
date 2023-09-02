#include "ICharacter.hpp"

ICharacter::ICharacter(){
    name = "Defualt";
}

ICharacter::ICharacter(std::string str){
    name = str;
}

ICharacter::ICharacter(ICharacter& obj){
    name = obj.name;
}

ICharacter& ICharacter::operator=(ICharacter& obj){
    name = obj.name;
    return *this;
}