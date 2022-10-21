//
// Created by bruce on 10/20/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_BINARYINSERTIONSORT_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_BINARYINSERTIONSORT_H

#include "../Search/search.h"

/**
 * 二分插入排序(优化了元素比较的时间损耗)
 * 算法稳定性:稳定
 * 平均时间复杂度:O(n^2)
 */
template <class T>
void binaryInsertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {

        T temp = arr[i];
        int l = search::binarySearchForInsertionSort(arr, i, arr[i]);
        for (int j = i; j - l > 0; j--)
            arr[j] = arr[j - 1];
        arr[l] = temp;
    }
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_BINARYINSERTIONSORT_H
