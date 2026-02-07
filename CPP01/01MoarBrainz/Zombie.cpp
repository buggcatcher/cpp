#include "Zombie.hpp"

void Zombie::announce(){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

Zombie::~Zombie(){
    std::cout << "\033[31m" << name << " was terminated\033[0m" << std::endl;
}