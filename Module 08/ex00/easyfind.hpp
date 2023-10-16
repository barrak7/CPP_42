#pragma once

#include <algorithm>
#include <iostream>

template <typename T>
void easyfind(T container, int v){
    typename T::iterator it = std::find(container.begin(), container.end(), v);
    if (it == container.end())
        std::cout << "There is no occurence of " << v << " in the provided container!" << std::endl; 
    else
        std::cout << "First occurrence of " << *it << " is at index " << it - container.begin() << std::endl;
}

