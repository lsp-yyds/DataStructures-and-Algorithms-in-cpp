//
// Created by bruce on 10/22/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_BRACKETCHECK_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_BRACKETCHECK_H

#include "arrayStack.h"

bool bracketCheck(const std::string &str, int length) {
    arrayStack<char> s = arrayStack<char>((int) str.length() / 2 + 1);
    for (int i = 0; i < length; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]);
        else {
            if (s.empty())
                return false;

            char top;
            top = s.top();
            s.pop();
            if (str[i] == ')' && top != '(')
                return false;

            if (str[i] == ']' && top != '[')
                return false;

            if (str[i] == '}' && top != '{')
                return false;
        }
    }
    if (!s.empty())
        return false;

    return true;
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_BRACKETCHECK_H
