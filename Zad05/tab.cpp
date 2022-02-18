#include <iostream>
#include <limits.h>
using namespace std;

const int N = 10000;

struct fifo {
    int tab[N];
    int last = -1;

    void enqueue(int val) {
        tab[++last] = val;
    }

    bool isEmpty() {
        if(last == -1) {
            return true;
        }
        return false;
    }

    int dequeue() {
        if(!isEmpty()) {
            int pom = tab[0];
            for(int i = 0; i < last; i++) {
                tab[i] = tab[i+1];
            }
            last--;
            return pom;
        }
        return -INT32_MAX;
    }

    int size() {
        return last+1;
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