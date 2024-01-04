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
        void addEdge(string from, string to);
        void addEdge(string from, string to, int weight);
        Path* dijkstra(string source);

    protected:
        void depthFirstSearch(bool* visited, string fromNode) ;
        void breadthFirstSearch(bool* visited, string startNode) ;
        Edge* edgeList(int& edgeCount) override;
    };

}
#endif //DATASTRUCTURES_CPP_GRAPH_H
