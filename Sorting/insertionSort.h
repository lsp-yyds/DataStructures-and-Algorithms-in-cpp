//
// Created by bruce on 10/20/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_INSERTIONSORT_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_INSERTIONSORT_H

#include <iostream>

/**
 * 插入排序
 * 算法稳定性:稳定
 * 最好时间复杂度(全部有序):O(n)
 * 最坏时间复杂度(全部逆序):O(n^2)
 * 平均时间复杂度:O(n^2)
 */
template <class T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
            std::swap(arr[j - 1], arr[j]);
    }
}

/**
 * 优化后的插入排序(优化了交换所带来的时间损耗)
 * 算法稳定性:稳定
 * 平均时间复杂度:O(n^2)
 */
template <class T>
void insertionSortImproved(T arr[], int n) {
    for (int i = 1; i < n; i++) {

        T temp = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > temp; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_INSERTIONSORT_H
