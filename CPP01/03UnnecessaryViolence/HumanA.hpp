#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"


class HumanA {
        std::string name;
        Weapon& weapon;
    public:
        HumanA(std::string name, Weapon& weapon);
        void attack() const;
};

#endif

/*a differenza di HumanB, HumanA ha un riferimento a Weapon,che
è inizializzato nel costruttore e non può essere modificato successivamente.
Questo significa che HumanA deve essere sempre associato a una Weapon.*/