#include "HumanA.hpp"

void HumanA::attack(){
    std::cout << name << ": attacks with their weapon " << weapon.getType() << std::endl;
}