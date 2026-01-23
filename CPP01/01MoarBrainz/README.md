### Exercise 01: Moar brainz!

**Turn-in directory:** `ex01/`  
**Files to turn in:** `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `zombieHorde.cpp`  
**Forbidden functions:** None

#### Objective
Create a horde of Zombies using dynamic allocation.

#### Requirements
- Implement the function: `Zombie* zombieHorde(int N, std::string name);`
  - Allocates `N` Zombie objects in a single allocation.
  - Initializes each zombie with the given name.
  - Returns a pointer to the first zombie.
- Write your own tests to ensure `zombieHorde()` works as expected.
  - Call `announce()` for each zombie in the horde.
- Use `delete[]` to deallocate all zombies and check for memory leaks.

---