#include "Zombie.hpp"

int main()
{
    int N = 5;
    std::string name = "Clicker";
    Zombie *horde = zombieHorde(N, name);
    int i = 0;
    while(i < N)
        horde[i++].announce();
    delete[] horde;
}