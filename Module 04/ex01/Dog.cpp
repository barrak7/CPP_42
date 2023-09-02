#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog Default constructor\n";
    type = "default";
    brain = new Brain();
}

Dog::Dog(std::string str){
    std::cout << "Dog parameterized constructor\n";
    type = str;
    brain = new Brain();
}

Dog::Dog(Dog& obj): Animal(obj){
    std::cout << "Dog copy constructor\n";
    this->type = obj.type;
    this->brain = new Brain(*obj.brain);
}

Dog& Dog::operator=(Dog& obj){
    std::cout << "Dog copy assignment operator\n";
    this->type = obj.type;
    this->brain = new Brain(*obj.brain);
    return (*this);
}

Dog::~Dog(){
    delete brain;
    std::cout << "Dog Destructor\n";
}

void Dog::makeSound(void) const{
    std::cout << type << ": Woof!\n";
}