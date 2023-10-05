#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data {
    int         d;
    int         t;
    std::string s;
    char        c;
};

class Serializer{
    Serializer();
    Serializer(Serializer &obj);
    ~Serializer();
    Serializer& operator=(Serializer& obj);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data*     deserialize(uintptr_t raw);
};


#endif