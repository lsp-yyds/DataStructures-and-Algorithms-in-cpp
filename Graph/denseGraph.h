//
// Created by bruce on 10/31/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_DENSEGRAPH_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_DENSEGRAPH_H

#include <cassert>
#include <iostream>
#include <vector>

class denseGraph {
  private:
    int v, e;
    bool directed;
    std::vector<std::vector<bool>> g;

  public:
    denseGraph(int v, bool directed) {
        this->v = v;
        this->e = 0;
        this->directed = directed;
        for (int i = 0; i < v; ++i)
            g.push_back(std::vector<bool>(v, false));
    }

    ~denseGraph() {
    }

    int V() {
        return v;
    }

    int E() {
        return e;
    }

    void addEdge(int v, int w) {
        assert(v >= 0 && v < this->v);
    }
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_DENSEGRAPH_H
