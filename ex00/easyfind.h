//
// Created by Manuel Hahn on 6/1/22.
//

#ifndef EX00_EASYFIND_H
#define EX00_EASYFIND_H

#include <algorithm>

template<typename T>
typename T::const_iterator easyfind(const T & container, int s) throw(std::invalid_argument) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), s);
    if (it == container.end()) throw std::invalid_argument(std::to_string(s) + ": not found!");
    return it;
}

#endif //EX00_EASYFIND_H
