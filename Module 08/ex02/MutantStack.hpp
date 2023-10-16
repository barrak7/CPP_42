#pragma once

#include <deque>
#include <stack>
#include <iostream> 

template <typename T, typename container = std::deque<T> >
class MutantStack: public std::stack<T, container>{
    public:
        typedef typename container::iterator iterator;
        iterator begin(){
            return this->c.begin();
        }
        iterator end(){
            return this->c.end();
        }
};