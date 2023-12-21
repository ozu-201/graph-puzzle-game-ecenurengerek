//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_GRAPH_H
#define DATASTRUCTURES_CPP_GRAPH_H


#include "EdgeList.h"
#include "../../General/AbstractGraph.h"
#include <iostream>
using namespace std;

namespace list {

    class Graph : public AbstractGraph{
    private:
        EdgeList *edges;
        string* labels;
    public:
        explicit Graph(int vertexCount);
        ~Graph();
        int findIndex(string label);
        const void addEdge(string from, string to);
        const void addEdge(string from, string to, int weight);
        void connectedComponentsDisjointSet();
        Path* bellmanFord(int source);
        Path* dijkstra(int source);
        void prim();
    protected:
        void depthFirstSearch(bool* visited, string fromNode) ;
        void breadthFirstSearch(bool* visited, string startNode) ;
        Edge* edgeList(int& edgeCount) override;
    };

}
#endif //DATASTRUCTURES_CPP_GRAPH_H
