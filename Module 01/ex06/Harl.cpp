#include "Harl.hpp"

void Harl::debug(void){
    std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info(void){
    std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void){
    std::cout << "[WARINING]\nthink I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void){
    std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level){
    int             i;
    void            (Harl::*p[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string     levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (i = 0; i < 4; i++){
        if (level == levels[i])
            break ;
    }
    switch (i){
        case 0:
            (this->*p[0])();
            // fallthrough
        case 1:
            (this->*p[1])();
            // fallthrough
        case 2:
            (this->*p[2])();
            // fallthrough
        case 3:
            (this->*p[3])();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}