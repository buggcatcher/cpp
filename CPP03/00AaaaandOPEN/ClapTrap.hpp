#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <iostream>
# include <string>

// le istanze di ClapTrap non devono interagire tra loro

class	ClapTrap {
	std::string	name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;
public:
	ClapTrap(const std::string& name);
	// non può eseguire azioni quando è esausto (hp o ep)
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap(void);
	void attack(const std::string& target);
	// fa perdere tot <attak_damage> ai hp del <target>
	// consuma un pe
	void takeDamage(unsigned int amount);
	// subisce <amount> danni
	void beRepaired(unsigned int amount);
	// ripristina <amount> hp
	// consuma un pe
};

#endif