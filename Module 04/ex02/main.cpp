#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    Animal *arr[] = {
        new Cat(),
        new Cat("test"),
        new Dog(),
        new Dog("random"),
        new Cat("extra_cat"),
        new Dog("More_dog")
    };
    for (int i = 0; i < 6; i++)
        delete arr[i];
    return 0;
}