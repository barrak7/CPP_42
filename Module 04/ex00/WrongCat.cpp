#include "WrongCat.hpp"

WrongCat::WrongCat(){
    std::cout << "WrongCat Default constructor\n";
    type = "default";
}

WrongCat::WrongCat(std::string str){
    std::cout << "WrongCat parameterized constructor\n";
    type = str;
}

WrongCat::WrongCat(WrongCat& obj): WrongAnimal(obj){
    std::cout << "WrongCat copy constructor\n";
    this->type = obj.type;
}

WrongCat& WrongCat::operator=(WrongCat& obj){
    std::cout << "WrongCat copy assignment operator\n";
    this->type = obj.type;
    return (*this);
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat Destructor\n";
}

void WrongCat::makeSound(void) const{
    std::cout << type << ": mew!\n";
}