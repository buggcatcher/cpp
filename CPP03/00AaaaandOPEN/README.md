### Exercise 00: Aaaaand... OPEN!

**Turn-in directory:** `ex00/`  
**Files to turn in:** `Makefile`, `main.cpp`, `ClapTrap.{h,hpp}`, `ClapTrap.cpp`  
**Forbidden functions:** None

#### Objective
Implement your first class in Module 03: `ClapTrap`.

#### Requirements
- Create a `ClapTrap` class with the following private attributes:
  - `name` (passed as a constructor parameter)
  - `hitPoints` initialized to `10`
  - `energyPoints` initialized to `10`
  - `attackDamage` initialized to `0`
- Add the following public member functions:
  - `void attack(const std::string& target);`
  - `void takeDamage(unsigned int amount);`
  - `void beRepaired(unsigned int amount);`
- Behavior rules:
  - `attack()` makes the target lose `<attack damage>` hit points.
  - `beRepaired()` restores `<amount>` hit points.
  - Attacking and repairing each consume `1` energy point.
  - A `ClapTrap` can’t do anything if it has no hit points or no energy points left.
  - `ClapTrap` instances do not directly interact with one another in this exercise.

#### Output Expectations
- Every member function must print a message describing what happens.
- Example attack message format:

```text
ClapTrap <name> attacks <target>, causing <damage> points of damage!
```

- Constructors and destructor must also print messages so evaluators can confirm calls.

#### Testing
Implement and submit your own tests to verify that all behaviors work as expected.
