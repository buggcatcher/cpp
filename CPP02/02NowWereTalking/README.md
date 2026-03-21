### Exercise: 02
# Now we’re talking

**Turn-in directory:** `ex02/`  
**Files to turn in:** `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`  
**Authorized functions:** `roundf` (from `<cmath>`)

#### Objective
Add full operator support to your fixed-point class and expose utility `min`/`max` helpers.

#### Requirements
- Keep everything from exercises 00 and 01.
- Overload public member operators:
  - Comparison: `>`, `<`, `>=`, `<=`, `==`, `!=`
  - Arithmetic: `+`, `-`, `*`, `/`
  - Increment/decrement: pre/post `++`, pre/post `--`
- Increment/decrement must modify the value by the smallest representable epsilon (`ϵ`) such that `1 + ϵ > 1`.
- Add static overloads:
  - `min(Fixed&, Fixed&)`
  - `min(Fixed const&, Fixed const&)`
  - `max(Fixed&, Fixed&)`
  - `max(Fixed const&, Fixed const&)`
- Test every feature of the class.

---

Add public member functions to your class to overload the following operators:
- The 6 comparison operators: `>`, `<`, `>=`, `<=`, `==`, and `!=`.
- The 4 arithmetic operators: `+`, `-`, `*`, and `/`.
- The 4 increment/decrement operators (pre-increment, post-increment, pre-decrement, post-decrement), which increase or decrease the fixed-point value by the smallest representable `ϵ`, such that `1 + ϵ > 1`.

Add these four public overloaded member functions to your class:
- A static member function `min` that takes two references to fixed-point numbers as parameters, and returns a reference to the smallest one.
- A static member function `min` that takes two references to constant fixed-point numbers as parameters, and returns a reference to the smallest one.
- A static member function `max` that takes two references to fixed-point numbers as parameters, and returns a reference to the greatest one.
- A static member function `max` that takes two references to constant fixed-point numbers as parameters, and returns a reference to the greatest one.

It’s up to you to test every feature of your class. However, running the code below:

```cpp
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}
```

Should output something like (for greater readability, constructor/destructor messages are removed in the example below):

```bash
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
```

If you ever do a division by 0, it is acceptable that the program crashes.
