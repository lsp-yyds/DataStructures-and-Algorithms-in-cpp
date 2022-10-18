//
// Created by bruce on 7/14/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_QUEUE_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_QUEUE_H

template <class T>
class queue {
  public:
    virtual ~queue() {
    }
    //返回true,当且仅当队列为空
    virtual bool empty() const = 0;
    //返回队列中元素个数
    virtual int size() const = 0;
    //返回头元素的引用
    virtual T &front() = 0;
    //返回尾元素的引用
    virtual T &back() = 0;
    //删除首元素
    virtual void pop() = 0;
    //把元素theElement加入队尾
    virtual void push(const T &theElement) = 0;
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_QUEUE_H
