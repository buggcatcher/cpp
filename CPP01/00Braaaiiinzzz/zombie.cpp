#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : name(name) {
}

Zombie::~Zombie() {
    std::cout << name << "\033[31m was destroyed\033[0m" << std::endl;
}

void Zombie::announce() {
    std::cout << name << ": \033[32mBraiiiiiiinnnzzzZ...\033[0m" << std::endl;
}






