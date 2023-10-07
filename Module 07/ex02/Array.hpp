#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
class Array{
    T               *arr;
    unsigned int    n;
    public:
        Array(){
            arr = new T[1];
            n = 1;
            std::cout << "default constructor\n";
        }
        Array(unsigned int n):n(n){
            std::cout << "parametrized constructor\n";
            arr = new T[n];
        }
        Array(Array& obj){
            std::cout << "copy constructor\n";
            n = obj.size();
            arr = new T[n];
            for(size_t i = 0; i < n; i++){
                arr[i] = obj.arr[i];
            }
        }
        Array& operator=(Array& obj){
            std:: cout << "assignment operator\n";
            if (&obj == this)
                return *this;
            delete[] arr;
            n = obj.size();
            arr = new T[n];
            for(size_t i = 0; i < n; i++){
                arr[i] = obj.arr[i];
            }
            return *this;
        }
        unsigned int size(void) const{
            return n;
        }
        T& operator[](int i){
            if (i < 0 || (unsigned int)i >= n)
                throw std::exception();
            return arr[i];
        }
        ~Array(){
            std::cout << "destructor\n";
            delete [] arr;
        }
};

#endif