#include "Fixed.hpp"

const int Fixed::fraction = 8;

// constructors::

Fixed::Fixed(int n){
    fixed = n << fraction;
}

Fixed::Fixed(float n){
    fixed = roundf(n * (1 << fraction));
}

Fixed::Fixed(const Fixed &obj){ 
    fixed = obj.getRawBits();
}

Fixed::Fixed(){
    fixed = 0;
}

//destructor
Fixed::~Fixed(){
}


//copy assignment constructor
Fixed& Fixed::operator=(const Fixed& obj){
    this->fixed = obj.getRawBits();
    return *this;
}

//setter & getter
void Fixed::setRawBits(int i){
    fixed = i;
}
 
int Fixed::getRawBits(void) const {
    return fixed;
}

//to int and to float functions
int Fixed::toInt(void) const{
    return (fixed >> fraction);
}

float Fixed::toFloat(void) const{
    return ((float)fixed / (1 << fraction));
}


//insertion operator overlaoding
std::ostream& operator<<(std::ostream& out, const Fixed& obj){ 
    out << obj.toFloat();
    return out; 
}


//comparison operators overloading
bool Fixed::operator<(const Fixed& obj){
    if (fixed < obj.fixed)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& obj){
    if (fixed <= obj.fixed)
        return true;
    return false;    
}

bool Fixed::operator>(const Fixed& obj){
    if (fixed > obj.fixed)
        return true;
    return false;    
}

bool Fixed::operator>=(const Fixed& obj){
    if (fixed >= obj.fixed)
        return true;
    return false;    
}

bool Fixed::operator==(const Fixed& obj){
    if (fixed == obj.fixed)
        return true;
    return false;    
}

bool Fixed::operator!=(const Fixed& obj){
    if (fixed != obj.fixed)
        return true;
    return false;    
}


//arithmetic operators overloading
Fixed Fixed::operator*(const Fixed& obj){
    Fixed new_obj;
    new_obj.fixed = (fixed * obj.fixed) >> fraction;
    return new_obj;
}

Fixed Fixed::operator/(const Fixed& obj){
    Fixed new_obj;
    new_obj.fixed = (fixed / obj.fixed) << fraction;
    return new_obj;
}

Fixed Fixed::operator+(const Fixed& obj){
    Fixed new_obj;
    new_obj.fixed = fixed + obj.fixed;
    return new_obj;
}

Fixed Fixed::operator-(const Fixed& obj){
    Fixed new_obj;
    new_obj.fixed = fixed - obj.fixed;
    return new_obj;
}

//min & max functions
Fixed& Fixed::min(Fixed& f1, Fixed& f2){
    if (f1.fixed < f2.fixed)
        return f1;
    return f2;
} 

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2){
    if (f1.fixed < f2.fixed)
        return f1;
    return f2; 
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2){
    if (f1.fixed > f2.fixed)
        return f1;
    return f2;
} 

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2){
    if (f1.fixed > f2.fixed)
        return f1;
    return f2; 
}

//increament and decreament operator
//post
Fixed Fixed::operator++(int){
    Fixed temp(*this);
    fixed++;
    return temp;
}

Fixed Fixed::operator--(int){
    Fixed temp(*this);
    fixed--;
    return temp;
}

//pre
Fixed& Fixed::operator++(){
    fixed++;
    return *this;
}

Fixed& Fixed::operator--(){
    fixed--;
    return *this;
}