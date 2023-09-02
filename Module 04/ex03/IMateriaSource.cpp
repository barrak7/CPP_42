#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(){
    for (int i = 0; i < 4; i++){
        inventory[i] = 0;
    }
}

IMateriaSource::IMateriaSource(IMateriaSource& obj){
    for (int i = 0 ; i < 4; i++){
        if (obj.inventory[i])
            inventory[i] = obj.inventory[i]->clone();
    }
}

IMateriaSource& IMateriaSource::operator=(IMateriaSource& obj){
    for (int i = 0 ; i < 4; i++){
        if (obj.inventory[i])
            inventory[i] = obj.inventory[i]->clone();
    }
    return *this;
}