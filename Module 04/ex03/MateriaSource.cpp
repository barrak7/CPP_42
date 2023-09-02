#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++){
        inventory[i] = 0;
    }
}

MateriaSource::MateriaSource(MateriaSource& obj): IMateriaSource(obj){
    for (int i = 0; i < 4; i++){
        if (obj.inventory[i])
            inventory[i] = obj.inventory[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource& obj){
    for (int i = 0; i < 4; i++){
        if (obj.inventory[i])
            inventory[i] = obj.inventory[i]->clone();
    }
    return *this;
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++){
        if (inventory[i])
            delete inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria* m){
    if (!m)
        return;
    for (int i = 0; i < 4; i++){
        if (!inventory[i]){
            inventory[i] = m;
            break ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type){
    if (type == "ice")
        return (new Ice());
    if (type == "cure")
        return (new Cure());
    std::cout << "Invalid AMateria type!!\n";
    return (0);
}