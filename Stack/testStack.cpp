//
// Created by bruce on 7/14/22.
//

#include "arrayStack.h"
#include "bracketCheck.h"
#include "derivedArrayStack.h"
#include "linkedStack.h"

int main() {

    std::string s = "((())(())";

    if (!bracketCheck(s, (int) s.length()))
        printf("Brackets do not match!!!");
    else
        printf("haha");

    return 0;
}
