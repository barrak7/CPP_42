#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <limits>
#include <algorithm>


void    read_data(std::map<std::string, float> &m);
int     valid_date(std::string str);
int     valid_amount(std::string str, std::string line); 
void    get_value(std::map<std::string, float> &m, std::string file);
void    print_value(std::string date, std::string amount, std::map<std::string, float> &m);
void    str_sep(std::string &str, std::string *arr, char s);