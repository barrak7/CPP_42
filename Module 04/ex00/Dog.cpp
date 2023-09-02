#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog Default constructor\n";
    type = "default";
}

Dog::Dog(std::string str){
    std::cout << "Dog parameterized constructor\n";
    type = str;
}

Dog::Dog(Dog& obj): Animal(obj){
    std::cout << "Dog copy constructor\n";
    this->type = obj.type;
}

Dog& Dog::operator=(Dog& obj){
    std::cout << "Dog copy assignment operator\n";
    this->type = obj.type;
    return (*this);
}

Dog::~Dog(){
    std::cout << "Dog Destructor\n";
}

void Dog::makeSound(void) const{
    std::cout << type << ": Woof!\n";
}