#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat Default constructor\n";
    type = "default";
}

Cat::Cat(std::string str){
    std::cout << "Cat parameterized constructor\n";
    type = str;
}

Cat::Cat(Cat& obj): Animal(obj){
    std::cout << "Cat copy constructor\n";
    this->type = obj.type;
}

Cat& Cat::operator=(Cat& obj){
    std::cout << "Cat copy assignment operator\n";
    this->type = obj.type;
    return (*this);
}

Cat::~Cat(){
    std::cout << "Cat Destructor\n";
}

void Cat::makeSound(void) const{
    std::cout << type << ": mew!\n";
}