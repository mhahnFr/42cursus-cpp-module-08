//
// Created by Manuel Hahn on 6/1/22.
//

#ifndef EX01_SPAN_H
#define EX01_SPAN_H


#include <vector>
//#include <initializer_list>                   // <-- C++11

class Span {
public:
    Span();
    Span(const Span &);
//    Span(std::initializer_list<int>);          // <-- C++11
    explicit Span(int n);
    ~Span();

    void addNumber(int) throw(std::range_error);
    unsigned int getN() const;

    void insert(std::vector<int>::iterator &pos, int count, int value);
    void insert(std::vector<int>::iterator &pos, int value);
//    void insert(std::vector<int>::const_iterator &pos, std::initializer_list elements); // <-- C++11
    std::vector<int>::iterator begin() const;
    std::vector<int>::iterator end() const;
    const std::vector<int> &getVec() const;
    unsigned int getStored() const;
    int shortestSpan() const;
    int longestSpan() const;

    Span & operator=(const Span &);

private:
    mutable std::vector<int> vec;
    unsigned int stored;
    unsigned int n;
};


#endif //EX01_SPAN_H
