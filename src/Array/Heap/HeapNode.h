//
// Created by Olcay Taner YILDIZ on 24.04.2023.
//

#ifndef DATASTRUCTURES_CPP_HEAPNODE_H
#define DATASTRUCTURES_CPP_HEAPNODE_H

#include <iostream>
using namespace std;


class HeapNode {
private:
    int data;
    string name;
public:
    HeapNode(int data, string name);
    HeapNode();
    int getData() const;
    string getName() const;
    void setData(int _data);
};


#endif //DATASTRUCTURES_CPP_HEAPNODE_H
