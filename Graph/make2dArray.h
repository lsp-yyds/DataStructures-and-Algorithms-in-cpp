//
// Created by bruce on 10/17/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MAKE2DARRAY_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MAKE2DARRAY_H

template <class T>
void make2dArray(T **&arr, int numberOfRaws, int numberOfColumns) {
    arr = new T *[numberOfRaws];

    for (int i = 0; i < numberOfColumns; ++i) {
        arr[i] = new T[numberOfColumns];
    }
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MAKE2DARRAY_H
