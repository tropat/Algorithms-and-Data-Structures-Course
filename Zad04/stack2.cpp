#include <iostream>
#include <limits.h>
using namespace std;

const int n = 100;

struct element {
    int value;
    element* previous;

    element(int val, element * prev) {
        value = val;
        previous = prev;
    }
};

struct stack {
    element* head = NULL;

    void push(int val) {
        head = new element(val, head);
    }
    int pop() {
        if(!isEmpty()) {
            int v = head->value;
            head = head->previous;
            return v;
        }
        else return INT_MIN;
    }
    bool isEmpty() {
        if(head == NULL) return true;
        return false;
    }
};

int main() {
    stack s;
    if(s.isEmpty()) cout << "Empty stack\n";
    else cout << "Not empty stack\n";
    cout << "Push: 5\n";
    s.push(5);
    cout << "Push: 1\n";
    s.push(1);
    cout << "Push: -4\n";
    s.push(-4);
    cout << "Push: 1\n";
    s.push(1);
    if(s.isEmpty()) cout << "Empty stack\n";
    else cout << "Not empty stack\n";
    cout << "Pop: " << s.pop() << "\n";
    cout <<"Pop: " << s.pop() << "\n";
    cout <<"Pop: " << s.pop() << "\n";

    return 0;
}