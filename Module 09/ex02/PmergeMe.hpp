#include <vector>
#include <iostream>
#include <list>
#include <ctime>
#include <string.h>

void PmergeMe_vec(char** numbers);
void PmergeMe_list(char** numbers);
int  int_len(int n);

template <typename T>
void str_pars(char** strs, T& container){
    size_t           i = 0;
    int              tmp_len;
    int              re;

    while(strs[i]){
        tmp_len = std::strlen(strs[i]);
        if (strs[i][0] == '+')
            tmp_len--; 
        re = atoi((const char *)(strs[i]));
        if (int_len(re) != tmp_len){
            std::cout << "Error: Invalid integer " << strs[i] << std::endl;
            exit(1);
        }
        container.push_back(re);
        i++;
    }
}