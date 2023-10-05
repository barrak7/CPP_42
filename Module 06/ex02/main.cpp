#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

Base* generate(void){
    std::srand(time(0)); 
    int c = std::rand() % 3;
    switch (c){
        case 0:
            return new A();
            break ;
        case 1:
            return new B();
            break ;
        default:
            return new C(); 
    }
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "This is an instance of: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "This is an instance of: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "This is an instance of: C" << std::endl;
    else
        std::cout << "This is an instance of: unkown" << std::endl;
}

void identify(Base& p){
    try {
        dynamic_cast<A&>(p);
        std::cout << "This is an instance of: A" << std::endl;
        return;
    }
    catch(std::exception& e) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "This is an instance of: B" << std::endl;
            return;
        }
        catch(std::exception& e) {
            try {
                dynamic_cast<C&>(p);
                std::cout << "This is an instance of: C" << std::endl;
                return;
            }
            catch(std::exception& e) {
                std::cout << "This is an instance of: unkown" << std::endl;
            }
        }
    }
}


int main(){
    Base* ptr = generate();
    identify(ptr);
    delete ptr;
    sleep(1);
    ptr = generate();
    identify(ptr);
    delete ptr;
    sleep(1);
    ptr = generate();
    identify(*ptr); 
    delete ptr;
    return 0;
}