#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap& obj);
        ~ScavTrap();
        ScavTrap& operator=(ScavTrap& obj);
        void guardGate(void);
        void attack(std::string target);
};

#endif