#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain Default\n";
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "Default";
}

Brain::Brain(Brain& obj){
    std::cout << "Brain copy\n";
    for (int i = 0; i < 100; i++)
        this->ideas[i] = obj.ideas[i];
}

Brain& Brain::operator=(Brain& obj){
    std::cout << "Brain assignment\n";
    for (int i = 0; i < 100; i++)
        this->ideas[i] = obj.ideas[i];
    return *this; 
}

Brain::~Brain(){
    std::cout << "Brain Destructor\n";
    
}