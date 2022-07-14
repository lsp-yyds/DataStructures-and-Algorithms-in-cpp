//
// Created by bruce on 7/14/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ARRAYQUEUE_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ARRAYQUEUE_H

#include "Queue.h"

template <class T>
class arrayQueue : public queue<T> {
  private:
    int theFont;
    int theBack;
    int arrayLength;
    T *queue;

  public:
    arrayQueue( int initialCapacity = 10 );
    ~arrayQueue() {
        delete[] queue;
    }
    bool empty() const {
        return theBack - theFont == 0;
    }
    int size() const {
        return theBack - theFont;
    }
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ARRAYQUEUE_H
