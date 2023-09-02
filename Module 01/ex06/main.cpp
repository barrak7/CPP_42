#include "Harl.hpp"

int main(int argc, char **argv){
    if (argc != 2){
        std::cout << "Invalid number of arguments!" << std::endl;
        return (1);
    }
    Harl obj;

    obj.complain(argv[1]);
    return (0);
}