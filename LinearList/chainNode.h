//
// Created by bruce on 10/22/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_CHAINNODE_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_CHAINNODE_H

template <class T>
struct chainNode {
    //数据成员
    T element;
    chainNode<T> *next;

    //方法
    chainNode() {
    }
    chainNode(const T &element) {
        this->element = element;
    }
    chainNode(const T &element, chainNode<T> *next) {
        this->element = element;
        this->next = next;
    }
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_CHAINNODE_H
