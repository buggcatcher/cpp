#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap a("Magikarp");
	ScavTrap b("Plusle");
	FragTrap c("Minun");

    std::cout << "\nMagikarp used Splash.\n";
	a.attack("Plusle");

	std::cout << "\nMinun used Thunder Punch.\n";
	c.attack("Magikarp");
	std::cout << "It's super effective!\n";
	a.takeDamage(30);

	std::cout << "\nMinun used Helping Hand.\n";
	c.highFivesGuys();
	std::cout << std::endl;

	FragTrap e(c);
	FragTrap d("Charmander");
	d = c;
	std::cout << std::endl;

	return 0;
}
