#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <iostream>

class WrongAnimal{
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal & obj);
        WrongAnimal(std::string set_type);

        WrongAnimal& operator=(WrongAnimal& obj);
    
        virtual ~WrongAnimal();
        
        std::string getType(void) const;
        void        setType(std::string str);

        virtual void makeSound(void) const;
        
    protected:
        std::string type;
};


#endif 