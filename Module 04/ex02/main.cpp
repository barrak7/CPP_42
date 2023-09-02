#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    Animal *arr[] = {
        new Cat(),
        new Cat("test"),
        new Dog(),
        new Dog("random")
    };
    for (int i = 0; i < 4; i++)
        delete arr[i];
    return 0;
}