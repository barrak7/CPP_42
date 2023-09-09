#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    type = "default";
    std::cout << "WrongAnimal Default constructor!\n";
}

WrongAnimal::WrongAnimal(std::string set_type){
    std::cout << "WrongAnimal parametrized constructor!\n";
    type = set_type;
}

WrongAnimal::WrongAnimal(WrongAnimal& obj){
    std::cout << "WrongAnimal copy operator!\n";
    this->type = obj.type;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& obj){
    std::cout << "WrongAnimal assignment operator!\n";
    this->type = obj.type;
    return *this;
}


WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal Destructed!\n";
}

void WrongAnimal::makeSound(void) const{
    std::cout << "This is an Wronganimal of type: " << type << ". I'm not sure about its sound!\n";
}

void WrongAnimal::setType(std::string str){
    type = str;
}

std::string WrongAnimal::getType(void) const{
    return type;
}