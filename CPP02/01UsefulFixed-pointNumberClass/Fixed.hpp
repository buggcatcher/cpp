#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    int a;
    static const int b;
public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed(const int input);
    Fixed(const float input);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &input);

#endif