//
// Created by bruce on 7/14/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_LINKEDSTACK_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_LINKEDSTACK_H

#include "MyExceptions.h"
#include "Stack.h"
#include <iostream>

template <class T>
struct chainNode {
    //数据成员
    T element;
    chainNode<T> *next;

    //方法
    chainNode() {
    }
    chainNode( const T &element ) {
        this->element = element;
    }
    chainNode( const T &element, chainNode<T> *next ) {
        this->element = element;
        this->next = next;
    }
};

template <class T>
class linkedStack : public stack<T> {
  private:
    //栈顶指针
    chainNode<T> *stackTop;
    //栈中元素个数
    int stackSize;

  public:
    linkedStack( int initialCapacity = 10 ) {
        stackTop = NULL;
        stackSize = 0;
    }
    ~linkedStack();
    bool empty() const {
        return stackSize == 0;
    }
    int size() const {
        return stackSize;
    }
    T &top() {
        if ( stackSize == 0 )
            throw stackEmpty();
        return stackTop->element;
    }
    void pop();
    void push( const T &theElement ) {
        stackTop = new chainNode<T>( theElement, stackTop );
        stackSize++;
    }
};

template <class T>
linkedStack<T>::~linkedStack<T>() {
    //析构函数
    while ( stackTop != NULL ) {
        //删除栈顶节点
        chainNode<T> *nextNode = stackTop->next;
        delete stackTop;
        stackTop = nextNode;
    }
}

template <class T>
void linkedStack<T>::pop() {
    //删除栈顶节点
    if ( stackSize == 0 )
        throw stackEmpty();

    chainNode<T> *nextNode = stackTop->next;
    delete stackTop;
    stackTop = nextNode;
    stackSize--;
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_LINKEDSTACK_H
