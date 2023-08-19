# include "Zombie.hpp"

int main(void){
    Zombie* test = newZombie("Test");

    test->announce();
    randomChump("Random");
    delete test;
    
}