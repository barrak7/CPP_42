#ifndef WRONG_CAT_H
#define WRONG_CAT_H

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
    public:
        WrongCat();
        WrongCat(std::string set_type);
        WrongCat(WrongCat & obj);
        ~WrongCat();

        WrongCat& operator=(WrongCat & obj);

        void makeSound(void) const;

    protected:
        std::string type;

};

#endif