# C++ Modules - Learning Object-Oriented Programming

## Chapter I: Introduction

C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes" (source: Wikipedia).

The goal of these modules is to introduce you to **Object-Oriented Programming**. This will be the starting point of your C++ journey. Many languages are recommended for learning OOP. We decided to choose C++ since it's derived from your old friend C.

Since C++ is a complex language, and in order to keep things simple, your code will follow the **C++98 standard**.

We are aware modern C++ is way different in a lot of aspects. So if you want to become a proficient C++ developer, it's up to you to go further after the 42 Common Core!

You will discover new concepts step-by-step. The exercises will progressively increase in complexity.

---

## Chapter II: General Rules

### Compiling

- Compile your code with `c++` and the flags `-Wall -Wextra -Werror`
- Your code should still compile if you add the flag `-std=c++98`

### Formatting and Naming Conventions

- The exercise directories will be named this way: `ex00`, `ex01`, ... , `exn`
- Name your files, classes, functions, member functions and attributes as required in the guidelines
- **Write class names in UpperCamelCase format.** Files containing class code will always be named according to the class name. For instance: `ClassName.hpp`/`ClassName.h`, `ClassName.cpp`, or `ClassName.tpp`. Then, if you have a header file containing the definition of a class "BrickWall" standing for a brick wall, its name will be `BrickWall.hpp`
- Unless specified otherwise, every output message must end with a newline character and be displayed to the standard output
- **Goodbye Norminette!** No coding style is enforced in the C++ modules. You can follow your favorite one. But keep in mind that code your peer evaluators can't understand is code they can't grade. Do your best to write clean and readable code

### Allowed/Forbidden

Time to C++! Therefore:

- You are allowed to use almost everything from the standard library. Thus, instead of sticking to what you already know, it would be smart to use the C++-ish versions of the C functions you are used to as much as possible
- However, **you can't use any other external library.** It means C++11 (and derived forms) and Boost libraries are **forbidden**. The following functions are **forbidden** too: `*printf()`, `*alloc()` and `free()`. If you use them, your grade will be **0** and that's it

---


**Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff**

### Module-Specific Rules

- Note that unless explicitly stated otherwise, the `using namespace <ns_name>` and `friend` keywords are **forbidden**. Otherwise, your grade will be **-42**
- You are allowed to use the STL only in **Modules 08 and 09**. That means: no Containers (`vector`/`list`/`map`, and so forth) and no Algorithms (anything that requires including the `<algorithm>` header) until then. Otherwise, your grade will be **-42**

### Design Requirements

- **Memory leakage occurs in C++ too.** When you allocate memory (by using the `new` keyword), you must avoid memory leaks
- From **Module 02 to Module 09**, your classes must be designed in the **Orthodox Canonical Form**, except when explicitly stated otherwise
- **Any function implementation put in a header file (except for function templates) means 0 to the exercise**
- **You should be able to use each of your headers independently from others.** Thus, they must include all the dependencies they need. However, you must avoid the problem of double inclusion by adding include guards. Otherwise, your grade will be **0**

### Important Notes

- You can add some additional files if you need to (i.e., to split your code). As these assignments are not verified by a program, feel free to do so as long as you turn in the mandatory files
- Sometimes, the guidelines of an exercise look short but the examples can show requirements that are not explicitly written in the instructions
- **Read each module completely before starting! Really, do it**
- **By Odin, by Thor! Use your brain!!!**

### Makefile

Regarding the Makefile for C++ projects, the same rules as in C apply (see the Norm chapter about the Makefile).

> You will have to implement a lot of classes. This can seem tedious, unless you're able to script your favorite text editor.

---

### Final Reminder

You are given a certain amount of freedom to complete the exercises. However, follow the mandatory rules and don't be lazy. You would miss a lot of useful information! Do not hesitate to read about theoretical concepts.
