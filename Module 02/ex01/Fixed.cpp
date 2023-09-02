#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed(const int n){
    std::cout << "Int constructor called\n";
    fixed = n * (1 << fraction);
}

Fixed::Fixed(const float n){
    std::cout << "Float constructor called\n";
    fixed = roundf(n * (1 << fraction)); 
}

Fixed::Fixed(const Fixed &obj){
    std::cout << "Copy constrctor called\n";
    fixed = obj.getRawBits();
}

Fixed::Fixed(){
    std::cout << "Default constructor called\n";
    fixed = 0;
}

Fixed& Fixed::operator=(const Fixed& obj){
    std::cout << "Copy assignment operator called\n";
    this->fixed = obj.getRawBits();
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called\n";
}

void Fixed::setRawBits(int i){
    fixed = i;
}
 
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return fixed;
}

int Fixed::toInt(void) const{
    return (fixed / (1 << fraction));
}

float Fixed::toFloat(void) const{
    return ((float)fixed / (1 << fraction));
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj){ 
    out << obj.toFloat();
    return out; 
}