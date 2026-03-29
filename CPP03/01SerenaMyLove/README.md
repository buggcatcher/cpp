### Exercise 01: Serena, my love!

**Turn-in directory:** `ex01/`  
**Files to turn in:** Files from previous exercise + `ScavTrap.{h,hpp}`, `ScavTrap.cpp`  
**Forbidden functions:** None

#### Objective
Create a derived robot class named `ScavTrap` that inherits from `ClapTrap`.

#### Requirements
- `ScavTrap` must inherit from `ClapTrap`.
- It reuses `ClapTrap` attributes (update `ClapTrap` accordingly) and initializes them to:
  - `name` (passed as a constructor parameter)
  - `hitPoints` = `100`
  - `energyPoints` = `50`
  - `attackDamage` = `20`
- Constructors, destructor, and `attack()` must print messages different from `ClapTrap`.
- Proper construction/destruction chaining must be visible in tests:
  - On creation, `ClapTrap` is constructed first, then `ScavTrap`.
  - On destruction, order is reversed.
- Add the special member function:

```cpp
void guardGate();
```

- `guardGate()` must display that `ScavTrap` is now in Gate keeper mode.

#### Testing
Add and submit additional tests to validate inheritance behavior, chaining order, and `ScavTrap`-specific behavior.
