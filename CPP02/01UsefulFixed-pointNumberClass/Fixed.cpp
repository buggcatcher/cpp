#include "Fixed.hpp"
#include <cmath>

const int Fixed::b = 8;

Fixed::Fixed() : a(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int input) {
    std::cout << "Int constructor called" << std::endl;
    this->a = input << this->b;
}

Fixed::Fixed(const float input) {
    std::cout << "Float constructor called" << std::endl;
    this->a = static_cast<int>(roundf(input * (1 << this->b)));
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->a = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    return this->a;
}

void Fixed::setRawBits(int const raw) {
    this->a = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->a) / (1 << this->b);
}

int Fixed::toInt(void) const {
    return this->a >> this->b;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Fixed &input) {
    o << input.toFloat();
    return o;
}