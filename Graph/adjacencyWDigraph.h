//
// Created by bruce on 10/17/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ADJACENCYWDIGRAPH_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_ADJACENCYWDIGRAPH_H

#include "../myExceptions.h"
#include "delete2dArray.h"
#include "graph.h"
#include "make2dArray.h"
#include <iostream>
#include <iterator>
#include <sstream>

template <class T>
class adjacencyWDigraph : public graph<T> {
  protected:
    int v;
    int e;
    T **a;
    T noEdge;

  public:
    // 构造函数
    adjacencyWDigraph(int numberOfVertices = 0, T theNoEdge = 0) {
        if (numberOfVertices < 0)
            throw illegalParameterValue("number of vertices must be >= 0");
        v = numberOfVertices;
        e = 0;
        noEdge = theNoEdge;
        make2dArray(a, v + 1, v + 1);
        for (int i = 1; i <= v; ++i)
            fill(a[i], a[i] + v + 1, noEdge);
    }

    ~adjacencyWDigraph() {
        delete2dArray(a, v + 1);
    }

    int numberOfVertices() const {
        return v;
    }

    int numberOfEdges() const {
        return e;
    }

    bool directed() const {
        return true;
    }

    bool weighted() const {
        return true;
    }

    bool existsEdge(int i, int j) const {
        if (i < 1 || j < 1 || i > v || j > v || a[i][j] == noEdge)
            return false;
        else
            return true;
    }

    void insertEdge(edge<T> *theEdge) {
        int v1 = theEdge->vertex1();
        int v2 = theEdge->vertex2();
        if (v1 < 1 || v2 < 1 || v1 > v || v2 > v || v1 == v2) {
            std::ostringstream s;
            s << "<" << v1 << "," << v2 << "> is not a permissible edge";
            throw illegalParameterValue(s.str());
        }

        if (a[v1][v2] == noEdge)
            e++;
        a[v1][v2] = theEdge->weight();
    }

    void eraseEdge(int i, int j) {
        if (i >= 1 && j >= 1 && i <= v && j <= v && a[i][j] != noEdge) {
            a[i][j] = noEdge;
            e--;
        }
    }

    void checkVertex(int theVertex) const {
        if (theVertex < 1 || theVertex > v) {
            std::ostringstream s;
            s << "no vertex " << theVertex;
            throw illegalParameterValue(s.str());
        }
    }

    int degree(int theVertex) const {
        throw undefinedMethod("degree() undefined");
    }

    int outDegree(int theVertex) const {
        checkVertex(theVertex);

        int sum = 0;
        for (int j = 1; j <= v; j++)
            if (a[theVertex][j] != noEdge)
                sum++;

        return sum;
    }

    int inDegree(int theVertex) const {
        checkVertex(theVertex);

        int sum = 0;
        for (int j = 1; j <= v; j++)
            if (a[j][theVertex] != noEdge)
                sum++;

        return sum;
    }

    class myIterator : public vertexIterator<T> {
      protected:
        T *row;
        T noEdge;
        int n;
        int currentVertex;

      public:
        myIterator(T *theRow, T theNoEdge, int numberOfVertices) {
            row = theRow;
            noEdge = theNoEdge;
            v = numberOfVertices;
            currentVertex = 1;
        }

        ~myIterator() {
        }

        int next(T &theWeight) {
            for (int j = currentVertex; j <= n; j++)
                if (row[j] != noEdge) {
                    currentVertex = j + 1;
                    theWeight = row[j];
                    return j;
                }
        }
    };

    myIterator *iterator(int theVertex) {
        checkVertex(theVertex);
        return new myIterator(a[theVertex], noEdge, v);
    }
};

#endif // DATASTRUCTURES_A

// ND_ALGORITHMS_IN_CPP_ADJACENCYWDIGRAPH_H
