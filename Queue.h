#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <climits> // Add this line
using namespace std;

template <class Type>
class Queue {
private:
    struct Node {
        Type data;
        Node* next;
        Node(Type d) : data(d), next(nullptr) {}
    };
    Node* front;
    Node* back;
    int count;

public:
    Queue() : front(nullptr), back(nullptr), count(0) {}

    Queue(const Queue<Type>& q) {
        front = nullptr;
        back = nullptr;
        count = 0;
        Node* temp = q.front;
        while (temp != nullptr) {
            enqueue(temp->data);
            temp = temp->next;
        }
    }

    Queue<Type>& operator=(const Queue<Type>& q) {
        if (this != &q) {
            clear();
            Node* temp = q.front;
            while (temp != nullptr) {
                enqueue(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }

    // Destructor
    ~Queue() {
        clear();
    }

    void enqueue(Type data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        count++;
    }

    Type peek() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return front->data;
    }

    void dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        count--;
        if (count == 0) {
            back = nullptr;
        }
    }

    bool isEmpty() const {
        return count == 0;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    friend ostream& operator<<(ostream& out, const Queue<Type>& q) {
        Node* temp = q.front;
        while (temp != nullptr) {
            out << temp->data;
            if (temp->next != nullptr) {
                out << endl;
            }
            temp = temp->next;
        }
        return out;
    }
};

#endif