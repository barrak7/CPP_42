#include "ClapTrap.hpp"

int main(void){
    ClapTrap a("a");
    ClapTrap b("b");
    ClapTrap c;

    c = b;
    a.attack("b");
    a.takeDamage(5);
    a.beRepaired(5);
    c.attack("a");
    return (0);
}