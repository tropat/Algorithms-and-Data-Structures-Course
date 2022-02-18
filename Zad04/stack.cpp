#include <iostream>
#include <limits.h>
using namespace std;

const int n = 100;

struct stack {
    int tab[n];
    int head = -1;

    void push(int val) {
        tab[++head] = val;
    }
    int pop() {
        if(!empty()) return tab[head--];
        else return INT_MIN;
    }
    bool empty() {
        if(head == -1) return true;
        return false;
    }
};

int main() {
    stack s;
    if(s.empty()) cout << "Empty stack\n";
    else cout << "Not empty stack\n";
    cout << "Push: 5\n";
    s.push(5);
    cout << "Push: 1\n";
    s.push(1);
    cout << "Push: -4\n";
    s.push(-4);
    cout << "Push: 1\n";
    s.push(1);
    if(s.empty()) cout << "Empty stack\n";
    else cout << "Not empty stack\n";
    cout << "Pop: " << s.pop() << "\n";
    cout <<"Pop: " << s.pop() << "\n";
    cout <<"Pop: " << s.pop() << "\n";

    return 0;
}