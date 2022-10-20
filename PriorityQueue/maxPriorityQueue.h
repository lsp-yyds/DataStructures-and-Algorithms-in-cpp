//
// Created by bruce on 10/20/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MAXPRIORITYQUEUE_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MAXPRIORITYQUEUE_H

template <class T>
class maxPriorityQueue {
  public:
    virtual ~maxPriorityQueue() {
    }
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual const T &top() = 0;
    virtual void pop() = 0;
    virtual void push(const T &theElement) = 0;
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MAXPRIORITYQUEUE_H
