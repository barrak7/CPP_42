#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed{
    public:
        //constructors
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed &obj);

        //operator overloading
        Fixed& operator=(const Fixed& other);
        bool    operator>(const Fixed& obj) const;
        bool    operator<(const Fixed& obj) const;
        bool    operator>=(const Fixed& obj) const;
        bool    operator<=(const Fixed& obj) const;
        bool    operator==(const Fixed& obj) const;
        bool    operator!=(const Fixed& obj) const;
        Fixed   operator+(const Fixed& obj) const;
        Fixed   operator-(const Fixed& obj) const;
        Fixed   operator*(const Fixed& obj) const;
        Fixed   operator/(const Fixed& obj) const;

        //destructor
        ~Fixed();

        //getters
        int getRawBits(void) const;
        float toFloat(void) const;
        int toInt(void) const;
        
        //setters
        void setRawBits(int const raw);

        //min & max
        static const Fixed& min(const Fixed& f1, const Fixed& f2);
        static const Fixed& max(const Fixed& f1, const Fixed& f2);
        
        //increament & decremenet operators
        //post:
        Fixed operator++(int);
        Fixed operator--(int);
        //pre
        Fixed& operator++();
        Fixed& operator--();

    private:
        int fixed;
        static const int fraction;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
