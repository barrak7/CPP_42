#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    std::cout << "MateriaSource default constructor\n";
    for (int i = 0; i < 4; i++){
        inventory[i] = 0;
    }
}

MateriaSource::MateriaSource(MateriaSource& obj): IMateriaSource(obj){
    std::cout << "MateriaSource copy constructor\n";
    for (int i = 0; i < 4; i++){
        if (obj.inventory[i])
            inventory[i] = obj.inventory[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource& obj){
    std::cout << "MateriaSource assignment operator\n";
    for (int i = 0; i < 4; i++){
        if (obj.inventory[i])
            inventory[i] = obj.inventory[i]->clone();
    }
    return *this;
}

MateriaSource::~MateriaSource(){
    std::cout << "MateriaSource destructor\n";
    for (int i = 0; i < 4; i++){
        if (inventory[i])
            delete inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria* m){
    if (!m){
        std::cout << "The AMateria passed is NULL\n";
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!inventory[i]){
            inventory[i] = m;
            std::cout << "AMateria learned!\n";
            return ;
        }
    }
    std::cout << "MateriaSource is already full!\n";
}

AMateria* MateriaSource::createMateria(std::string const &type){
    if (type == "ice")
        return (new Ice());
    if (type == "cure")
        return (new Cure());
    std::cout << "Invalid AMateria type!!\n";
    return (0);
}