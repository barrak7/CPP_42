#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon{
    public:
        Weapon(std::string string);
        const std::string& getType();
        void setType(std::string string);
    private:
        std::string type;
};

#endif