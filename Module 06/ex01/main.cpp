#include "Serializer.hpp"

int main(){
    Data *ptr = new Data;
    ptr->c = 'h';
    ptr->d = 1337;
    ptr->t = 42;
    ptr->s = "test";
    uintptr_t raw = Serializer::serialize(ptr);
    ptr = Serializer::deserialize(raw + 4);
    std::cout << ptr->d << std::endl;
    ptr = Serializer::deserialize(raw);
    std::cout << ptr->d << std::endl;
    return 0;
}