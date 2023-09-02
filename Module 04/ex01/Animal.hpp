#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "Brain.hpp"

class Animal{
    public:
        Animal();
        Animal(Animal & obj);
        Animal(std::string set_type);

        Animal& operator=(Animal& obj);
    
        virtual ~Animal();
        
        std::string getType(void) const;
        void        setType(std::string str);

        virtual void makeSound(void) const;
        
    protected:
        std::string type;
};


#endif 