#include "Animal.hpp"

Animal::Animal(){
    type = "default";
    std::cout << "Animal Default constructor!\n";
}

Animal::Animal(std::string set_type){
    std::cout << "Animal parametrized constructor!\n";
    type = set_type;
}

Animal::Animal(Animal& obj){
    std::cout << "Animal copy operator!\n";
    this->type = obj.type;
}

Animal& Animal::operator=(Animal& obj){
    std::cout << "Animal assignment operator!\n";
    this->type = obj.type;
    return *this;
}


Animal::~Animal(){
    std::cout << "Animal Destructed!\n";
}

void Animal::makeSound(void) const{
    std::cout << "This is an animal of type: " << type << ". I'm not sure about its sound!\n";
}

void Animal::setType(std::string str){
    type = str;
}

std::string Animal::getType(void) const{
    return type;
}