#include "Zombie.hpp"

int main() {
    Zombie* heapZombie;

    heapZombie = newZombie("student");
    delete heapZombie;
    randomChump("hannibal");
    return 0;
}

/*
La classe Zombie rappresenta un oggetto con un nome e un metodo announce() che stampa un messaggio.
Costruttore e distruttore della classe stampano messaggi per mostrare creazione/distruzione.
*/

