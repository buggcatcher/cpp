### Exercise 04: Sed is for losers

**Turn-in directory:** `ex04/`  
**Files to turn in:** `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}`  
**Forbidden functions:** `std::string::replace`

#### Objective
Replace all occurrences of a string in a file and write the result to a new file.

#### Requirements
- The program takes three parameters: a filename, `s1`, and `s2`.
- Open `<filename>` and copy its content into `<filename>.replace`, replacing every occurrence of `s1` with `s2`.
- Do not use C file manipulation functions.
- All member functions of `std::string` are allowed except `replace`.
- Handle unexpected inputs and errors.
- Create and turn in your own tests to ensure your program works as expected.

---