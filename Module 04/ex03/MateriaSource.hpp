#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
    protected:
        AMateria *inventory[4];
    public:
        ~MateriaSource();
        MateriaSource();
        MateriaSource(MateriaSource& obj);
        MateriaSource& operator=(MateriaSource& obj);
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};

#endif