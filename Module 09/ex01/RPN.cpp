#include "RPN.hpp"

void rpn(std::string in){
    std::string::iterator   it = in.begin();
    std::string::iterator   e  = in.end();    
    std::string             o  = "+-*/";
    std::stack<int>         mystack;
    int                     a;
    int                     b;

    for (;it != e; it++){
        if (!std::isdigit(*it) && o.find(*it) == std::string::npos && *it != ' '){
            std::cout << "Error" << std::endl;
            exit(1);
        }
        else if (std::isdigit(*it)){
            mystack.push((*it) - 48);
        }
        else if (*it == ' ')
            continue ;
        else{
            b = mystack.top();
            mystack.pop();
            a = mystack.top();
            mystack.pop();
            switch (o.find(*it)){
                case 0:
                    mystack.push(a + b);
                    break;
                case 1:
                    mystack.push(a - b);
                    break ;
                case 2:
                    mystack.push(a * b);
                    break ;
                default:
                    if (b == 0){
                        std::cout << "Error: division by zero." << std::endl;
                        exit(1);
                    }
                    mystack.push(a / b);
            }
        }
    }
    if (mystack.size() != 1){
        std::cout << "Error" << std::endl;
        exit(1);
    }
    std::cout << mystack.top() << std::endl;
}