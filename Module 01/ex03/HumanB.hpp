#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB{
    private:
        std::string name;
        Weapon *weapon;
        
    public:
        HumanB(std::string name) : name(name), weapon(NULL) {};
        void attack(void);
        void setWeapon(Weapon &weapon);
};

#endif