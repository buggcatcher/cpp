#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"


class HumanB {
        std::string name;
        Weapon* weapon;
    public:
        HumanB(std::string name);
        void setWeapon(Weapon& weapon);
        void attack() const;
};

#endif

/*a differenza di HumanA, HumanB non ha un riferimento a Weapon, ma un puntatore, e non è inizializzato nel costruttore.
Questo significa che HumanB può esistere senza una Weapon, e la Weapon può essere assegnata in un secondo momento usando il metodo setWeapon.
Inoltre, il metodo attack deve verificare se weapon è nullptr prima di tentare di accedere al suo tipo, per evitare un comportamento indefinito.
*/