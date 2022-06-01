//
// Created by Manuel Hahn on 6/1/22.
//

//#include <array>
#include <vector>
#include <list>
#include <iostream>
#include "easyfind.h"

int main() {
/*
 * The following code uses the std::array, which has been added in C++11. It still works with the flag -std=c++98 on macOS.
 */
//    std::array<int, 5> v = {5, 8, 9, 6};
//    try {
//        std::array<int, 5>::const_iterator it = easyfind(v, 7);
//        std::cout << "Result: " << *it << std::endl;
//    } catch (std::invalid_argument & ex) {
//        std::cerr << ex.what() << std::endl;
//    }
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(77);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(11);
    vec.push_back(1);
    try {
        std::vector<int>::const_iterator it = easyfind(vec, 7);
        std::cout << "Result: " << *it << std::endl;
    } catch (std::invalid_argument & ex) {
        std::cerr << ex.what() << std::endl;
    }
    std::list<int> l;
    l.push_back(5);
    l.push_back(4);
    l.push_back(7);
    l.push_back(3);
    l.push_back(2);
    l.push_back(11);
    l.push_back(1);
    try {
        std::list<int>::const_iterator it = easyfind(l, 7);
        std::cout << "Result: " << *it << std::endl;
    } catch (std::invalid_argument & ex) {
        std::cerr << ex.what() << std::endl;
    }
}
