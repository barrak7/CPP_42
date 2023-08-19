#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <iostream>

class Zombie{
    public:
        Zombie();
        Zombie(std::string str);
        void init(std::string str);
        void announce(void);
        ~Zombie();
    private:
        std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif