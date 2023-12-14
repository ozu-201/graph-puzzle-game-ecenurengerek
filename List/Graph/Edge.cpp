//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//
using namespace std;
#include "Edge.h"
#include <string>

Edge::Edge(string from, string to, int weight) {
    this->from = from;
    this->to = to;
    this->weight = weight;
    next = nullptr;
}

void Edge::setNext(Edge *_next) {
    next = _next;
}

Edge *Edge::getNext() const{
    return next;
}

string Edge::getFrom() const{
    return from;
}

string Edge::getTo() const{
    return to;
}

int Edge::getWeight() const{
    return weight;
}

Edge::Edge() {
}
