//
// Created by bruce on 10/17/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_VERTEXITERATOR_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_VERTEXITERATOR_H

template <class T>
class vertexIterator {
  public:
    virtual ~vertexIterator();
    virtual int next() = 0;
    virtual int next(T &) = 0;
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_VERTEXITERATOR_H
