//
// Created by Manuel Hahn on 6/2/22.
//

#include <string>
#include <iostream>
#include "MutantStack.h"
#include <stack>

void print(const std::string &str) {
    std::cout << str << std::endl;
}

std::string stringer;

void toString(const char &c) {
    stringer += c;
}

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl << "Own tests:" << std::endl;
    {
        MutantStack<std::string> stack = MutantStack<std::string>();
        stack.push("aaaaa");
        stack.push("bbbbb");
        stack.push("ccccc");
        std::for_each(stack.begin(), stack.end(), print);
    }
    {
        MutantStack<char> stack = MutantStack<char>();
        stack.push('H');
        stack.push('e');
        stack.push('l');
        stack.push('l');
        stack.push('o');
        stack.push('!');
        stack.push('\n');
        stack.push('\0');
        std::for_each(stack.begin(), stack.end(), toString);
        std::cout << stringer << std::endl;
    }
    return 0;
}
