#include <iostream>
#include "twowayList.h"
using namespace std;

TwoWayList::TwoWayList() {
    for(int i = 0; i < N; i++) {
        tab[i][0] = INT32_MAX;
        tab[i][1] = -1;
        tab[i][2] = -1;
    }
    head = -1;
}

void TwoWayList::printList() {
    cout << "List: (head) ";
    for(int i = head; i != -1; i = tab[i][1]) {
        cout << tab[i][0] << " <-> ";
    }
    cout << "NULL\n";
}

void TwoWayList::printTab() {
    cout << "Tab: ";
    for(int i = 0 ; i < 8; i ++) {
        cout << "[" << tab[i][0] << "|" << tab[i][1] << "|" << tab[i][2] << "] ";
    }
    cout << "..." << endl;
}

void TwoWayList::add(int e) {
    for(int i = 0; i < N; i++) {
        if(tab[i][0] == INT32_MAX) {
            tab[i][0] = e;
            tab[i][1] = -1;
            if(head == -1) {
                head = i;
                tab[i][2] = -1;
            }
            else {
                for(int j = head; j != -1 ; j = tab[j][1]) {
                    if(i != j && tab[j][1] == -1 && tab[j][0] != INT32_MAX) {
                        tab[j][1] = i;
                        tab[i][2] = j;
                        break;
                    }
                }
            }
            break;
        }
    }
}

void TwoWayList::add(int e, int i) {
        for(int p = 0; p < N; p++) {
            if(tab[p][0] == INT32_MAX) {
                tab[p][0] = e;
                tab[p][1] = -1;
                for(int j = head, k = 0; j != -1; j = tab[j][1]) {
                    if(i == 0) {
                        tab[p][1] = head;
                        tab[head][2] = p;
                        head = p;
                        tab[p][2] = -1;
                        break;
                    }
                    else if(k == i - 1) {
                        k = tab[j][1];
                        tab[j][1] = p;
                        tab[p][2] = j;
                        tab[p][1] = k;
                        if(k != -1) {
                            tab[k][2] = p;
                        }
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

void TwoWayList::removeValue(int e) {
        for(int i = head; i != -1; i = tab[i][1]) {
            if(tab[i][0] == e && i == head) {
                tab[i][0] = INT32_MAX;
                head = tab[i][1];
                if(tab[i][1] != -1) {
                    tab[tab[i][1]][2] = -1;
                }
                tab[i][1] = -1;
                break;
            }
            else if(tab[i][0] == e) {
                tab[i][0] = INT32_MAX;
                if(tab[i][1] != -1) {
                    tab[tab[i][2]][1] = tab[i][1];
                    tab[tab[i][1]][2] = tab[i][2];
                } else {
                    tab[tab[i][2]][1] = -1;
                }
                tab[i][1] = -1;
                tab[i][2] = -1;
                break;
            }
        }
    }

void TwoWayList::removePosition(int i) {
        for(int p = head, k = 0; p != -1; p = tab[p][1]) {
            if(i == 0) {
                tab[p][0] = INT32_MAX;
                head = tab[p][1];
                if(tab[p][1] != -1) {
                    tab[tab[p][1]][2] = -1;
                }
                tab[p][1] = -1;
                break;
            }
            if(k == i) {
                tab[p][0] = INT32_MAX;
                tab[tab[p][2]][1] = tab[p][1];
                tab[tab[p][1]][2] = tab[p][2];
                tab[p][1] = -1;
                tab[p][2] = -1;
                break;
            }
            k++;
        }
    }

bool TwoWayList::contains(int e) {
        for(int i = head; i != -1; i = tab[i][1]) {
            if(tab[i][0] == e) {
                return true;
            }
        }
        return false;
    }

void TwoWayList::sort() {
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