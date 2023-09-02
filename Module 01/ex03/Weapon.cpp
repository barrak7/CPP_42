# include "Weapon.hpp"

Weapon::Weapon(std::string string){
    type = string;
}

void Weapon::setType(std::string string){
    type = string;
}

const std::string& Weapon::getType(void){
    return type;
}