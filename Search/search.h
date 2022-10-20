//
// Created by bruce on 10/18/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SEARCH_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SEARCH_H

namespace search {
    // 线性查找
    template <class T>
    int linearSearch(T arr[], int n, T value) {
        int i = 0;

        while (i < n && arr[i] != value)
            i++;

        return i == n ? -1 : i;
    }

    // 仅适用于数组0号位置为预留位置
    // 逆线性查找
    template <class T>
    int linearSearchInverse(T arr[], int n, T value) {
        arr[0] = value;
        int i = n;

        while (arr[i] != value)
            i--;

        return i;
    }

    // 对于有序数组(升序)的线性查找
    template <class T>
    int linearSearchIsSorted(T arr[], int n, T value) {
        int i = 0;

        while (arr[i] < value && arr[i] != value)
            i++;

        return arr[i] == value ? i : -1;
    }

    // 二分查找
    template <class T>
    int binarySearch(T arr[], int n, T value) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == value)
                return mid;
            else if (arr[mid] > value)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return -1;
    }

    // 对于二分插入排序的二分查找函数
    template <class T>
    int binarySearchForInsertionSort(T arr[], int n, T value) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > value)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return l;
    }

    // 二分查找递归函数
    template <class T>
    int binarySearch(T arr[], int l, int r, T value) {
        if (l > r)
            return -1;

        int mid = l + (r - l) / 2;

        if (arr[mid] == value)
            return mid;
        if (arr[mid] > value)
            return binarySearch(arr, l, mid - 1, value);
        if (arr[mid] < value)
            return binarySearch(arr, mid + 1, r, value);
    }

    // 递归实现的二分查找
    template <class T>
    int binarySearchRecursion(T arr[], int n, T value) {
        return binarySearch(arr, 0, n - 1, value);
    }
} // namespace search

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SEARCH_H
