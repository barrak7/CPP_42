#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "Default FragTrap constructor!\n";
    name = "default";
    hit = 100;
    energy = 100;
    damage = 30;
}

FragTrap::FragTrap(std::string Name){
    std::cout << "parameterized FragTrap constructor!\n";
    name = Name;
    hit = 100;
    energy = 100;
    damage = 30;
}

FragTrap::FragTrap(FragTrap& obj): ClapTrap(obj){
    std::cout << "FragTrap copy constructor!\n";
}

FragTrap& FragTrap::operator=(FragTrap& obj){
    std::cout << "FragTrap copy constructor!\n";
    name = obj.name;
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << name << " deconstructed!\n";
}

void FragTrap::highFivesGuys(void){
    std::cout << name << ": High Five Guys!\n";
}