### Exercise 06: Harl filter

**Turn-in directory:** `ex06/`  
**Files to turn in:** `Makefile`, `main.cpp`, `Harl.{h,hpp}`, `Harl.cpp`  
**Forbidden functions:** None

#### Objective
Filter Harl's messages based on log levels using a switch statement.

#### Requirements
- Create a program that takes one of four log levels as a parameter.
- Display all messages from the given level and above.
- If the parameter does not match a level, print:
  - `[ Probably complaining about insignificant problems ]`
- Name the executable `harlFilter`.
- You must use the `switch` statement in your implementation.

#### Example
```bash
$> ./harlFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
Ive been coming for years, whereas you started working here just last month.
[ ERROR ]
This is unacceptable! I want to speak to the manager now.
$> ./harlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
```

---