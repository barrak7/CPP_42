#include "PmergeMe.hpp"

int main(int argc, char **argv){
    if (argc < 2){
        std::cout << "Error: invalid number of arguments." << std::endl;
        exit(1);
    }
    PmergeMe_vec(&argv[1]);
    PmergeMe_list(&argv[1]);
    return 0;
}