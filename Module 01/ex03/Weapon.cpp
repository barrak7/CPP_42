# include "Weapon.hpp"

Weapon::Weapon(std::string string){
    type = string;
}

void Weapon::setType(std::string string){
    type = string;
}

std::string Weapon::getType(void){
    return type;
}