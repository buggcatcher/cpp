#include "Zombie.hpp"


int main(void)
{
    Zombie *z;
    z = newZombie("Luca");
    delete z;

    randomChump("Paolo");
}