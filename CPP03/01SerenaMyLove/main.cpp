#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap a("Magikarp");
	ScavTrap b("Geodude");


    std::cout << "\nMagikarp used Splash.\n";
	a.attack("Geodude");

    std::cout << "\nGeodude used Tackle.\n";
	a.takeDamage(3);

	std::cout << "\nMagikarp used Confusion.\n" << "Geodude is confused.\n" << "Geodude hit itself by its confusion!\n";
	b.takeDamage(10);

	std::cout << "\nGeodude used Protect.\n";
	b.guardGate();

    std::cout << "\nMagikarp used Recover.\n";
	a.beRepaired(2);

	std::cout << "\nGeodude used Tackle.\n";
	a.takeDamage(3);
	std::cout << std::endl;

	ScavTrap c(b);
    std::cout << "\nGeodude used Low Kick.\n";
	c.attack("Magikarp");
	a.takeDamage(20);
	std::cout << std::endl;

	return 0;
}
