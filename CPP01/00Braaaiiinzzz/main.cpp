#include "Zombie.hpp"

int main() {
    Zombie* heapZombie;
    heapZombie = newZombie("dynamic_m_alloc");
    delete heapZombie;
    randomChump("student");
    return 0;
}
/*
La classe Zombie rappresenta un oggetto con un nome e un metodo announce() che stampa un messaggio.

Costruttore e distruttore della classe stampano messaggi per mostrare creazione/distruzione.

    // HEAP: usa l'heap (new/delete) quando vuoi che l'oggetto sopravviva oltre la funzione corrente,
    //       o quando la dimensione dell'oggetto è molto grande o non nota a compile-time.
    // STACK: usa lo stack per oggetti temporanei, locali a una funzione o a un blocco.
*/

