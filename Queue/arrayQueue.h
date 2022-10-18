//
// Created by bruce on 7/14/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ARRAYQUEUE_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ARRAYQUEUE_H

#include "../myExceptions.h"
#include "queue.h"
#include <sstream>

template <class T>
class arrayQueue : public queue<T> {
  private:
    int theFont;
    int theBack;
    int arrayLength;
    T *queue;

  public:
    arrayQueue(int initialCapacity = 10);
    ~arrayQueue() {
        delete[] queue;
    }
    bool empty() const {
        return theFont == theBack;
    }
    int size() const {
        return (theBack - theFont + arrayLength) % arrayLength;
    }
    T &font() {
        if (theFont == theBack)
            throw queueEmpty();
        return queue[ (theFont + 1) % arrayLength ];
    }
    T &back() {
        if (theFont == theBack)
            throw queueEmpty();
        return queue[ theBack ];
    }
    void pop() {
        if (theFont == theBack)
            throw queueEmpty();
        theFont = (theFont + 1) % arrayLength;
        queue[ theFont ].~T();
    }
    void push(const T &theElement);
};

template <class T>
arrayQueue<T>::arrayQueue(int initialCapacity) {
    if (initialCapacity < 1) {
        std::ostringstream s;
        s << "Initial capacity" << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    queue = new T[ arrayLength ];
    theFont = 0;
    theBack = 0;
}

template <class T>
void arrayQueue<T>::push(const T &theElement) {
    if ((theBack + 1) % arrayLength == theFont) {
        T *newQueue = new T[ 2 * arrayLength ];

        int start = (theFont + 1) % arrayLength;
        if (start < 2) {
            std::copy(queue + start, queue + start + arrayLength - 1, newQueue);
        } else {
            std::copy(queue + start, queue + arrayLength, newQueue);
            std::copy(queue, queue + theBack + 1,
                      newQueue + arrayLength - start);
        }

        theFont = 2 * arrayLength - 1;
        theBack = arrayLength - 2;
        arrayLength *= 2;
        queue = newQueue;
    }

    theBack = (theBack + 1) % arrayLength;
    queue[ theBack ] = theElement;
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ARRAYQUEUE_H
