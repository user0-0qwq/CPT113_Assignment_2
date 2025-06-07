#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>
#include <string>

template<class T>
struct CircularNode {
public:
    T data;
    CircularNode<T>* next;
    CircularNode(T val) : data(val), next(nullptr) {

    }
};

template <class T>
class CircularLinkedList {
private:
    CircularNode<T>* tail;
    int count;

public:
    CircularLinkedList() : tail(nullptr), count(0) {}

    ~CircularLinkedList() {
        while (count > 0) {
            removeFront();
        }
    }

    void addMember(T data) {
        CircularNode<T>* newNode = new CircularNode<T>(data);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void rotateAndPrintOnce() const {
        if (!tail) {
            std::cout << "No members in study group.\n";
            return;
        }

        CircularNode<T>* current = tail->next;
        do {
            current->data->printProfile();
            current = current->next;
        } while (current != tail->next);
    }

    void removeFront() {
        if (!tail) return;

        CircularNode<T>* front = tail->next;

        if (tail == front) {
            delete front;
            tail = nullptr;
        } else {
            tail->next = front->next;
            delete front;
        }
        count--;
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }
};

#endif
