#include "Zombie.hpp"

// Crea uno Zombie sull'heap: chi chiama la funzione è responsabile di chiamare delete
Zombie* newZombie(std::string name) {
    return new Zombie(name);
}
