#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class Cure: public AMateria{
    public:
        Cure(std::string const & type);
        Cure();
        Cure(AMateria& obj);
        ~Cure();

        Cure& operator=(AMateria &obj);

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif