//
// Created by bruce on 7/15/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_HELPERS_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_HELPERS_H

#include "myExceptions.h"
#include <cassert>
#include <ctime>
#include <iostream>
#include <string>

//改变一个数组长度
namespace helpers {
    template <class T>
    void changeLength1D(T *&a, int oldLength, int newLength) {
        if (newLength < 0)
            throw illegalParameterValue("new length must be >= 0");

        //新数组
        T *temp = new T[newLength];
        //需要复制的元素个数
        int number = std::min(oldLength, newLength);
        std::copy(a, a + number, temp);
        //释放老数组的内存
        delete[] a;
        a = temp;
    }

    template <class T>
    void changeArrayIndex0to1(T *&a, int length) {
        int newLength = length + 1;
        T *temp = new T[newLength];

        for (int i = 0; i < length; i++)
            temp[i + 1] = a[i];

        delete[] a;
        a = temp;
    }

    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;

        return arr;
    }

    int *generateNearlyOrderedArray(int n, int swapTimes) {
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = i;

        srand(time(NULL));
        for (int i = 0; i < swapTimes; i++) {
            int posx = rand() % n;
            int posy = rand() % n;
            std::swap(arr[posx], arr[posy]);
        }

        return arr;
    }

    template <class T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }

    template <class T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;

        return true;
    }

    template <class T>
    void testSort(std::string sortName, void (*sort)(T[], int), T arr[],
                  int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        assert(isSorted(arr, n));
        std::cout << sortName << " : "
                  << double(endTime - startTime) / CLOCKS_PER_SEC << "s"
                  << std::endl;
    }

    int *copyIntArray(int a[], int n) {
        int *arr = new int[n];
        std::copy(a, a + n, arr);
        return arr;
    }
} // namespace helpers

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_HELPERS_H
