//
// Created by bruce on 7/13/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_STACK_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_STACK_H

template <class T>
class stack {
  public:
    virtual ~stack() {
    }
    //返回true,当且进当栈为空
    virtual bool empty() const = 0;
    //返回栈中的元素个数
    virtual int size() const = 0;
    //返回栈顶元素的引用
    virtual T &top() = 0;
    //删除栈顶元素
    virtual void pop() = 0;
    //将元素theElement压入栈顶
    virtual void push(const T &theElement) = 0;
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_STACK_H
