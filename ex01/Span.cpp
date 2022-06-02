//
// Created by Manuel Hahn on 6/1/22.
//

#include <stdexcept>
#include <string>
#include "Span.h"

unsigned int Span::getN() const {
    return n;
}

Span::Span(): vec(0), stored(0), n(0) {}

Span::Span(const Span &other): vec(other.getVec()), stored(other.getStored()), n(other.getN()) {}

Span::Span(int n): vec(n), stored(0), n(n) {}

Span::~Span() {}

void Span::addNumber(int i) throw(std::range_error) {
    if (stored == n) {
        throw std::range_error("Cannot add a number: size: " + std::to_string(n)
        + ", element number: " + std::to_string(stored + 1));
    }
    vec[stored++] = i;
}

int Span::shortestSpan() const {
    std::vector<int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());
    int lastDiff = std::numeric_limits<int>::max();
    for (unsigned long i = 0; i < tmp.size(); ++i) {
        if (i + 1 < tmp.size()) {
            int tmpDiff = tmp[i + 1] - tmp[i];
            if (tmpDiff < lastDiff) {
                lastDiff = tmpDiff;
            }
        }
    }
    return lastDiff;
}

int Span::longestSpan() const {
    std::vector<int> tmp = vec;
    std::sort(tmp.begin(), tmp.end());
    return tmp.back() - tmp.front();
}

Span &Span::operator=(const Span &other) {
    if (&other != this) {
        vec = other.getVec();
        stored = other.getStored();
        n = other.getN();
    }
    return *this;
}

const std::vector<int> &Span::getVec() const {
    return vec;
}

unsigned int Span::getStored() const {
    return stored;
}

void Span::insert(std::vector<int>::iterator &pos, int count, int value) {
    if (pos >= end() || pos < begin()) throw std::out_of_range("Position out of range!");
    if (count > end() - pos) {
        throw std::out_of_range("Can't add " + std::to_string(count) +
        " elements from position " + std::to_string(pos - begin()) + " with size " + std::to_string(n) + "!" +
        " (Would need " + std::to_string(pos - begin() + count) + " capacity)");
    }
    for (std::vector<int>::iterator it = pos; it < pos + count; ++it) {
        *it = value;
    }
}

std::vector<int>::iterator Span::begin() const {
    return vec.begin();
}

std::vector<int>::iterator Span::end() const {
    return vec.end();
}

void Span::insert(std::vector<int>::iterator &pos, int value) {
    if (pos >= end() || pos < begin()) throw std::out_of_range("Position out of range!");
    *pos = value;
}

//Span::Span(std::initializer_list<int> lst): vec(lst), stored(lst.size()), n(stored) {} // <-- C++11
