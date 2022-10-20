//
// Created by bruce on 10/20/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_HEAP_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_HEAP_H

#include "../helpers.h"
#include "../myExceptions.h"
#include "maxPriorityQueue.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iterator>
#include <sstream>
#include <string>

/*
template <class T>
class maxHeap : public maxPriorityQueue<T> {
  private:
    T *heap;
    int arrayLength;
    int heapSize;

  public:
    maxHeap(int initialCapacity = 10);
    ~maxHeap() {
        delete[] heap;
    }
    bool empty() const {
        return heapSize == 0;
    }
    int size() const {
        return heapSize;
    }
    const T &top() {
        if (heapSize == 0)
            throw queueEmpty();
        return heap[1];
    }
    void pop();
    void push(const T &);
    void initialize(T *, int);
    void deactiveArray() {
        heap = NULL;
        arrayLength = heapSize = 0;
    }
    void output(std::ostream &out) const;
    void testPrint() {

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if (size() >= 100) {
            std::cout
                << "This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if (typeid(T) != typeid(int)) {
            std::cout << "This print function can only work for int item";
            return;
        }

        std::cout << "The max heap size is: " << size() << std::endl;
        std::cout << "Data in the max heap: ";
        for (int i = 1; i <= size(); i++) {
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert(heap[i] >= 0 && heap[i] < 100);
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while (n > 0) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level - 1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for (int level = 0; level < max_level; level++) {
            std::string line1 = std::string(max_level_number * 3 - 1, ' ');

            int cur_level_number =
                std::min(heapSize - int(pow(2, level)) + 1, int(pow(2, level)));
            bool isLeft = true;
            for (int index_cur_level = 0; index_cur_level < cur_level_number;
                 index++, index_cur_level++) {
                putNumberInLine(heap[index], line1, index_cur_level,
                                cur_tree_max_level_number * 3 - 1, isLeft);
                isLeft = !isLeft;
            }
            std::cout << line1 << std::endl;

            if (level == max_level - 1)
                break;

            std::string line2 = std::string(max_level_number * 3 - 1, ' ');
            for (int index_cur_level = 0; index_cur_level < cur_level_number;
                 index_cur_level++)
                putBranchInLine(line2, index_cur_level,
                                cur_tree_max_level_number * 3 - 1);
            std::cout << line2 << std::endl;

            cur_tree_max_level_number /= 2;
        }
    }

  private:
    void putNumberInLine(int num, std::string &line, int index_cur_level,
                         int cur_tree_width, bool isLeft) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if (num >= 10) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        } else {
            if (isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine(std::string &line, int index_cur_level,
                         int cur_tree_width) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left =
            index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
        assert(offset_left + 1 < line.size());
        int offset_right = index_cur_level * (cur_tree_width + 1) +
                           sub_tree_width + 1 + sub_sub_tree_width;
        assert(offset_right < line.size());

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
};

template <class T>
maxHeap<T>::maxHeap(int initialCapacity) { // Constructor.
    if (initialCapacity < 1) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity + 1;
    heap = new T[arrayLength];
    heapSize = 0;
}

template <class T>
void maxHeap<T>::initialize(T *theHeap, int theSize) {
    delete[] heap;
    heap = theHeap;
    heapSize = theSize;

    for (int root = heapSize / 2; root >= 1; root--) {
        T rootElement = heap[root];

        int child = 2 * root;
        while (child <= heapSize) {
            if (child < heapSize && heap[child] < heap[child + 1])
                child++;

            if (rootElement >= heap[child])
                break;

            heap[child / 2] = heap[child];
            child *= 2;
        }
        heap[child / 2] = rootElement;
    }
}

template <class T>
void maxHeap<T>::push(const T &theElement) {

    // 当数组元素填满时增加数组长度
    if (heapSize == arrayLength - 1) {
        helpers::changeLength1D(heap, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    // 为元素theElement寻找插入位置
    // currentNode 从新叶子向上移动
    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2] < theElement) {
        heap[currentNode] = heap[currentNode / 2];
        currentNode /= 2;
    }

    heap[currentNode] = theElement;
}
class

    template <class T>
    void maxHeap<T>::pop() {
    // 如果堆为空,抛出异常
    if (heapSize == 0)
        throw queueEmpty();

    // 删除最大元素
    heap[1].~T();

    // 删除最后一个元素,然后重新建堆
    T lastElement = heap[heapSize--];

    // 从根开始,为最后一个元素寻找位置
    int currentNode = 1, child = 2;
    while (child <= heapSize) {
        if (child < heapSize && heap[child] < heap[child + 1])
            child++;

        if (lastElement >= heap[child])
            break;

        heap[currentNode] = heap[child];
        currentNode = child;
        child *= 2;
    }
    heap[currentNode] = lastElement;
}

template <class T>
void maxHeap<T>::output(std::ostream &out) const {
    std::copy(heap + 1, heap + heapSize + 1,
              std::ostream_iterator<T>(std::cout, "  "));
}

// overload <<
template <class T>
std::ostream &operator<<(std::ostream &out, const maxHeap<T> &x) {
    x.output(out);
    return out;
}*/

template <class T>
class maxHeap : public maxPriorityQueue<T> {
  private:
    T *heap;
    int arrayLength;
    int heapSize;

    void shiftUp(int k) {

        while (k > 1 && heap[k / 2] < heap[k]) {
            swap(heap[k / 2], heap[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2 * k <= heapSize) {

            int j = k * 2;
            if (j + 1 <= heapSize && heap[j] < heap[j + 1])
                j += 1;
            if (heap[k] >= heap[j])
                break;

            swap(heap[k], heap[j]);
            k = j;
        }
    }

  public:
    maxHeap(int initialCapacity = 10);
    ~maxHeap() {
        delete[] heap;
    }
    bool empty() const {
        return heapSize == 0;
    }
    int size() const {
        return heapSize;
    }
    const T &top() {
        if (heapSize == 0)
            throw queueEmpty();
        return heap[1];
    }
    void pop();
    void push(const T &);
    void initialize(T *, int);
    void deactiveArray() {
        heap = NULL;
        arrayLength = heapSize = 0;
    }
    void output(std::ostream &out) const;
    void testPrint() {

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if (size() >= 100) {
            std::cout
                << "This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if (typeid(T) != typeid(int)) {
            std::cout << "This print function can only work for int item";
            return;
        }

        std::cout << "The max heap size is: " << size() << std::endl;
        std::cout << "Data in the max heap: ";
        for (int i = 1; i <= size(); i++) {
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert(heap[i] >= 0 && heap[i] < 100);
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        int n = size();
        int max_level = 0;
        int number_per_level = 1;
        while (n > 0) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level - 1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for (int level = 0; level < max_level; level++) {
            std::string line1 = std::string(max_level_number * 3 - 1, ' ');

            int cur_level_number =
                std::min(heapSize - int(pow(2, level)) + 1, int(pow(2, level)));
            bool isLeft = true;
            for (int index_cur_level = 0; index_cur_level < cur_level_number;
                 index++, index_cur_level++) {
                putNumberInLine(heap[index], line1, index_cur_level,
                                cur_tree_max_level_number * 3 - 1, isLeft);
                isLeft = !isLeft;
            }
            std::cout << line1 << std::endl;

            if (level == max_level - 1)
                break;

            std::string line2 = std::string(max_level_number * 3 - 1, ' ');
            for (int index_cur_level = 0; index_cur_level < cur_level_number;
                 index_cur_level++)
                putBranchInLine(line2, index_cur_level,
                                cur_tree_max_level_number * 3 - 1);
            std::cout << line2 << std::endl;

            cur_tree_max_level_number /= 2;
        }
    }

  private:
    void putNumberInLine(int num, std::string &line, int index_cur_level,
                         int cur_tree_width, bool isLeft) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if (num >= 10) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        } else {
            if (isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine(std::string &line, int index_cur_level,
                         int cur_tree_width) {

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left =
            index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
        assert(offset_left + 1 < line.size());
        int offset_right = index_cur_level * (cur_tree_width + 1) +
                           sub_tree_width + 1 + sub_sub_tree_width;
        assert(offset_right < line.size());

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
};

template <class T>
maxHeap<T>::maxHeap(int initialCapacity) { // Constructor.
    if (initialCapacity < 1) {
        std::ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity + 1;
    heap = new T[arrayLength];
    heapSize = 0;
}

template <class T>
void maxHeap<T>::initialize(T *, int) {
}

template <class T>
void maxHeap<T>::push(const T &) {
}

template <class T>
void maxHeap<T>::pop() {
}

template <class T>
void maxHeap<T>::output(std::ostream &out) const {
    std::copy(heap + 1, heap + heapSize + 1,
              std::ostream_iterator<T>(std::cout, "  "));
}

// overload <<
template <class T>
std::ostream &operator<<(std::ostream &out, const maxHeap<T> &x) {
    x.output(out);
    return out;
}
* /

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_HEAP_H
