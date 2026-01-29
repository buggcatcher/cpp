#include <string>
#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        void announce(void);
        Zombie(const std::string& name);
        ~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);