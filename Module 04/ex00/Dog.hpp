#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog: public Animal{
    public:
        Dog();
        Dog(std::string set_type);
        Dog(Dog & obj);
        ~Dog();

        Dog& operator=(Dog & obj);

        void makeSound(void) const;

    protected:
        std::string type;

};

#endif