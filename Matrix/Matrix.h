//
// Created by bruce on 7/12/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MATRIX_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MATRIX_H

#include "MyExceptions.h"
#include <iostream>

template <class T>
class matrix {
    template <class F>
    friend std::ostream &operator<<( std::ostream &, const matrix<F> & );

  private:
    //矩阵的行数和列数
    int theRows, theColumns;
    //数组element
    T *element;

  public:
    matrix( int theRows = 0, int theColumns = 0 );
    matrix( const matrix<T> & );
    ~matrix() {
        delete[] element;
    }
    int rows() const {
        return theRows;
    }
    int columns() const {
        return theColumns;
    }
    T &operator()( int i, int j ) const;
    matrix<T> &operator=( const matrix<T> & );
    // unary +
    matrix<T> operator+() const;
    matrix<T> operator+( const matrix<T> & ) const;
    matrix<T> operator-() const;
    matrix<T> operator-( const matrix<T> & ) const;
    matrix<T> operator*( const matrix<T> & ) const;
    matrix<T> &operator+=( const T & );
};

//矩阵构造函数
template <class T>
matrix<T>::matrix( int theRows, int theColumns ) {
    //检查行数和列数的有效性
    if ( theRows < 0 || theColumns < 0 )
        throw illegalParameterValue( "Rows and columns must be >= 0" );
    if ( ( theRows == 0 || theColumns == 0 ) &&
         ( theRows != 0 || theColumns != 0 ) )
        throw illegalParameterValue(
            "Either both or neither rows and columns should be zero" );

    //创建矩阵
    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T[ theRows * theColumns ];
}

//矩阵复制构造函数
template <class T>
matrix<T>::matrix( const matrix<T> &m ) {
    //创建矩阵
    theRows = m.theRows;
    theColumns = m.theColumns;
    element = new T[ theRows * theColumns ];

    //复制m的每一个元素
    std::copy( m.element, m.element + theRows * theColumns, element );
}

template <class T>
matrix<T> &matrix<T>::operator=( const matrix<T> &m ) {
    //赋值.*this = m;
    //不能自己复制自己
    if ( this != &m ) {
        delete[] element;
        theRows = m.theRows;
        theColumns = m.theColumns;
        element = new T[ theRows * theColumns ];
        //复制每一个元素
        std::copy( m.element, m.element + theRows * theColumns, element );
    }
    return *this;
}

template <class T>
T &matrix<T>::operator()( int i, int j ) const {
    //返回对元素element(i,j)的引用
    if ( i < 1 || i > theRows || j < 1 || j > theColumns )
        throw matrixIndexOutOfBounds();
    return element[ ( i - 1 ) * theColumns + j - 1 ];
}

template <class T>
matrix<T> matrix<T>::operator+( const matrix<T> &m ) const {
    //返回矩阵w = (*this) + m
    if ( theRows != m.theRows || theColumns != m.theColumns )
        throw matrixSizeMismatch();

    //生成结果矩阵
    matrix<T> w( theRows, theColumns );
    for ( int i = 0; i < theRows * theColumns; i++ ) {
        w.element[ i ] = element[ i ] + m.element[ i ];
    }

    return w;
}

template <class T>
matrix<T> matrix<T>::operator-( const matrix<T> &m ) const {
    //返回矩阵w = (*this) - m
    if ( theRows != m.theRows || theColumns != m.theColumns )
        throw matrixSizeMismatch();

    //生成结果矩阵
    matrix<T> w( theRows, theColumns );
    for ( int i = 0; i < theRows * theColumns; i++ ) {
        w.element[ i ] = element[ i ] - m.element[ i ];
    }

    return w;
}

template <class T>
matrix<T> matrix<T>::operator-() const {
    //返回 w = -(*this).
    //创建矩阵w
    matrix<T> w( theRows, theColumns );
    for ( int i = 0; i < theRows * theColumns; i++ ) {
        w.element[ i ] = -element[ i ];
    }
}

template <class T>
matrix<T> matrix<T>::operator*( const matrix<T> &m ) const {
    //矩阵乘法.返回结果矩阵w=(*this) * m
    if ( theColumns != theRows )
        throw matrixSizeMismatch();

    //创建结果矩阵
    matrix<T> w( theRows, theColumns );

    //定义矩阵*this,m和w的游标且初始化(1,1)元素定位
    int ct = 0, cm = 0, cw = 0;

    //对所有i和j计算w(i,j)
    //计算结果矩阵的第i行
    for ( int i = 1; i <= theRows; i++ ) {
        //计算w(i,j)第一项
        for ( int j = 1; j <= m.theColumns; j++ ) {
            T sum = element[ ct ] * m.element[ cm ];

            //累加其余所有项
            for ( int k = 2; k <= theColumns; k++ ) {
                //*this中第i行的下一项
                ct++;
                // m中第j列的下一项
                cm += m.theColumns;
                sum += element[ ct ] * element[ cm ];
            }
            //存储在w(i,j)
            w.element[ cw++ ] = sum;

            //从行的起点和下一列重新开始
            ct -= theColumns - 1;
            cm = j;
        }

        //从下一行和第一列重新开始
        ct += theColumns;
        cm = 0;
    }

    return w;
}

template <class T>
matrix<T> &matrix<T>::operator+=( const T &x ) {
    //*this所有的元素增加x
    for ( int i = 0; i < theRows * theColumns; i++ )
        element[ i ] += x;
    return *this;
}

template <class T>
std::ostream &operator<<( std::ostream &out, const matrix<T> &m ) {
    //把矩阵m放入输出流
    //先行后列
    //元素数组索引
    int k = 0;
    for ( int i = 0; i < m.theRows; i++ ) {
        for ( int j = 0; j < m.theColumns; j++ )
            out << m.element[ k++ ] << "  ";

        out << std::endl;
    }

    return out;
}

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_MATRIX_H
