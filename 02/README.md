
## Exercise 02: The Job Of Your Dreams

- **Turn-in directory**: `02/`
- **Files to turn in**: 
  - `Makefile`
  - `Account.cpp`
  - `Account.hpp`
  - `tests.cpp`
- **Forbidden functions**: None

## Overview

Welcome to GlobalBanksters United! Your first day on the job as a dev team member has arrived. After impressing the recruiter with your quick Adobe Reader installation skills and acing the recruitment tests, you're ready to tackle your first task.

## The Task

Your manager has assigned you to **recreate a lost file**. Unfortunately, a critical source file was accidentally deleted by your colleagues (who apparently don't know Git and use USB keys to share code). 

### What You Have

- `Account.hpp` - The header file (saved!)
- `tests.cpp` - Test file to validate your implementation
- A log file showing the expected output

### What You Need to Do

By analyzing the header file `Account.hpp`, the test file `tests.cpp`, and the log file, you must reconstruct the missing `Account.cpp` file. The implementation should:

1. Define all member functions declared in `Account.hpp`
2. Properly initialize member variables
3. Implement constructors and destructors
4. Match the expected behavior shown in the log file

## Important Notes

⚠️ **Destructor Order**: The order in which destructors are called may differ depending on your compiler/operating system. Therefore, your destructors may be called in reverse order compared to other implementations. This is normal and expected.

## Building and Testing

Compile the project using the provided `Makefile`:

```bash
make
```

Run the tests to verify your implementation matches the expected output from the log file.

## C++ Concepts

This exercise covers:
- Namespaces
- Classes and member functions
- Stdio streams
- Initialization lists
- Static members
- Const qualifiers
- And other fundamental C++ features

---

Good luck! You've got this! 🚀
