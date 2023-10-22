#include "BitcoinExchange.hpp"

void str_sep(std::string &str, std::string arr[3], char s){
    int                   i  = 0;
    std::string::iterator it = str.begin();

    for (; i < 3; i++)
        arr[i].clear();
    i = 0;
    for (;it != str.end(); it++){
        if (i == 3)
            break ;
        if (*it == s)
            i++;
        else
            arr[i].push_back(*it);
    }
    if (i > 2)
        arr[1].clear();
}

int valid_day(int y, int m, int d){
    if (m != 2 && (m == 4 || m == 6 || m == 9 || m == 11) && (d > 30 || d == 0))
        return 0;
    if (m != 2 && d > 31)
        return 0;
    if (m == 2){
        if (d == 0)
            return 0;
        if (!(y % 4)){
            if (!(y % 100) && (y % 400) && d > 28)
                return 0;
            if (d > 29)
                return 0;
        }
        if (d > 28)
            return 0;
    }
    return 1;
}

int valid_date(std::string str){
    int         i       = 0;
    int         len     = str.length() - 1;
    int         month;
    int         day;
    std::string arr[3];

    if (len != 10)
        return 0;
    for (;i != len; i++){
        if ((i < 4 || (i > 4 && i < 7) || i > 7) && !std::isdigit(str[i])){
            return 0;
        }
        else if (!std::isdigit(str[i]) && str[i] != '-'){
            return 0;
        }
    }
    if (str[len] != ' ')
        return 0;
    str_sep(str, arr, '-');
    i = atoi(arr[0].c_str());
    month = atoi(arr[1].c_str());
    day = atoi(arr[2].c_str());    
    if (month > 12 || month == 0)
        return 0;
    if (!valid_day(i, month, day))
        return 0;
    if (i < 2009 || (i == 2009 && atoi(arr[2].c_str()) < 2))
        return 0;
    return 1; 
}

int valid_amount(std::string str, std::string line){
    char    *p;
    float   re = std::strtof(str.c_str(), &p);

    if (*p || str[0] != ' '){
        std::cout << "Error: bad input => " << line << std::endl;
        return 0;
    } 
    if (re < 0){
        std::cout << "Error: not a positive number." << std::endl;
        return 0;
    }    
    if ((long)re > std::numeric_limits<int>::max()){
        std::cout << "Error: too large a number." << std::endl;
        return 0;
    }
    return 1;
}

void print_value(std::string date, std::string amount, std::map<std::string, float> &m){
    std::map<std::string, float>::iterator it = m.upper_bound(date);

    it--;
    std::cout << date << " => " << std::strtof(amount.c_str(), NULL) << " = " << std::strtof(amount.c_str(), NULL) * it->second << std::endl;
}

void read_data(std::map<std::string, float> &m){
    std::ifstream   file("data.csv");
    std::string     line;
    std::string     arr[3];

    if (!file.is_open()){
        std::cout << "Error: could not open data file." << std::endl;
        exit(1);
    }
    std::getline(file, line);
    while (std::getline(file, line)){
        str_sep(line, arr, ',');
        m[arr[0]] =  std::strtof(arr[1].c_str(), NULL);
    }
    file.close();
}

void get_value(std::map<std::string, float> &m, std::string name){
    std::ifstream   f(name);    
    std::string     line;
    std::string     arr[3];
    int             i = 1;

    if (!f.is_open()){
        std::cout << "Error: could not open data file." << std::endl;
        exit(1);
    }
    std::getline(f, line);
    if (line != "date | value"){
        std::cout << "Error: invalid header => " << line <<std::endl;
        exit(1); 
    }
    while (std::getline(f, line)){
        str_sep(line, arr, '|');
        if (arr[0].empty() && arr[1].empty() && arr[2].empty()){
            std::cout << "Error: line " << i << " is empty." << std::endl;
            i++;
            continue ;
        }
        if (arr[0].empty() || arr[1].empty() || !arr[2].empty()){
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }
        if (!valid_date(arr[0])){
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }        
        arr[0].resize(arr[0].size() - 1);
        if (!valid_amount(arr[1], line))
            continue ;
        print_value(arr[0], arr[1], m);
        i++;
    }
}
