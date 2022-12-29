//
// Created by bruce on 10/22/22.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_UNIONFINDNODE_H
#define DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_UNIONFINDNODE_H

struct unionFindNode {
    int parent;
    bool root;

    unionFindNode() {
        parent = 1;
        root = true;
    }
};

#endif // DATASTRUCTURES_AND_ALGORITHMS_IN_CPP_UNIONFINDNODE_H
