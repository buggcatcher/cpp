#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Magikarp");
	ClapTrap b("Gastly");


    std::cout << "Magikarp used Splash.\n";
	a.attack("Gastly");

    std::cout << "Gastly used Curse.\n";
	b.takeDamage(3);

    std::cout << "Magikarp used Recover.\n";
	a.beRepaired(2);

	ClapTrap c(a);
    std::cout << "Magikarp used Splash.\n";
	c.attack("Gastly");

	return 0;
}
