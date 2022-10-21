//
// Created by bruce on 10/20/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_BUBBLESORT_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_BUBBLESORT_H

#include <iostream>

/**
 * 冒泡排序
 * 算法稳定性:稳定
 * 最好时间复杂度:O(n)
 * 最坏时间复杂度:O(n^2)
 * 平均时间复杂度:O(n^2)
 */
template <class T>
void bubble(T a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1])
            std::swap(a[i], a[i + 1]);
    }
}

template <class T>
void bubbleSort(T arr[], int n) {
    for (int i = n; i > 1; i--) {
        bubble(arr, i);
    }
}

template <class T>
bool bubbleImproved(T a[], int n) {
    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1]) {
            std::swap(a[i], a[i + 1]);
            swapped = true;
        }
    return swapped;
}

template <class T>
void bubbleSortImproved(T a[], int n) {

    for (int i = n; i > 1 && bubbleImproved(a, i); i--) {}
}

template <class T>
void bubbleInverse(T a[], int n) {
    for (int i = n - 1; i > 0; i--) {
        if (a[i] < a[i - 1])
            std::swap(a[i - 1], a[i]);
    }
}

//    template <class T>
//    void bubbleSortInverse(T arr[], int n) {
//        for (int i = 0; i < ; ++i) {}
//    }

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_BUBBLESORT_H
