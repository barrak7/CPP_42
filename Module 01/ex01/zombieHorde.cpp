# include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name){
    if (N <= 0){
        std::cout << "Invalid number of zombies!!\n";
        return NULL;
    }
    Zombie *Horde = new Zombie[N];
    for (int i = 0; i < N; i++){
        Horde[i].init(name);
    }
    return Horde;
}