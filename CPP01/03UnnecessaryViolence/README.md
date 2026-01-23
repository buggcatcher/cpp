### Exercise 03: Unnecessary violence

**Turn-in directory:** `ex03/`  
**Files to turn in:** `Makefile`, `main.cpp`, `Weapon.{h,hpp}`, `Weapon.cpp`, `HumanA.{h,hpp}`, `HumanA.cpp`, `HumanB.{h,hpp}`, `HumanB.cpp`  
**Forbidden functions:** None

#### Objective
Implement classes to explore the use of references and pointers in C++.

#### Requirements
- Implement a `Weapon` class:
  - Private attribute: `type` (string)
  - `getType()`: returns a constant reference to `type`
  - `setType()`: sets `type` to a new value
- Implement two classes: `HumanA` and `HumanB`:
  - Both have a name and a weapon
  - Both have an `attack()` function that prints: `<name> attacks with their <weapon type>`
  - `HumanA` takes a `Weapon` in its constructor and is always armed
  - `HumanB` may not always have a weapon and sets it via a setter
- If implemented correctly, the following code will print two attacks for each human, reflecting weapon type changes:

```cpp
int main() {
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
```
- Check for memory leaks.

#### Reflection
When is it best to use a pointer to `Weapon`? And a reference to `Weapon`? Consider this before starting the exercise.

---