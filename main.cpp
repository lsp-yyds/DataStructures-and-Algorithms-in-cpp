#include "Sort/sort.h"
#include "helpers.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    int n = 1000;
    int *arr1 = helpers::generateRandomArray(n, 0, n);
    int *arr2 = helpers::copyIntArray(arr1, n);

    helpers::testSort("InsertionSort", sort::insertionSort, arr1, n);
    helpers::testSort("InsertionSortImproved", sort::insertionSortImproved,
                      arr2, n);
    return 0;
}