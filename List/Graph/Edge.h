//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_EDGE_H
#define DATASTRUCTURES_CPP_EDGE_H


#include <string>

class Edge {
private:
    string from;
    string to;
    int weight;
    Edge* next;
public:
    Edge();
    Edge(string from, string to, int weight);
    void setNext(Edge* _next);
    Edge* getNext() const;
    string getFrom() const;
    string getTo() const;
    int getWeight() const;
};


#endif //DATASTRUCTURES_CPP_EDGE_H
