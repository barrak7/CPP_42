#include "Span.hpp"

int main()
{
    std::vector<int> tmp; 
    tmp.push_back(0);
    tmp.push_back(26); 
    tmp.push_back(18);
    tmp.push_back(10);
    tmp.push_back(2);
    Span sp(10);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(tmp.begin(), tmp.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}