#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Magikarp");
	ClapTrap b("Slowpoke");


    std::cout << "Magikarp used Splash.\n";
	a.attack("Slowpoke");

    std::cout << "Slowpoke is confused.\n";
	b.takeDamage(3);

    std::cout << "Magikarp used Recover.\n";
	a.beRepaired(2);

	ClapTrap c(a);
    std::cout << "Magikarp used Splash.\n";
	c.attack("Slowpoke");

	return 0;
}
