#include "Zombie.hpp"

  // Qui l'oggetto stackZombie esiste solo all'interno del blocco della funzione randomChump.
 //  La memoria per l'oggetto viene allocata automaticamente e la sua durata
//   è limitata al blocco/funzione corrente. 

void randomChump(std::string name) {
    Zombie stackZombie(name); // Allocazione
    stackZombie.announce();  //  Deallocazione automatica
}
