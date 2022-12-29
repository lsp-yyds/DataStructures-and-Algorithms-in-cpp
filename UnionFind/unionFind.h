//
// Created by bruce on 10/22/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_UNIONFIND_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_UNIONFIND_H

#include "unionFindNode.h"

class unionFind {
  protected:
    unionFindNode *node;

  public:
    unionFind(int numberOfElements) {
        node = new unionFindNode[numberOfElements + 1];
    }

    void unite(int rootA, int rootB) {
        if (node[rootA].parent < node[rootB].parent) {
            node[rootB].parent += node[rootA].parent;
            node[rootA].root = false;
            node[rootA].parent = rootB;
        } else {
            node[rootA].parent += node[rootB].parent;
            node[rootB].root = false;
            node[rootB].parent = rootA;
        }
    }

    int find(int theElement) {
        int theRoot = theElement;
        while (!node[theElement].root)
            theRoot = node[theRoot].parent;

        int currentNode = theElement;
        while (currentNode != theRoot) {
            int parentNode = node[currentNode].parent;
            node[currentNode].parent = theRoot;
            currentNode = parentNode;
        }

        return theRoot;
    }
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_UNIONFIND_H
