#include <iostream>
using namespace std;

double *pom;
int porownanMerge = 0;
int przestawienMerge = 0;

void merge(double tab[], int left, int middle, int right) {

    int l = left;
    int m = middle + 1;

    for(int i = left; i <= right; i++) {
        //przestawienMerge++;
        pom[i] = tab[i];
    }

    for(int i = left; i <= right; i++) {
        porownanMerge++;
        if(l <= middle) {
            porownanMerge++;
            if(m <= right) {
                porownanMerge++;
                if(pom[l] < pom[m]) {
                    tab[i] = pom[l];
                    przestawienMerge++;
                    l++;
                }
                else {
                    tab[i] = pom[m];
                    przestawienMerge++;
                    m++;
                }
            }
            else {
                tab[i] = pom[l];
                przestawienMerge++;
                l++;
            }
        }
        else {
            tab[i] = pom[m];
            przestawienMerge++;
            m++;
        }
    }
} 

void mergeSortFunc(double tab[], int left, int right) {
    if(left>=right) {
        porownanMerge++;
        return;   
    }
    int middle = (left + right)/2;

    mergeSortFunc(tab, left, middle);
    mergeSortFunc(tab, middle+1, right);

    merge(tab, left, middle, right);

}

void resetMerge() {
    porownanMerge = 0;
    przestawienMerge = 0;
}

void mergeSort(double tab[], int left, int right, int n) {
    pom = new double[n];
    mergeSortFunc(tab, left, right);
}

int ileOperacjiMerge() {
    return porownanMerge+przestawienMerge;
}