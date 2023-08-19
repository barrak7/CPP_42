#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie{
    public:
        Zombie(std::string arg);
        void announce(void);
        ~Zombie();
    private:
        std::string name;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);


#endif