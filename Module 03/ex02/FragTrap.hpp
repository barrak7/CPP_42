#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap& obj);
        ~FragTrap();
        FragTrap& operator=(FragTrap& obj);
        void highFivesGuys(void);
        void attack(std::string target);

};

#endif