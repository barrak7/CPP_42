#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    name = "default";
    hit = 10;
    energy = 10;
    damage = 0;
}

ClapTrap::ClapTrap(std::string Name){
    name = Name;
    hit = 10;
    energy = 10;
    damage = 0;
}

ClapTrap::ClapTrap(ClapTrap& obj){
    name = obj.name;
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
}

ClapTrap& ClapTrap::operator=(ClapTrap& obj){
    name = obj.name;
    hit = obj.hit;
    energy = obj.energy;
    damage = obj.damage;
    return *this;
}

ClapTrap::~ClapTrap(){
}

void ClapTrap::attack(const std::string &target){
    if (energy == 0 || hit == 0){
        std::cout << "ClapTrap " << name << " has no energy points to hit!\n";
        return; 
    } 
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << damage << " points of damage!\n";
    energy--;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (energy == 0){
        std::cout << "ClapTrap " << name << " has no energy points to be repaired!\n";
        return ;
    }
    std::cout << name << " was repaired!\n";
    hit += amount;
    energy--;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (hit == 0){
        std::cout << name << " is already out of hit points!\n";
        return ;
    }
    if (amount > hit){
        std::cout << name << " doesn't have " << amount << " points!\n";
        return ;
    }
    std::cout << name << " took " << amount << " damage!\n";
    hit -= amount;
}