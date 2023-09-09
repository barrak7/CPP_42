#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(){
    std::cout << "IMateriaSource default constructor\n";
    for (int i = 0; i < 4; i++){
        inventory[i] = 0;
    }
}

IMateriaSource::IMateriaSource(IMateriaSource& obj){
    std::cout << "IMateriaSource copy constructor\n";
    for (int i = 0 ; i < 4; i++){
        if (obj.inventory[i])
            inventory[i] = obj.inventory[i]->clone();
    }
}

IMateriaSource& IMateriaSource::operator=(IMateriaSource& obj){
    std::cout << "IMateriaSource assignment operator\n";
    for (int i = 0 ; i < 4; i++){
        if (obj.inventory[i])
            inventory[i] = obj.inventory[i]->clone();
    }
    return *this;
}