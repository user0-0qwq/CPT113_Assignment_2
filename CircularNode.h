#ifndef CIRCULARNODE_H
#define CIRCULARNODE_H

#include <iostream>
#include <string>

template<class T>
class CircularNode{
public:
    T data;
    CircularNode<T>* next;

    CircularNode(T val) : data(val), next(nullptr) {

    }
};

#endif
