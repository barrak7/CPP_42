#ifndef IMATERIASOURCE_H
#define IMATERIASOURCE_H

#include "AMateria.hpp"

class IMateriaSource
{
    protected:
        AMateria *inventory[4];
    public:
        virtual ~IMateriaSource() {};
        IMateriaSource();
        IMateriaSource(IMateriaSource& obj);
        IMateriaSource& operator=(IMateriaSource& obj);
        virtual void learnMateria(AMateria* m) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif