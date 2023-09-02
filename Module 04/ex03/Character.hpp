#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

typedef struct trash {
    void *ptr;
    struct trash *next;
} t_trash;

class Character: public ICharacter{
    private:
        AMateria *inventory[4];
        t_trash *trash;
        t_trash *head;
    public:
        ~Character();
        Character();
        Character(Character& obj);
        Character& operator=(Character& obj);
        Character(std::string str);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

};

#endif