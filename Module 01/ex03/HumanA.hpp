#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA{
    public:
        HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon){};
        void attack(void);
    
    private:
        std::string name;
        Weapon &weapon;
};

#endif