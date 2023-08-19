#include "Sed.hpp"

void remove_str(std::string &string, int start, int len){
    string = string.substr(0, start) + string.substr(start + len);
}

void replace(char **argv){
    std::ofstream   outfile((argv[1] + std::string(".replace")).c_str());
    std::ifstream   infile(argv[1]);
    std::string     line;
    size_t          pos;
    int             len;

    if (!infile.is_open()){
        std::cout << "Error: Couldn't open input file!\n";
        std::exit(1);
    }
    if (!outfile.is_open()){
        std::cout << "Error: Couldn't open output file!\n";
        std::exit(1);
    }

    len = std::strlen(argv[2]);
    while (!infile.eof()){
        std::getline(infile, line);
        int i = 0;
        pos = 0;
        while (len && (pos = line.find(argv[2], i)) != std::string::npos){
            remove_str(line, pos, len);
            line.insert(pos, argv[3]);
            i += pos + len;
        }
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();
}