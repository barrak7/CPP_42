#include "Span.hpp"

Span::Span(){
    N = 0;
}

Span::Span(int n): N(n){}

Span::Span(Span& obj){
    N = obj.N;
}

Span& Span::operator=(Span& obj){
    N = obj.N;
    return *this;
}

int obs(int n){
    return std::abs(n);
}

void Span::addNumber(int n){
    if (arr.size() == N)
        throw std::exception();
    if (arr.size() == 1)
        shortSpan = std::abs(n - arr[0]);
    if (arr.size() > 1){
        std::vector<int> re(arr.size());
        std::vector<int> scal(arr.size());
        std::fill(scal.begin(), scal.end(), n);
        std::transform(arr.begin(), arr.end(), scal.begin(), re.begin(), std::minus<int>());
        std::vector<int> tmp(arr.size());
        std::transform(re.begin(), re.end(), tmp.begin(), obs);
        unsigned int tmp2 = *(std::min_element(tmp.begin(), tmp.end()));
        if (tmp2 < shortSpan)
            shortSpan = tmp2;
    }
    arr.push_back(n);
}

unsigned int Span::shortestSpan(){
    if (arr.size() < 2)
        throw std::exception();
    return shortSpan;
}

unsigned int Span::longestSpan(){
    if (arr.size() < 2)
        throw std::exception();
    return *(std::max_element(arr.begin(), arr.end())) - *(std::min_element(arr.begin(), arr.end()));
}