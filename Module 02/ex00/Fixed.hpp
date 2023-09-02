#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed{
    public:
        Fixed();
        Fixed(Fixed &obj);
        ~Fixed();
        Fixed& operator=(Fixed& other);
        int getRawBits(void);
        void setRawBits(int const raw);

    private:
        int fixed;
        static const int fraction;
};

#endif