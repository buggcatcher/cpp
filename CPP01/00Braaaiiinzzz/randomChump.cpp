#include "Zombie.hpp"

// void randomChump(std::string name) {
//     Zombie *z = new Zombie;
//     z->setName(name);
//     z->announce();
//     delete z;
//  }  // STACK

void randomChump(std::string name) {
    Zombie z;
    z.setName(name);
    z.announce();
}