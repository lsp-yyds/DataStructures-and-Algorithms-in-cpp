//
// Created by bruce on 10/20/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_HEAPSORT_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_HEAPSORT_H

#include "../PriorityQueue/maxHeap.h"

template <class T>
void heapSort(T arr[], int n) {
    maxHeap<T> maxheap = maxHeap<T>(n);
    maxheap.initialize(arr, n);

    for (int i = n; i > 0; i--) {
        arr[i] = maxheap.pop();
    }
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_HEAPSORT_H
