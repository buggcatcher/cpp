#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie {
    std::string name;
public:
    void announce();
    void setName(std::string name);
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif