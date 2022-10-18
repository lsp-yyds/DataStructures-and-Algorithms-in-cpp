//
// Created by bruce on 10/17/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_GRAPH_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_GRAPH_H

#include "edge.h"
#include "vertexIterator.h"
#include <iostream>

template <class T>
class graph {
  public:
    virtual ~graph();

    // 图的顶点数
    virtual int numberOfVertices() const = 0;
    // 图的边数
    virtual int numberOfEdges() const = 0;
    // 如果边(i,j)存在,返回true,否则返回false
    virtual bool existsEdge(int, int) const = 0;
    // 插入边
    virtual void insertEdge(edge<T> *) = 0;
    // 删除边
    virtual void eraseEdge(int, int) const = 0;
    // 顶点的度
    virtual int degree(int) const = 0;
    // 顶点的入度
    virtual int inDegree(int) const = 0;
    // 顶点的出度
    virtual int outDegree(int) const = 0;

    // 当且仅当是有向图时, 返回true
    virtual bool directed() const = 0;
    // 当且进当是加权图是, 返回true
    virtual bool weighted() const = 0;
    // 访问指定顶点的相邻顶点
    virtual vertexIterator<T> *iterator(int) = 0;
    // 输出图
    virtual void output(std::ostream &) const = 0;

    // 广度优先遍历
    virtual void bfs(int v, int reach[], int label);

    // 深度优先遍历
    void dfs(int v, int reach[], int label);

    //
    int *findPath(int theSource, int theDestination);

    bool connected();

    int labelComponents(int c[]);

    bool topologicalOrder(int *theOrder);

    int bipartiteCover(int *theLabel, int *theCover);

    bool kruskal(weightedEdge<T> *spanningTreeEdges);

    void bellmanFord(int s, T *d, int *p);

  protected:
    static int *reach;
    static int *path;
    static int label;
    static int length;
    static int destination;
    static int *bin;
    static binNode *node;

    void rDfs(int v);
    bool rFindPath(int s);
    void createBins(int b, int n);
    void insertBins(int b, int v);
    void moveBins(int bMax, int toBin, int v);
};

int *graph<bool>::reach;
int graph<bool>::label;

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_GRAPH_H
