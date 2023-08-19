#include "Harl.hpp"

void Harl::debug(void){
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info(void){
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void){
    std::cout << "WARINING: think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void){
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level){
    int             i = 0;
    void            (Harl::*p[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    const char      *levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (i = 0; i < 4; i++){
        if (level == levels[i]){
            (this->*p[i])();
            break ;
        }
    }
    if (i == 4)
        std::cout << "Error: " << level << " is not a vlid level!!\n";
}