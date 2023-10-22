#include "PmergeMe.hpp"

int int_len(int n){
    int i = 0;

    if (!n)
        return 1;
    while (n){
        n /= 10;
        i++;
    }
    return i;
}

std::vector<int> str_pars(std::string str){
    std::string      tmp;
    std::vector<int> vec;
    size_t           i = 0;
    int              tmp_len;
    int              re;

    for (;i < str.length(); i++){
        while(str[i] == ' ')
            i++;
        while (str[i] != ' ' && str[i] != '\0')
            tmp.push_back(str[i++]);
        tmp_len = tmp.length();
        if (tmp[0] == '+')
            tmp_len--;
        re = atoi(tmp.c_str());
        if (int_len(re) != tmp_len){
            std::cout << "Error: Invalid integer " << tmp << std::endl;
            exit(1);
        }
        vec.push_back(re);
        tmp.clear();
    }
    return vec;
}

std::vector<int> insertSort(std::vector<int> left, std::vector<int> right){
    std::vector<int>            re;
    std::vector<int>::iterator  li = left.begin();
    std::vector<int>::iterator  ri = right.begin();

    while (li != left.end() && ri != right.end()){
        if (*li < *ri){
            re.push_back(*li);
            li++;
        }
        else{
            re.push_back(*ri);
            ri++;
        }
    }
    for (;li != left.end(); li++)
        re.push_back(*li);
    for (;ri != right.end(); ri++)
        re.push_back(*ri);
    return re;
}

std::vector<int> mergSort(std::vector<int> vec){
    if (vec.size() <= 1)
        return vec;

    std::vector<int> right = mergSort(std::vector<int>(vec.begin(), vec.begin() + vec.size() / 2));
    std::vector<int> left = mergSort(std::vector<int>(vec.begin()+ vec.size() / 2, vec.end()));

    return insertSort(left, right);
}

void PmergeMe_vec(std::string numbers){
    std::vector<int> vec = str_pars(numbers);

    vec = mergSort(vec);
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;
}