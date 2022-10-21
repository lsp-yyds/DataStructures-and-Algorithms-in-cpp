//
// Created by bruce on 10/20/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_QUICKSORT_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_QUICKSORT_H

/**
 * 快速排序
 * 算法稳定性:不稳定
 * 最好时间复杂度:O(nlogn)
 * 最坏时间复杂度:O(n^2)
 * 平均时间复杂度:O(nlogn)
 */
template <class T>
int partition(T arr[], int l, int r) {
    T temp = arr[l];
    while (l < r) {
        while (l < r && arr[r] >= temp)
            r--;
        arr[l] = arr[r];
        while (l < r && arr[l] <= temp)
            l++;
        arr[r] = arr[l];
    }
    arr[l] = temp;
    return l;
}

template <class T>
void quickSortPartition(T arr[], int l, int r) {
    if (l < r) {
        int p = partition(arr, l, r);
        quickSortPartition(arr, l, p - 1);
        quickSortPartition(arr, p + 1, r);
    }
}

template <class T>
void quickSort(T arr[], int n) {
    quickSortPartition(arr, 0, n - 1);
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_QUICKSORT_H
