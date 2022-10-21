//
// Created by bruce on 10/20/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SECTIONSORT_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SECTIONSORT_H

#include <iostream>

/**
 * 选择排序
 * 算法稳定性:不稳定
 * 平均时间复杂度:O(n^2)
 */
template <class T>
void sectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        if (min != i)
            std::swap(arr[i], arr[min]);
    }
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SECTIONSORT_H
