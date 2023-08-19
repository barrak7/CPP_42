# include "Sed.hpp"

int main(int c, char **argv){
    if (c != 4){
        std::cout << "Invalid number of arguments!\n";
        return 1;
    }
    replace(argv);
    return (0);
}