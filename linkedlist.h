#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

class LinkedList : public List {
    node *head, *tail;
    int size;

public:
    void addFirst(int num) {
        node* n = new node;
        n->elem = num;
        // Step 2: Set the n's next to head
        n->next = head;
        // Step 3: Head to n
        head = n;
        if (!tail) {
            tail = n;
        }
        // Step 4: Inc size
        size++;
    }

    void addLast(int num) {
        // STEP 1: Create node
        node* n = (node*) malloc( sizeof(node) );
        n->elem = num;
        n->next = nullptr;
        // STEP 2: Tail's next = n
        if (tail) {
            tail->next = n;
        } else {
            head = n;
        }
        // STEP 3: Tail = n
        tail = n;
        // STEP 4: Increment size
        size++;
    }

    void add(int num) {
        addFirst(num);
    }

    int get(int pos) {
        node* curr = head;
        int ctr = 1;
        while (ctr < pos) {
            curr = curr->next;
            ctr++;
        }
        return curr->elem;
    }

    int remove(int num) {
        return 0;
    }

    int removeFirst() {
        if (size == 0) return -1;
        node* tmpPtr;
        tmpPtr = head;
        head = head->next;
        int tmp = tmpPtr->elem;
        free(tmpPtr);
        tmpPtr = nullptr;
        size--;
        return tmp;
    }

    int _size() {
        return size;
    }

    void print() {
        node* curr = head;
        cout << "Size: " << size << endl;
        while (curr != nullptr) {
            cout << curr->elem << "->";
            curr = curr->next;
        }
        cout << endl;
    }

};