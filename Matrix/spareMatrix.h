//
// Created by bruce on 7/13/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SPAREMATRIX_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SPAREMATRIX_H

template <class T>
struct matrixTerm {
    int row, col;
    T value;

    operator T() const {
        return value;
    }
};

template <class T>
class spareMatrix {
    // TODO
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_SPAREMATRIX_H
