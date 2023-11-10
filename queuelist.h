#include <iostream>
#include "linkedlist.h"
#include "queue.h"

class QueueList : public Queue {
    LinkedList *queue;

public:
    QueueList() {
        queue = new LinkedList();
    }

    void enqueue(int num) {
        queue->addLast(num);
    }
    int dequeue() {
        return queue->removeFirst();
    }
    int first() {
        return queue->get(1);
    }
    bool isEmpty() {
        return size() == 0;
    }
    int size() {
        return queue->_size();
    }
    void print() {
        queue->print();
    }
};