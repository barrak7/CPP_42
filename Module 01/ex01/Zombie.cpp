# include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string str){
    name = str;
}

void Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::init(std::string str){
    name = str;
}

Zombie::~Zombie(){
    std::cout << name <<": Dead!!\n";
}