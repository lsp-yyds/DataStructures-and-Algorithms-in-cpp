//
// Created by bruce on 10/18/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SORT_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SORT_H

#include <algorithm>

namespace sort {
    template <class T>
    void insertionSort(T arr[], int n) {
        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
                std::swap(arr[j - 1], arr[j]);
        }
    }

    template <class T>
    void insertionSortImproved(T arr[], int n) {
        for (int i = 1; i < n; i++) {

            T e = arr[i];
            int j;
            for (j = i; j > 0 && arr[j - 1] > e; j--) {
                arr[j] = arr[j - 1];
            }
            arr[j] = e;
        }
    }
} // namespace sort

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SORT_H
