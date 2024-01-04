//
// Created by Olcay Taner YILDIZ on 6.03.2023.
//

#include "Node.h"
#include <string>

Node::Node(string data) {
    this->data = data;
    this->next = nullptr;
}

void Node::setNext(Node *_next) {
    this->next = _next;
}

Node *Node::getNext() {
    return next;
}

string Node::getData() {
    return data;
}

