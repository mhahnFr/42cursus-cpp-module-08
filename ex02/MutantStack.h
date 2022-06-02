//
// Created by Manuel Hahn on 6/2/22.
//

#ifndef EX02_MUTANTSTACK_H
#define EX02_MUTANTSTACK_H

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::const_iterator iterator;

    MutantStack(): std::stack<T>() {}

    MutantStack(const MutantStack<T> &other): std::stack<T>(other) {}

    ~MutantStack() {}

    MutantStack & operator=(const MutantStack<T> &other) {
        if (&other != this) {
            *this = other;
        }
        return *this;
    }

    iterator begin() const {
        return std::stack<T>::c.begin();
    }

    iterator end() const {
        return std::stack<T>::c.end();
    }
};

#endif //EX02_MUTANTSTACK_H
