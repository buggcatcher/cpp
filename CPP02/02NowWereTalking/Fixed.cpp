
#include "Fixed.hpp"

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

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return this->a;
}

void Fixed::setRawBits(int const raw) {
    this->a = raw;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->a = other.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->a > other.a;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->a < other.a;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->a >= other.a;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->a <= other.a;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->a == other.a;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->a != other.a;
}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;

    result.setRawBits(this->a + other.a);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;

    result.setRawBits(this->a - other.a);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    long raw;

    raw = static_cast<long>(this->a) * static_cast<long>(other.a);
    result.setRawBits(static_cast<int>(raw >> this->b));
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    long raw;

    raw = (static_cast<long>(this->a) << this->b) / other.a;
    result.setRawBits(static_cast<int>(raw));
    return result;
}

Fixed &Fixed::operator++() {
    ++this->a;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);

    ++this->a;
    return tmp;
}

Fixed &Fixed::operator--() {
    --this->a;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);

    --this->a;
    return tmp;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->a) / (1 << this->b);
}

int Fixed::toInt(void) const {
    return this->a >> this->b;
}

Fixed &Fixed::min(Fixed &first, Fixed &second) {
    if (first.a < second.a)
        return first;
    return second;
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second) {
    if (first.a < second.a)
        return first;
    return second;
}

Fixed &Fixed::max(Fixed &first, Fixed &second) {
    if (first.a > second.a)
        return first;
    return second;
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second) {
    if (first.a > second.a)
        return first;
    return second;
}

std::ostream &operator<<(std::ostream &o, const Fixed &input) {
    o << input.toFloat();
    return o;
}