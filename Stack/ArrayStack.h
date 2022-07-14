//
// Created by bruce on 7/13/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ARRAYSTACK_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ARRAYSTACK_H

#include "MyExceptions.h"
#include "Stack.h"
#include <sstream>

namespace arrayStackHelper {
    template <class T>
    void changeLength1D( T *&a, int oldLength, int newLength ) {
        if ( newLength < 0 )
            throw illegalParameterValue( "new length must be >= 0" );

        //新数组
        T *temp = new T[ newLength ];
        //需要复制的元素个数
        int number = std::min( oldLength, newLength );
        std::copy( a, a + number, temp );
        //释放老数组的内存
        delete[] a;
        a = temp;
    }
} // namespace arrayStackHelper

template <class T>
class arrayStack : public stack<T> {
  private:
    //当前栈顶
    int stackTop;
    //栈容量
    int arrayLength;
    //元素数组
    T *stack;

  public:
    arrayStack( int initialCapacity = 10 );
    ~arrayStack() {
        delete[] stack;
    }
    bool empty() const {
        return stackTop == -1;
    }
    int size() const {
        return stackTop + 1;
    }
    T &top() {
        if ( stackTop == -1 )
            throw stackEmpty();
        return stack[ stackTop ];
    }
    void pop() {
        if ( stackTop == -1 )
            throw stackEmpty();
        stack[ stackTop-- ].~T();
    }
    void push( const T &theElement );
};

template <class T>
arrayStack<T>::arrayStack( int initialCapacity ) {
    //构造函数
    if ( initialCapacity < 1 ) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue( s.str() );
    }
    arrayLength = initialCapacity;
    stack = new T[ arrayLength ];
    stackTop = -1;
}

template <class T>
void arrayStack<T>::push( const T &theElement ) {
    //将元素theElement压入栈
    //空间已满,增加容量
    if ( stackTop == arrayLength - 1 ) {
        arrayStackHelper::changeLength1D( stack, arrayLength, 2 * arrayLength );
        arrayLength *= 2;
    }

    stack[ ++stackTop ] = theElement;
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ARRAYSTACK_H
