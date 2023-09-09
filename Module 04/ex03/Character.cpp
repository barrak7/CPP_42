#include "Character.hpp"

Character::Character(){
    std::cout << "Character default constructor\n";
    trash = 0;
    head = 0;
    name = "Default";
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character::Character(std::string str){
    std::cout << "Character parameterized constructor\n";
    trash = 0;
    head = 0;
    name = str;
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character::Character(Character& obj): ICharacter(obj){
    std::cout << "Character copy constructor\n";
    trash = 0;
    head = 0;
    name = obj.getName();
    for (int i = 0; i < 4; i++){
        if (obj.inventory[i]){
            inventory[i] = obj.inventory[i][0].clone();
        }
    }
}

Character& Character::operator=(Character& obj){
    std::cout << "Character assignment operator\n";
    if (&obj==this)
        return *this;
    name = obj.getName();
    for (int i = 0; i < 4; i++){
        if (inventory[i])
            delete inventory[i];
        if (obj.inventory[i])
            inventory[i] = obj.inventory[i]->clone();
    }
    return *this;
}

Character::~Character(){
    std::cout << "Character destructor\n";
    while (head){
        trash = head->next;
        delete head->ptr;
        delete head;
        head = trash;
    }
    for (int i = 0; i < 4; i++){
        if (inventory[i])
            delete inventory[i];
    }
}

void Character::equip(AMateria *m){
    if (!m){
        std::cout << "Character: AMateria ptr can't be NULL\n";
        return ;
    }
    for (int i = 0; i < 4; i++){
        if (!inventory[i]){
            inventory[i] = m;
            std::cout << "Equiped!\n";
            return ;
        }
    }
    std::cout << "Character already has 4 AMaterias\n";
}

void Character::unequip(int idx){
    if (idx < 0 || idx>3 || !inventory[idx]){
        std::cout << "Index out of range!\n";
        return ;
    }
    if (trash == 0)
        head = trash = new t_trash;
    else{
        trash->next = new t_trash;
        trash = trash->next;
    }
    trash->ptr = inventory[idx];
    trash->next = 0;
    inventory[idx] = 0;
    std::cout << "Unequiped!\n";
}

void Character::use(int idx, ICharacter& target){
    if (idx < 0 || idx > 3 || !inventory[idx]){
        std::cout << "Can't be used!\n";
        return;
    }
    inventory[idx]->use(target);
}

std::string const &Character::getName() const{
    return name;
}