#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string type;

public:
    AMateria(std::string const & type);
    AMateria();
    AMateria(AMateria& obj);
    virtual ~AMateria();

    AMateria& operator=(AMateria &obj);

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif