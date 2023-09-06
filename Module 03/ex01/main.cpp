#include "ScavTrap.hpp"

int main(void){
    ScavTrap b("b");
    ClapTrap a("a");
    ScavTrap c(b);

    c.attack("b");
    a.takeDamage(5);
    a.beRepaired(5);
    b.attack("a");
    return (0);
}