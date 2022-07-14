//
// Created by bruce on 7/10/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ARRAYLIST_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ARRAYLIST_H

#include "LinearList.h"
#include "MyExceptions.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <sstream>

//改变一个数组长度
namespace arrayListHelper {
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
} // namespace arrayListHelper

template <class T>
class arrayList : public linearList<T> {
  protected:
    // public:
    //若索引theIndex无效，则抛出异常
    void checkIndex( int theIndex ) const;
    //存储线性表元素的一维数组
    T *element;
    //一维数组的容量
    int arrayLength;
    //现行表元素个数
    int listSize;

  public:
    //构造函数、复制构造函数和析构函数
    arrayList( int initialCapacity = 10 );
    arrayList( const arrayList<T> & );
    ~arrayList() {
        delete[] element;
    }

    // ADT方法
    bool empty() const {
        return listSize == 0;
    }
    int size() const {
        return listSize;
    }
    T &get( int theIndex ) const;
    int indexOf( const T &theElement ) const;
    void erase( int theIndex );
    void insert( int theIndex, const T &theElement );
    void output( std::ostream &out ) const;

    //其他方法
    int capacity() const {
        return arrayLength;
    }
    void reSet( int );
    void set( int, const T & );
    void clear() {
        listSize = 0;
    }
};

template <class T>
arrayList<T>::arrayList( int initialCapacity ) {
    //构造函数
    if ( initialCapacity < 1 ) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue( s.str() );
    }
    arrayLength = initialCapacity;
    element = new T[ arrayLength ];
    listSize = 0;
}

template <class T>
arrayList<T>::arrayList( const arrayList<T> &theList ) {
    //复制构造函数
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[ arrayLength ];
    std::copy( theList.element, theList.element + listSize, element );
}

template <class T>
void arrayList<T>::checkIndex( int theIndex ) const {
    //确定索引theIndex在0和listSize - 1之间
    if ( theIndex < 0 || theIndex >= listSize ) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalParameterValue( s.str() );
    }
}

template <class T>
T &arrayList<T>::get( int theIndex ) const {
    //返回索引为theIndex的元素
    //若此元素不存在，则抛出异常
    checkIndex( theIndex );
    return element[ theIndex ];
}

template <class T>
int arrayList<T>::indexOf( const T &theElement ) const {
    //返回元素theElement第一次出现时的索引
    //若该元素不存在，则返回-1

    //查找元素theIndex
    int theIndex =
        (int) ( std::find( element, element + listSize, theElement ) -
                element );

    //确定元素theElement是否找到
    if ( theIndex == listSize )
        //没有找到
        return -1;
    else
        return theIndex;
}

template <class T>
void arrayList<T>::erase( int theIndex ) {
    //删除其索引为theIndex的元素
    //如果该元素不存在，则抛出异常illegalIndex
    checkIndex( theIndex );

    //有效索引，移动其他索引大于theIndex的元素
    std::copy( element + theIndex + 1, element + listSize, element + theIndex );

    //调用析构函数
    element[ --listSize ].~T();
}

template <class T>
void arrayList<T>::insert( int theIndex, const T &theElement ) {
    if ( theIndex < 0 || theIndex > listSize ) {
        //无效索引
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalParameterValue( s.str() );
    }

    //有效索引，确定数组是否已满
    if ( listSize == arrayLength ) {
        arrayListHelper::changeLength1D( element, arrayLength,
                                         2 * arrayLength );
        arrayLength *= 2;
    }

    //把元素向右移动一个位置
    std::copy_backward( element + theIndex, element + listSize,
                        element + listSize + 1 );

    element[ theIndex ] = theElement;
    listSize++;
}

template <class T>
void arrayList<T>::output( std::ostream &out ) const {
    //把线性表插入输出流
    std::copy( element, element + listSize,
               std::ostream_iterator<T>( std::cout, "  " ) );
}
//重载
template <class T>
std::ostream &operator<<( std::ostream &out, const arrayList<T> &x ) {
    x.output( out );
    return out;
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ARRAYLIST_H
