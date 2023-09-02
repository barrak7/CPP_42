#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>
 

class Fixed{
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed &obj);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

    private:
        int fixed;
        static const int fraction;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif