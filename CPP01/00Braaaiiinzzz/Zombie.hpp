#include <string>
#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie(const std::string& name); // costruttore verboso
        void announce(void);
        ~Zombie(); // distruttore verboso
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);