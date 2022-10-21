//
// Created by bruce on 10/20/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MERGESORT_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MERGESORT_H

#include <cassert>

template <class T>
void merge(T *&arr, int startOfFirst, int endOfFirst, int endOfSecond) {
    assert(startOfFirst < endOfFirst);
    T *tempArray = new T[endOfSecond - startOfFirst + 1];
    for (int i = startOfFirst; i <= endOfSecond; i++)
        tempArray[i - startOfFirst] = arr[i];

    int first = startOfFirst, second = endOfFirst + 1, result = startOfFirst;

    while ((first <= endOfFirst) && (second <= endOfSecond))
        if (tempArray[first] <= tempArray[second])
            arr[result++] = tempArray[first++];
        else
            arr[result++] = tempArray[second++];

    if (first > endOfFirst)
        for (int j = second; j <= endOfSecond; j++)
            arr[result++] = tempArray[j];
    else
        for (int j = 0; j <= endOfFirst; j++)
            arr[result++] = tempArray[j];

    delete[] tempArray;
}

template <class T>
void mergeSort(T arr[], int l, int r) {
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    if (arr[mid] > arr[mid + 1])
        merge(arr, l, mid, r);
}

template <class T>
void mergeSort(T arr[], int n) {
    mergeSort(arr, 0, n - 1);
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MERGESORT_H
