### Exercise 00: BraiiiiiiinnnzzzZ

**Turn-in directory:** `ex00/`  
**Files to turn in:** `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`  
**Forbidden functions:** None

#### Objective
Implement a `Zombie` class with a private string attribute `name` and a member function `void announce(void);` that prints:

```
<name>: BraiiiiiiinnnzzzZ...
```
(Do not print the angle brackets. For a zombie named Foo: `Foo: BraiiiiiiinnnzzzZ...`)

#### Requirements
- Implement the function: `Zombie* newZombie(std::string name);`
  - Creates a zombie, names it, and returns it (heap allocation).
- Implement the function: `void randomChump(std::string name);`
  - Creates a zombie, names it, and makes it announce itself (stack allocation).
- Zombies must be destroyed when no longer needed.
- The destructor must print a message with the zombie's name for debugging.

#### Note
Decide when to allocate zombies on the stack vs. the heap.

---