### Exercise 02: Repetitive work

**Turn-in directory:** `ex02/`  
**Files to turn in:** Files from previous exercises + `FragTrap.{h,hpp}`, `FragTrap.cpp`  
**Forbidden functions:** None

#### Objective
Implement a `FragTrap` class that inherits from `ClapTrap`, similarly to `ScavTrap`.

#### Requirements
- `FragTrap` must inherit from `ClapTrap`.
- Construction/destruction messages must be specific to `FragTrap` and different from other classes.
- Proper construction/destruction chaining must be shown in tests:
  - On creation, `ClapTrap` is constructed first.
  - On destruction, order is reversed.
- Initialize inherited attributes with these values:
  - `name` (passed as a constructor parameter)
  - `hitPoints` = `100`
  - `energyPoints` = `100`
  - `attackDamage` = `30`
- Add the special member function:

```cpp
void highFivesGuys(void);
```

- `highFivesGuys()` must print a positive high-fives request to standard output.

#### Testing
Add and submit more tests to validate `FragTrap` behavior and inheritance chain correctness.
