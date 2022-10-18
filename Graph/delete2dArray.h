//
// Created by bruce on 10/17/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_DELETE2DARRAY_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_DELETE2DARRAY_H

template <class T>
void delete2dArray(T **&theArray, int numberOfRows) {
    for (int i = 0; i < numberOfRows; i++)
        delete[] theArray[i];

    delete[] theArray;
    theArray = 0;
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_DELETE2DARRAY_H
