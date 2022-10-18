//
// Created by bruce on 10/17/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_EDGE_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_EDGE_H

template <class T>
class edge {
  public:
    virtual ~edge();
    virtual int vertex1() const = 0;
    virtual int vertex2() const = 0;
    virtual T weight() const = 0;
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_EDGE_H
