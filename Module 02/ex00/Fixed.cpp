#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed(Fixed &obj){
    std::cout << "Copy constrctor called\n";
    fixed = obj.getRawBits();
}

Fixed::Fixed(){
    std::cout << "Default constructor called\n";
    fixed = 0;
}

Fixed& Fixed::operator=(Fixed& obj){
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

int Fixed::getRawBits(void){
    std::cout << "getRawBits member function called\n";
    return fixed;
}