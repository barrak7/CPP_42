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

std::vector<int> insertSort(std::vector<int> left, std::vector<int> right){
    std::vector<int>::iterator  ri = right.begin();

    for (;ri != right.end(); ri++) 
        left.insert(std::upper_bound(left.begin(), left.end(), *ri), *ri);

    left.insert(left.end(), ri, right.end());
    return left;
}

std::vector<int> mergSort(std::vector<int> vec){
    if (vec.size() <= 1)
        return vec;

    std::vector<int> right = mergSort(std::vector<int>(vec.begin(), vec.begin() + vec.size() / 2));
    std::vector<int> left = mergSort(std::vector<int>(vec.begin()+ vec.size() / 2, vec.end()));

    return insertSort(left, right);
}

void PmergeMe_vec(char **numbers){
    std::vector<int> vec;
    std::clock_t   start, end;

    str_pars(numbers, vec);
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    start = std::clock(); 
    vec = mergSort(vec);    
    end = std::clock();
    std::cout << "After: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";    
    std::cout << std::endl; 
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << 1000000.0 * (end - start) /  CLOCKS_PER_SEC << " us"<<std::endl;
}

std::list<int> insertSort(std::list<int> left, std::list<int> right){
    std::list<int>::iterator  ri = right.begin();

    for (;ri != right.end(); ri++)  
        left.insert(std::upper_bound(left.begin(), left.end(), *ri), *ri);

    left.insert(left.end(), ri, right.end());
    return left;
}

std::list<int> mergSort(std::list<int> list){
    if (list.size() <= 1)
        return list;

    std::list<int> right = mergSort(std::list<int>(list.begin(), std::next(list.begin(), list.size() / 2)));
    std::list<int> left = mergSort(std::list<int>(std::next(list.begin(), list.size() / 2), list.end()));

    return insertSort(left, right);
}

void PmergeMe_list(char **numbers){
    std::list<int> list;
    std::clock_t   start, end;
    
    str_pars(numbers, list);
    start = std::clock();
    list = mergSort(list);
    end = std::clock();
    std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << 1000000.0 * (end - start) /  CLOCKS_PER_SEC << " us"<<std::endl;
}