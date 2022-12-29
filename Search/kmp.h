//
// Created by bruce on 10/22/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_KMP_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_KMP_H

#include <iostream>

int patternMatch(std::string str, std::string s) {
    int i = 0, j = 0;
    while (i <= str.length() && j <= str.length()) {
        if (str[i] == s[j]) {
            ++i, ++j;
        } else {
            i = i - j + 2;
            j = 0;
        }
    }
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_KMP_H
