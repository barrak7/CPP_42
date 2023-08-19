#include "HumanB.hpp"

void HumanB::attack(void){
    if (!weapon)
        std::cout << name << ": has no weapon!\n";
    else{
        std::cout << name << ": attackes with their weapon " << weapon->getType() << std::endl;
    }   
}

void HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon; 
}