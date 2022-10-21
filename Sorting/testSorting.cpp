//
// Created by bruce on 10/21/22.
//

#include "sorting.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    int *arr = new int[7];
    arr[0] = 49;
    arr[1] = 38;
    arr[2] = 65;
    arr[3] = 97;
    arr[4] = 76;
    arr[5] = 13;
    arr[6] = 27;

    sorting::mergeSort(arr, 7);
    for (int i = 0; i < 7; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
