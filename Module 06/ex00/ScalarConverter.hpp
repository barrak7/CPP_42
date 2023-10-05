#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cstdlib> 
class ScalarConverter{
    static double convert_literal(std::string literal, int &v);
    static void print_char(std::string literal, double c, int v);
    static void print_int(std::string literal, double c, int v);
    static void print_float(std::string literal, double c, int v);
    static void print_double(std::string literal, double c, int v);
    static int followed_by_zero(std::string literal);
    public: 
        ScalarConverter();
        ScalarConverter(ScalarConverter& obj);
        ScalarConverter& operator=(ScalarConverter& obj);
        ~ScalarConverter();
        static void convert(std::string literal);
};

#endif