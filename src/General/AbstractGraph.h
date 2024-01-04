//
// Created by Olcay Taner YILDIZ on 15.05.2023.
//

#ifndef DATASTRUCTURES_CPP_ABSTRACTGRAPH_H
#define DATASTRUCTURES_CPP_ABSTRACTGRAPH_H


#include "Path.h"
#include "../List/Graph/Edge.h"

class AbstractGraph {
protected:
    int vertexCount;
    virtual void depthFirstSearch(bool* visited, string fromNode) = 0;
    virtual void breadthFirstSearch(bool* visited, string startNode) = 0;
    virtual Edge* edgeList(int& edgeCount) = 0;
    Path* initializePaths(int source) const;
public:
    explicit AbstractGraph(int vertexCount);
};


#endif //DATASTRUCTURES_CPP_ABSTRACTGRAPH_H
