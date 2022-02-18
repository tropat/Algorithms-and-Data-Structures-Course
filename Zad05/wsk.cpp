#include <iostream>
#include <limits.h>
using namespace std;

struct node {
    int val;
    node * next;

    node(int v) {
        val = v;
        next = NULL;
    }
};

struct fifo {
    node *first = NULL;
    node *last = NULL;
    int s = 0;

    bool isEmpty() {
        if(first == NULL) {
            return true;
        }
        return false;
    }

    void enqueue(int val) {
        if(isEmpty()) {
            first = new node(val);
            first->next = last;
            last = first;
        } else {
            node * pom = new node(val);
            last->next = pom;
            last = pom;
        }
        s++;
    }

    int dequeue() {
        if(!isEmpty()) {
            node * pom = first;
            first = first->next;
            s--;
            return pom->val;
        }
        return -INT32_MAX;
    }

    int size() {
        return s;
    }
};

int main() {
    fifo f;
    
    if(f.isEmpty()) {
        cout << "Pusty\n";
    } else {
        cout << "Nie pusty\n";
    }
    f.enqueue(3);
    f.enqueue(9);
    f.enqueue(0);
    f.enqueue(-2);

    cout << "Size: " << f.size() << endl;

    cout << f.dequeue() << endl;
    cout << f.dequeue() << endl;

    f.enqueue(5);

    cout << "Size: " << f.size() << endl;

    cout << f.dequeue() << endl;

    return 0;
}