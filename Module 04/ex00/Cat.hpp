#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat: public Animal{
    public:
        Cat();
        Cat(std::string set_type);
        Cat(Cat & obj);
        ~Cat();

        Cat& operator=(Cat & obj);

        void makeSound(void) const;

    protected:
        std::string type;

};

#endif