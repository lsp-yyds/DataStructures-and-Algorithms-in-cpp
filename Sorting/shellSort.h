//
// Created by bruce on 10/20/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SHELLSORT_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SHELLSORT_H

/**
 * 希尔排序(仅适用于顺序表)[每次处理不同的子表]
 * 算法稳定性:不稳定
 * 最坏时间复杂度:O(n^2)
 */
template <class T>
void shellSort(T arr[], int n) {
    T temp;
    int d, i, j;
    for (d = n / 2; d > 0; d = d / 2) {
        for (i = d; i < n; i++) {
            if (arr[i] < arr[i - d]) {
                temp = arr[i];
                for (j = i - d; j >= 0 && arr[j] > temp; j -= d)
                    arr[j + d] = arr[j];
                arr[j + d] = temp;
            }
        }
    }
}

/**
 * 希尔排序(仅适用于顺序表)[每次处理相同的子表]
 * 算法稳定性:不稳定
 * 最坏时间复杂度:O(n^2)
 */
template <typename T>
void shellSortKnuth(T arr[], int n) {

    //计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    int h = 1;
    while (h < n / 3)
        h = 3 * h + 1;

    while (h >= 1) {
        for (int i = h; i < n; i++) {

            // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]...
            // 使用插入排序
            T e = arr[i];
            int j;
            for (j = i; j >= h && e < arr[j - h]; j -= h)
                arr[j] = arr[j - h];
            arr[j] = e;
        }

        h /= 3;
    }
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SHELLSORT_H
