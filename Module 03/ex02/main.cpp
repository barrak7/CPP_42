#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
    ScavTrap b("b");
    ClapTrap a("a");
    FragTrap d("d");
    

    d.attack("b");
    a.takeDamage(5);
    a.beRepaired(5);
    d.attack("a");
    return (0);
}