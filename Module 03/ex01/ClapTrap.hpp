#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap{
    public:
        ClapTrap();
        ClapTrap(std::string Name);
        ClapTrap(ClapTrap & obj);
        ClapTrap& operator=(ClapTrap& obj);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    protected:
        std::string     name;
        unsigned int    hit;
        unsigned int    energy;
        unsigned int    damage;
};

#endif