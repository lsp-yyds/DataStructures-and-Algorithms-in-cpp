//
// Created by bruce on 7/10/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_LINEARLIST_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_LINEARLIST_H

#include <iostream>

template <class T>
class linearList {
  public:
    virtual ~linearList(){};
    //返回true，当且仅当线性表为空
    virtual bool empty() const = 0;
    //返回线性表的元素个数
    virtual int size() const = 0;
    //返回索引为theIndex的元素
    virtual T &get(int theIndex) const = 0;
    //返回元素theElement第一次出现时的索引
    virtual int indexOf(const T &theElement) const = 0;
    //删除索引为theIndex的元素
    virtual void erase(int theIndex) = 0;
    //把theElement插入线性表中索引为theIndex的位置上
    virtual void insert(int theIndex, const T &theElement) = 0;
    //把线性表插入输出流out
    virtual void output(std::ostream &out) const = 0;
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_LINEARLIST_H
