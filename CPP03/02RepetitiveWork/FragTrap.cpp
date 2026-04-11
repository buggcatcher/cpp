#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap assignment operator called\n";
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name
		<< " requests a positive high five!\n";
}
