//
// Created by bruce on 7/13/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_DERIVEDARRAYSTACK_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_DERIVEDARRAYSTACK_H

#include "../LinearList/arrayList.h"
#include "../myExceptions.h"
#include "stack.h"

template <class T>
class derivedArrayStack : private arrayList<T>, public stack<T> {
  public:
    derivedArrayStack(int initialCapacity = 10)
        : arrayList<T>(initialCapacity) {
    }
    bool empty() const {
        return arrayList<T>::empty();
    }
    int size() const {
        return arrayList<T>::size();
    }
    T &top() {
        try {
            return arrayList<T>::get(arrayList<T>::size() - 1);
        } catch (illegalIndex) {
            throw stackEmpty();
        }
    }
    void pop() {
        if (arrayList<T>::empty())
            throw stackEmpty();
        arrayList<T>::erase(arrayList<T>::size() - 1);
    }
    void push(const T &theElement) {
        arrayList<T>::insert(arrayList<T>::size(), theElement);
    }
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_DERIVEDARRAYSTACK_H
