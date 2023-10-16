#include "easyfind.hpp"
#include <vector>

int main(){
    std::vector<int> t;
    t.push_back(10);
    t.push_back(50);
    t.push_back(44);
    t.push_back(3);
    t.push_back(2);
    easyfind(t, 2);
}