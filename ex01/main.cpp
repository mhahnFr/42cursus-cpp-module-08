//
// Created by Manuel Hahn on 6/1/22.
//

#include <iostream>
#include "Span.h"

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl << std::endl;
    {
        std::cout << "Own tests: " << std::endl;
        Span sp = Span(1000000);
        for (int i = 0; i < 1000000; ++i) {
            sp.addNumber(rand() % 1000000);
        }
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl << std::endl;
    }
    // ---            C++11         ---
//    Span s = {1, 2, 3, 4};
//    for (auto item : s.getVec()) {
//        std::cout << item << std::endl;
//    }
    // ---            -----         ---
    Span span = Span(10);
    std::vector<int>::iterator it = span.begin();
    span.insert(it, 5, 22);
    std::vector<int>::iterator middle = span.begin() + 5;
    span.insert(middle, 5, 2);
    it = span.begin() - 1;
    try {
        span.insert(it, -42);
    } catch (std::out_of_range & ex) {
        std::cerr << ex.what() << std::endl;
    }
    for (unsigned long i = 0; i < span.getN(); ++i) {
        std::cout << span.getVec()[i] << std::endl;
    }
    std::cout << std::endl << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl << std::endl;
    return 0;
}
