//
// Created by Olcay Taner YILDIZ on 15.05.2023.
//

#include <climits>
#include "AbstractGraph.h"
#include "../Array/DisjointSet.h"
#include "../List/Graph/Edge.h"

AbstractGraph::AbstractGraph(int vertexCount) {
    this->vertexCount = vertexCount;
}

Path *AbstractGraph::initializePaths(int source) const {
    Path* paths = new Path[vertexCount];
    for (int i = 0; i < vertexCount; i++){
        paths[i] = Path(INT_MAX, -1);
    }
    paths[source].setDistance(0);
    return paths;
}
