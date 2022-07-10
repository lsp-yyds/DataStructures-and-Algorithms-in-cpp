//
// Created by bruce on 7/10/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_CHAIN_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_CHAIN_H

#include "IllegalParameterValue.h"
#include "LinearList.h"
#include <sstream>

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
class chain : public linearList<T> {
  protected:
    //如果索引无效，抛出异常
    void checkIndex( int theIndex ) const;
    //指向链表第一个节点的指针
    chainNode<T> *firstNode;
    //线性表的元素个数
    int listSize;

  public:
    //构造函数、复制构造函数和析构函数
    chain( int initialCapacity = 10 );
    chain( const chain<T> & );
    ~chain();

    //抽象数据类型ADT的方法
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
};

template <class T>
chain<T>::chain( int initialCapacity ) {
    //构造函数
    if ( initialCapacity < 1 ) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue( s.str() );
    }
    firstNode = NULL;
    listSize = 0;
}

template <class T>
chain<T>::chain( const chain<T> &theList ) {
    //复制构造函数
    listSize = theList.listSize;

    if ( listSize == 0 ) {
        //链表theList为空
        firstNode = NULL;
        return;
    }

    //链表theList为非空
    //要复制链表theList的节点
    chainNode<T> *sourceNode = theList.firstNode;
    //复制链表theList的首元素
    firstNode = new chainNode<T>( sourceNode->element );
    sourceNode = sourceNode->next;
    //当前链表*this的最后一个节点
    chainNode<T> *targetNode = firstNode;
    while ( sourceNode != NULL ) {
        //复制剩余元素
        targetNode->next = new chainNode<T>( sourceNode->element );
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL;
}

template <class T>
chain<T>::~chain() {
    //链表析构函数.删除链表所有节点
    while ( firstNode != NULL ) {
        //删除首节点
        chainNode<T> *nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template <class T>
void chain<T>::checkIndex( int theIndex ) const {
    //确定索引theIndex在0和listSize - 1之间
    if ( theIndex < 0 || theIndex >= listSize ) {
        std::ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalParameterValue( s.str() );
    }
}

template <class T>
T &chain<T>::get( int theIndex ) const {
    //返回索引为theIndex的元素
    //若该元素不存在，则抛出异常
    checkIndex( theIndex );

    //移向所需节点
    chainNode<T> *currentNode = firstNode;
    for ( int i = 0; i < theIndex; i++ ) {
        currentNode = currentNode->next;
    }

    return currentNode->element;
}

template <class T>
int chain<T>::indexOf( const T &theElement ) const {
    //返回元素theElement首次出现时的索引
    //若该元素不存在，则返回-1

    //搜索链表寻找元素theElement
    chainNode<T> *currentNode = firstNode;
    //当前节点的索引
    int index = 0;
    while ( currentNode != NULL && currentNode->element != theElement ) {
        //移向下一个节点
        currentNode = currentNode->next;
        index++;
    }

    //确定是否找到所需元素
    if ( currentNode == NULL )
        return -1;
    else
        return index;
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_CHAIN_H
