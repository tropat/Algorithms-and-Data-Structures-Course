#include <iostream>
using namespace std;

int porownanBubble = 0;
int przestawienBubble = 0;

void bubbleSort(double tab[], int n) {
    double pom = 0.0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            porownanBubble++;
            if(tab[j] > tab[j+1]) {
                przestawienBubble++;
                pom = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = pom;
            }
        }
    }
}

void resetBubble() {
    porownanBubble = 0;
    przestawienBubble = 0;
}

int ileOperacjiBubble() {
    return porownanBubble+przestawienBubble;
}