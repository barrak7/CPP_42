#include "Zombie.hpp"

Zombie::Zombie(std::string arg){
    name = arg;
}

Zombie::~Zombie(){
    std::cout << name << ": dead\n";
}

void Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}