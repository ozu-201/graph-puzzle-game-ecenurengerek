//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//
using namespace std;
#include "Graph.h"
#include "../../Array/DisjointSet.h"
#include "../Queue.h"
#include "../../Array/Heap/MinHeap.h"
#include <string>

namespace list {

    Graph::Graph(int _vertexCount) : AbstractGraph(_vertexCount){
        edges = new EdgeList[vertexCount];
        labels = new string[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            edges[i] = EdgeList();
        }
    }

    int Graph::findIndex(string label){
        for(int i = 0; i< vertexCount;i++){
            if(labels[i] == label){
                return i;
            }
        }
        return -1;
    }

    void Graph::addEdge(string from, string to) {
        Edge* edge = new Edge(from, to, 1);
        edges[findIndex(from)].insert(edge);
    }

    void Graph::addEdge(string from, string to, int weight) {
        Edge* edge = new Edge(from, to, weight);
        edges[findIndex(from)].insert(edge);
    }

    Graph::~Graph() {
        delete[] edges;
    }

    void Graph::depthFirstSearch(bool *visited, string fromNode) {
        Edge* edge;
        string toNode;
        edge = edges[findIndex(fromNode)].getHead();
        while (edge != nullptr){
            toNode = edge->getTo();
            if (!visited[findIndex(toNode)]){
                visited[findIndex(toNode)] = true;
                depthFirstSearch(visited, toNode);
            }
            edge = edge->getNext();
        }
    }

    void Graph::breadthFirstSearch(bool *visited, string startNode) {
        Edge* edge;
        string fromNode, toNode;
        Queue queue = Queue();
        queue.enqueue(new Node(startNode));
        while (!queue.isEmpty()){
            fromNode = queue.dequeue()->getData();
            edge = edges[findIndex(fromNode)].getHead();
            while (edge != nullptr) {
                toNode = edge->getTo();
                if (!visited[findIndex(toNode)]){
                    visited[findIndex(toNode)] = true;
                    queue.enqueue(new Node(toNode));
                }
                edge = edge->getNext();
            }
        }
    }

    Path *Graph::dijkstra(string source) {
        Edge* edge;
        Path* shortestPaths = initializePaths(findIndex(source));
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert(HeapNode(shortestPaths[i].getDistance(), labels[i]));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            string fromNode = node.getName();
            edge = edges[findIndex(fromNode)].getHead();
            while (edge != nullptr){
                string toNode = edge->getTo();
                int newDistance = shortestPaths[findIndex(fromNode)].getDistance() + edge->getWeight();
                if (newDistance < shortestPaths[findIndex(toNode)].getDistance()){
                    int position = heap.search(toNode);
                    heap.update(position, newDistance);
                    shortestPaths[findIndex(toNode)].setDistance(newDistance);
                    shortestPaths[findIndex(toNode)].setPrevious(findIndex(fromNode));
                }
                edge = edge->getNext();
            }
        }
        return shortestPaths;
    }

    Edge *Graph::edgeList(int& edgeCount) {
        Edge* list;
        edgeCount = 0;
        for (int i = 0; i < vertexCount; i++){
            Edge* edge = edges[i].getHead();
            while (edge != nullptr){
                edgeCount++;
                edge = edge->getNext();
            }
        }
        list = new Edge[edgeCount];
        int index = 0;
        for (int i = 0; i < vertexCount; i++){
            Edge* edge = edges[i].getHead();
            while (edge != nullptr){
                list[index] = Edge(edge->getFrom(), edge->getTo(), edge->getWeight());
                index++;
                edge = edge->getNext();
            }
        }
        return list;
    }

}