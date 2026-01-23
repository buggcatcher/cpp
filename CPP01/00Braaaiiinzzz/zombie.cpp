#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : name(name) {
    announce();
}

Zombie::~Zombie() {
    std::cout << name << " was destroyed" << std::endl;
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}







