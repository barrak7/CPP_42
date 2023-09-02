#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain{
    public:
        Brain();
        Brain(Brain& obj);
        Brain& operator=(Brain& obj);

        ~Brain();
    private:
        std::string ideas[100];
};

#endif