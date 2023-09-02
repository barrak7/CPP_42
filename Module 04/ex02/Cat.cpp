#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat Default constructor\n";
    type = "default";
    brain = new Brain();
}

Cat::Cat(std::string str){
    std::cout << "Cat parameterized constructor\n";
    type = str;
    brain = new Brain();
}

Cat::Cat(Cat& obj): Animal(obj){
    std::cout << "Cat copy constructor\n";
    this->type = obj.type;
    this->brain = new Brain(*obj.brain);
}

Cat& Cat::operator=(Cat& obj){
    std::cout << "Cat copy assignment operator\n";
    this->type = obj.type;
    this->brain = new Brain(*obj.brain);
    return (*this);
}

Cat::~Cat(){
    delete brain;
    std::cout << "Cat Destructor\n";
}

void Cat::makeSound(void) const{
    std::cout << type << ": mew!\n";
}