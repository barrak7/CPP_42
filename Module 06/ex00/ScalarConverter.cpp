#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter &obj){
    std::cout << "Copied " << &obj<<std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& obj){
    std::cout << "Copied " << &obj<<std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

double ScalarConverter::convert_literal(std::string literal, int &v){
    if (literal.length() == 1){
        if (literal[0] >= '0' && literal[0] <= '9')
            return static_cast<double>(std::atoi(literal.c_str()));
        return static_cast<double>(literal[0]);
    }
    char *p;
    double r = strtod(literal.c_str(), &p);
    if (*p != '\0' && std::string("f") != p)
        v = 1;
    return r;
} 

void ScalarConverter::print_char(std::string literal, double c, int v){
    if (v || c > std::numeric_limits<char>::max() \
    || c < std::numeric_limits<char>::min() || literal == "nan" || literal == "nanf")
        std::cout << "char: impossible" << std::endl;
    else{
        if (c > 126 || c < 32){
            std::cout << "char: Non displayable" << std::endl;
        }
        else
            std::cout << "char: " << static_cast<char>(c)<<std::endl;
    }
}

void ScalarConverter::print_int(std::string literal, double c, int v){
    if (v || c > std::numeric_limits<int>::max() \
    || c < std::numeric_limits<int>::min() || literal == "nan" || literal == "nanf")
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(c) << std::endl;
}

int ScalarConverter::followed_by_zero(std::string literal){
    for (size_t i = 0; i < literal.length(); i++){
        if (literal[i] != '0') 
            return 0;
    }
    return 1;
}

void ScalarConverter::print_float(std::string literal, double c, int v){
    if (v || ((c > std::numeric_limits<float>::max() \
    || c < -std::numeric_limits<float>::max()) && literal \
    != "-inff" && literal != "+inff" && literal != "inff"\
    && literal != "-inf" && literal != "+inf" && literal != "inf")){
        std::cout << "float: impossible" << std::endl;
    }   
    else{
        std::cout << "float: " << static_cast<double>(c);
        for (size_t i = 0; i <= literal.length(); i++){
            if ((literal[i] == '.' && (literal[i+1] == 'f' || literal[i+1] == '\0' \
            || followed_by_zero(std::string(&(literal.c_str())[i + 1])))) || literal[i] == '\0'){
                std::cout << ".0f" << std::endl; 
                break ;
            }
            else if (literal[i] == '.'){
                std::cout << "f"<< std::endl;
                break ;
            }
        }
    }
}



void ScalarConverter::print_double(std::string literal, double c, int v){
    if (v || (literal != "-inff" && literal != "+inff" && literal != "inff"\
    && literal != "-inf" && literal != "+inf" && literal != "inf" && (c == 1.0/0.0 || c==-1.0/0.0)))
        std::cout << "double: impossible" << std::endl;
    else{
        std::cout << "double: " << static_cast<double>(c);
        for (size_t i = 0; i <= literal.length(); i++){
            if ((literal[i] == '.' && (literal[i+1] == 'f' || literal[i+1] == '\0' \
            || followed_by_zero(std::string(&(literal.c_str())[i + 1])))) || literal[i] == '\0'){
                std::cout << ".0" << std::endl; 
                break ;
            }
            else if (literal[i] == '.'){
                std::cout << std::endl;
                break ;
            }
        }
    }
}

void ScalarConverter::convert(std::string literal){
    int v = 0;
    double c = convert_literal(literal, v);
    print_char(literal, c, v);
    print_int(literal, c, v);
    print_float(literal, c, v);
    print_double(literal, c, v);
}