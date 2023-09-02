#include "Character.hpp"

Character::Character(){
    trash = 0;
    head = 0;
    name = "Default";
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character::Character(std::string str){
    trash = 0;
    head = 0;
    name = str;
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character::Character(Character& obj): ICharacter(obj){
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
    if (!m)
        return ;
    for (int i = 0; i < 4; i++){
        if (!inventory[i]){
            inventory[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx){
    if (idx < 0 || idx>3 || !inventory[idx])
        return ;
    if (trash == 0)
        head = trash = new t_trash;
    else{
        trash->next = new t_trash;
        trash = trash->next;
    }
    trash->ptr = inventory[idx];
    trash->next = 0;
    inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target){
    if (idx < 0 || idx > 3 || !inventory[idx])
        return;
    inventory[idx]->use(target);
}

std::string const &Character::getName() const{
    return name;
}