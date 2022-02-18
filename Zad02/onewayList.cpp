#include <iostream>
#include "onewayList.h"
using namespace std;

OneWayList::OneWayList() {
    for(int i = 0; i < N; i++) {
        tab[i][0] = INT32_MAX;
        tab[i][1] = -1;
    }
    head = -1;
}

void OneWayList::printList() {
    cout << "List: (head) ";
    for(int i = head; i != -1; i = tab[i][1]) {
        cout << tab[i][0] << " -> ";
    }
    cout << "NULL\n";
}

void OneWayList::printTab() {
    cout << "Tab: ";
    for(int i = 0 ; i < 8; i ++) {
        cout << "[" << tab[i][0] << "|" << tab[i][1] << "] ";
    }
    cout << "..." << endl;
}

void OneWayList::add(int e) {
    for(int i = 0; i < N; i++) {
        if(tab[i][0] == INT32_MAX) {
            tab[i][0] = e;
            tab[i][1] = -1;
            if(head == -1) {
                head = i;
            }
            else {
                for(int j = head; j != -1 ; j = tab[j][1]) {
                    if(i != j && tab[j][1] == -1 && tab[j][0] != INT32_MAX) {
                        tab[j][1] = i;
                        break;
                    }
                }
            }
            break;
        }
    }
}

void OneWayList::add(int e, int i) {
        for(int p = 0; p < N; p++) {
            if(tab[p][0] == INT32_MAX) {
                tab[p][0] = e;
                tab[p][1] = -1;
                for(int j = head, k = 0; j != -1; j = tab[j][1]) {
                    if(i == 0) {
                        tab[p][1] = head;
                        head = p;
                        break;
                    }
                    else if(k == i - 1) {
                        k = tab[j][1];
                        tab[j][1] = p;
                        tab[p][1] = k;
                        break;
                    }
                    else {
                        k++;
                    }
                }
                break;
            }
        }
    }

void OneWayList::removeValue(int e) {
        for(int i = head; i != -1; i = tab[i][1]) {
            if(tab[i][0] == e && i == head) {
                tab[i][0] = INT32_MAX;
                head = tab[i][1];
                tab[i][1] = -1;
                break;
            }
            else if(tab[tab[i][1]][0] == e) {
                tab[tab[i][1]][0] = INT32_MAX;
                int next = tab[tab[i][1]][1];
                tab[tab[i][1]][1] = -1;
                tab[i][1] = next;
                break;
            }
        }
    }

void OneWayList::removePosition(int i) {
        for(int p = head, k = 0; p != -1; p = tab[p][1]) {
            if(i == 0) {
                tab[p][0] = INT32_MAX;
                head = tab[p][1];
                tab[p][1] = -1;
                break;
            }
            if(k == i-1) {
                tab[tab[p][1]][0] = INT32_MAX;
                int next = tab[tab[p][1]][1];
                tab[tab[p][1]][1] = -1;
                tab[p][1] = next;
                break;
            }
            k++;
        }
    }

bool OneWayList::contains(int e) {
        for(int i = head; i != -1; i = tab[i][1]) {
            if(tab[i][0] == e) {
                return true;
            }
        }
        return false;
    }

void OneWayList::sort() {
    int pom;
    for(int i = head; i != -1; i = tab[i][1]) {
        for(int j = head; tab[j][1] != -1; j = tab[j][1]) {
            if(tab[j][0] > tab[tab[j][1]][0]) {
                pom = tab[j][0];
                tab[j][0] = tab[tab[j][1]][0];
                tab[tab[j][1]][0] = pom;
            }
        }
    }
}