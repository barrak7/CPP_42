#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "Default ScavTrap constructor!\n";
    name = "default";
    hit = 100;
    energy = 50;
    damage = 20;
}

ScavTrap::ScavTrap(std::string Name){
    std::cout << "parameterized ScavTrap constructor!\n";
    name = Name;
    hit = 100;
    energy = 50;
    damage = 20;
}

ScavTrap::ScavTrap(ScavTrap& obj): ClapTrap(obj){
    std::cout << "ScavTrap copy constructor!\n"; 
}

ScavTrap& ScavTrap::operator=(ScavTrap& obj){
    std::cout << "ScavTrap copy constructor!\n";
    name = obj.name;
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << name << " deconstructed!\n";
}

void ScavTrap::guardGate(void){
    std::cout << "ScavTrap " << name << " is guarding the gate!\n";
}

void ScavTrap::attack(std::string target){
    if (energy == 0 || hit == 0){
        std::cout << "ScavTrap " << name << " has no energy points to hit!\n";
        return; 
    } 
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!\n";
    energy--;
    hit--;
}