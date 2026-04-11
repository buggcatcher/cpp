#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <iostream>
# include <string>

// le istanze di ClapTrap non devono interagire tra loro

class	ClapTrap {
protected:
	std::string	name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;
public:
	ClapTrap(const std::string& name);			// non può eseguire azioni quando è esausto (HP o EP)
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap(void);
	virtual void attack(const std::string& target);		// fa perdere <attak_damage> ai HP del <target> e consuma un EP
	void takeDamage(unsigned int amount);		// subisce <amount> danni
	void beRepaired(unsigned int amount);		// ripristina <amount> HP e consuma un EP
};

#endif