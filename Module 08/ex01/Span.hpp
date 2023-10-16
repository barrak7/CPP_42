#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <cstdlib>

class Span{
    unsigned int N;
    std::vector<int> arr;
    unsigned int shortSpan;
    public:
        Span();
        Span(int n);
        Span(Span& obj);
        Span& operator=(Span& obj);
        void addNumber(int n);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        template <typename Iter>
        void addNumber(Iter begin, Iter end){
            if (end < begin)
                throw std::exception();
            if ((unsigned long)(end - begin) > N - arr.size())
                throw std::exception();
            for (;begin != end; begin++)
                addNumber(*begin);
        }
};