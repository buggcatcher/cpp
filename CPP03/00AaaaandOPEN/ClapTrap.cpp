#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& input)
{
    *this = input;
    std::cout << "Copy constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& input)
{
    if (this != &input) {
        name = input.name;
        hitPoints = input.hitPoints;
        energyPoints = input.energyPoints;
        attackDamage = input.attackDamage;
    }
    std::cout << "Assignment operator called\n";
    return *this;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints == 0) {
        std::cout << name << " can't attack: no hit points left!\n";
        return;
    }
    if (energyPoints == 0) {
        std::cout << name << " can't attack: no energy points left!\n";
        return;
    }
    --energyPoints;
    std::cout << name << " attacks " << target  << ", causing " << attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0) {
        std::cout << name << " is already destroyed!\n";
        return;
    }
    if (amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;
    std::cout << name << " takes " << amount << " points of damage! (HP: " << hitPoints << ")\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0) {
        std::cout << name << " can't repair: no hit points left!\n";
        return;
    }
    if (energyPoints == 0) {
        std::cout << name << " can't repair: no energy points left!\n";
        return;
    }
    --energyPoints;
    hitPoints += amount;
    std::cout << name << " repairs itself for " << amount  << " hit points! (HP: " << hitPoints << ")\n";
}