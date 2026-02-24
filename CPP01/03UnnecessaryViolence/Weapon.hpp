#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
        std::string type;
    public:
        Weapon(std::string type);
        const std::string& getType() const;
        void setType(std::string type);
        ~Weapon();
};

#endif

/*const a inizio e fine è una pratica comune per i getter per garantire che
il valore non possa essere cambiato accidentalmente dopo essere stato restituito dal getter.
il primo const indica che il metodo non modificherà l'oggetto, mentre
il secondo che il valore restituito non può essere modificato.*/

/**/

/**/