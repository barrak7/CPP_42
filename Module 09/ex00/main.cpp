#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
    std::map<std::string, float> m;

    if (argc != 2){
        std::cout << "Error: coult not open file." << std::endl;
        exit(1);
    }
    read_data(m);
    get_value(m, argv[1]);
    return 0;
}