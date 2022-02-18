#include <iostream>
using namespace std;

struct element{
    int value;
    element * previous;
    element * next;
    element(int e) {
        value = e;
        next = NULL;
        previous = NULL;
    }
};

struct twoWayList {
    element * head;

    twoWayList() {
        head = NULL;
    }

    void print() {
        cout << "List: (head) ";
        for(element * el = head; el != NULL; el = el->next) {
            cout << el->value << " <-> ";
        }
        cout << "NULL\n";
    }

    void add(int e) {
        element * el = new element(e);
        el->next = head;
        if(head != NULL) {
            head->previous = el;
        }
        head = el;
    }

    void add(int e, int i) {
        if(i == 0) {
            add(e);
        } else {
            for(element * elem = head; elem != NULL; elem = elem->next, i--) {
                if(i==1) {
                    element * el = new element(e);
                    el->next = elem->next;
                    el->previous = elem;
                    elem->next->previous = el;
                    elem->next = el;
                }
            }
        }
    }

    void removeValue(int e) {
        if(head != NULL && e == head->value) {
            head = head->next;
            if(head != NULL) {
                head->previous = NULL;
            }
        } else {
            for(element * el = head; el != NULL; el = el->next) {
                if(el->value == e) {
                    el->previous->next = el->next;
                    if(el->next!=NULL) {
                        el->next->previous = el->previous;
                    }
                }
            }
        }
    }

    void removePosition(int i) {
        if(i == 0) {
            head = head->next;
            head->previous = NULL;
        } else {
            for(element * el = head; el != NULL; el = el->next, i--) {
                if(i == 1) {
                    el->next = el->next->next;
                    el->next->previous = el;
                }
            }
        }
    }

    bool contains(int e) {
        for(element * el = head; el != NULL; el = el->next) {
                if(el->value == e) {
                    return true;
                }
            }
        return false;
    }

    void sort() {
        for(element * el = head; el->next != NULL; el = el->next) {
            for(element * e = head; e->next != NULL; e = e->next) {
                if(e->value > e->next->value) {
                    int pom = e->value;
                    e->value = e->next->value;
                    e->next->value = pom;
                }
            }
        }
    }
};

int main() {
    twoWayList lista;
    lista.print();
    lista.add(0,0);
    lista.add(5);
    lista.add(2);
    lista.print();
    lista.add(4,1);
    lista.add(7,0);
    lista.print();
    lista.removeValue(5);
    lista.print();
    lista.removePosition(0);
    lista.print();
    if(lista.contains(2)) cout << "Zawiera 2\n"; 
    else cout << "Nie zawiera 2\n";
    lista.add(-8,1);
    lista.add(10,0);
    lista.print();
    lista.sort();
    lista.print();

    return 0;
}