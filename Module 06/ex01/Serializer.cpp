#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(Serializer& obj){
    std::cout << "Copy constructor copied from: " << &obj << std::endl;
}

Serializer& Serializer::operator=(Serializer& obj){
    std::cout << "Assignment from: " << &obj << std::endl;
    return *this; 
}

Serializer::~Serializer(){};

uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}