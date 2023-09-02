#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"

class Ice: public AMateria{
    public:
        Ice(std::string const & type);
        Ice();
        Ice(AMateria& obj);
        ~Ice();

        Ice& operator=(AMateria &obj);

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif