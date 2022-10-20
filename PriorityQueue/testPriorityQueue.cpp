//
// Created by bruce on 10/20/22.
//

#include "../helpers.h"
#include "maxHeap.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    int *arr = new int[8];
    arr[0] = 53;
    arr[1] = 17;
    arr[2] = 78;
    arr[3] = 9;
    arr[4] = 45;
    arr[5] = 65;
    arr[6] = 87;
    arr[7] = 32;

    helpers::changeArrayIndex0to1(arr, 8);
    maxHeap<int> heap = maxHeap<int>(8);
    heap.initialize(arr, 8);
    std::cout << heap << std::endl;
    // heap.testPrint();
    return 0;
}