//
// Created by bruce on 10/18/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SORT_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SORT_H

#include <algorithm>
#include <cassert>
#include <ctime>

#include "../PriorityQueue/maxHeap.h"
#include "../Search/search.h"

namespace sorting {
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

    /**
     * 优化后的快速排序
     */

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

    template <class T>
    void heapSort(T arr[], int n) {
        maxHeap<T> heap = maxHeap<T>(n);
        for (int i = 0; i < n; i++) {
            heap.push(arr[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            arr[i] = heap.top();
            heap.pop();
        }
    }

    /**
     * 归并排序
     * 算法稳定性:稳定
     * 平均时间复杂度:O(nlogn)
     */
    // 将arr[l...mid]和arr[mid+1...r]两部分进行归并
    template <typename T>
    void merge(T arr[], int startOfFirst, int endOfFirst, int endOfSecond) {

        T temp[endOfSecond - startOfFirst + 1];
        for (int i = startOfFirst; i <= endOfSecond; i++)
            temp[i - startOfFirst] = arr[i];

        int i = startOfFirst, j = endOfFirst + 1;
        for (int k = startOfFirst; k <= endOfSecond; k++) {
            if (i > endOfFirst) {
                arr[k] = temp[j - startOfFirst];
                j++;
            } else if (j > endOfSecond) {
                arr[k] = temp[i - startOfFirst];
                i++;
            } else if (temp[i - startOfFirst] < temp[j - startOfFirst]) {
                arr[k] = temp[i - startOfFirst];
                i++;
            } else {
                arr[k] = temp[j - startOfFirst];
                j++;
            }
        }
    }

    // 递归使用归并排序，对arr[l ... r]的范围进行排序
    template <typename T>
    void mergeSort(T arr[], int l, int r) {

        if (l >= r)
            return;

        int mid = (l + r) / 2; // 当l和r较大时可能会发生溢出错误
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    template <typename T>
    void mergeSort(T arr[], int n) {
        mergeSort(arr, 0, n - 1);
    }
} // namespace sorting

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SORT_H
