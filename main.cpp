#include "LinearList/arrayList.h"
#include "Search/search.h"
#include "Sorting/sorting.h"
#include "helpers.h"
#include <iostream>

int main(int argc, char const *argv[]) {

    //    arrayList<int> arr = arrayList<int>(10);
    //    for (int i = 0; i < arr.capacity(); ++i) {
    //        arr.insert(i, i + 1);
    //    }
    //
    int n = 10000;
    // int *arr1 = helpers::generateNearlyOrderedArray(n, 10);
    int *arr1 = helpers::generateRandomArray(n, 0, n);
    int *arr2 = helpers::copyIntArray(arr1, n);
    int *arr3 = helpers::copyIntArray(arr1, n);
    int *arr4 = helpers::copyIntArray(arr1, n);
    int *arr5 = helpers::copyIntArray(arr1, n);
    int *arr6 = helpers::copyIntArray(arr1, n);
    int *arr7 = helpers::copyIntArray(arr1, n);
    int *arr8 = helpers::copyIntArray(arr1, n);
    int *arr9 = helpers::copyIntArray(arr1, n);
    int *arr10 = helpers::copyIntArray(arr1, n);

    helpers::testSort("InsertionSort", sorting::insertionSort, arr1, n);
    helpers::testSort("InsertionSortImproved", sorting::insertionSortImproved,
                      arr2, n);
    helpers::testSort("BinaryInsertionSort", sorting::binaryInsertionSort, arr3,
                      n);
    helpers::testSort("ShellSort", sorting::shellSort, arr4, n);
    helpers::testSort("ShellSortKnuth", sorting::shellSortKnuth, arr5, n);
    helpers::testSort("BubbleSort", sorting::bubbleSort, arr6, n);
    helpers::testSort("BubbleSort2", sorting::bubbleSortImproved, arr7, n);
    helpers::testSort("QuickSort", sorting::quickSort, arr8, n);
    helpers::testSort("SectionSort", sorting::sectionSort, arr9, n);
    helpers::testSort("HeapSort", sorting::heapSort, arr10, n);

    //    int arr[] = {27, 13, 49, 38, 76, 49, 65, 97};
    //    sorting::shellSort(arr, 8);
    //    for (int i = 0; i < 8; ++i) {
    //        std::cout << arr[i] << " ";
    //    }

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;

    return 0;
}