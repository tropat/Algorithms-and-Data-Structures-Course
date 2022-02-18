#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "bubbleSort.h"
#include "mergeSort.h"

using namespace std;

double p = -10;
double q = 10;

void tabPrint(double tab[], int n) {
    cout << "| ";
    for(int i = 0; i<n; i++) {
        cout << tab[i] << " | ";
    }
    cout << '\n';
}

void tabRandom(double tab[], int n) {
    for(int i = 0; i < n; i++) {
        tab[i] = p + (double)rand()/RAND_MAX*(q-p+1);
    }
}

int main() {
    srand(time(NULL));

    int n = 200;
    cout << "\nn = " << n << endl;

    cout << "\nBUBBLE SORT\n";

    double *tab = new double[n];
    tabRandom(tab, n);

    //tabPrint(tab, n);
    bubbleSort(tab, n);
    cout << "Operacji: " << ileOperacjiBubble() << endl;
    resetBubble();
    //cout << "\nSORTED: \n";
    //tabPrint(tab,n);

    cout << "\nMERGE SORT\n";

    tabRandom(tab, n);

    //tabPrint(tab, n);
    mergeSort(tab, 0, n-1, n);
    cout << "Operacji: " << ileOperacjiMerge() << endl;
    resetMerge();
    //cout << "\nSORTRED: \n";
    //tabPrint(tab, n);
    
    delete [] tab;

    ofstream fileBubble("bubbleSort.data");
    ofstream fileMerge("mergeSort.data");

    cout << "\nZbieranie danych do wykresow.";

    for (int i=1; i<=n; i++) {
        double * tab = new double[i];

        tabRandom(tab, i);
        bubbleSort(tab, i);
        fileBubble << i << " " << ileOperacjiBubble() << "\n";

        tabRandom(tab, i);
        mergeSort(tab, 0, i-1, i);
        fileMerge << i << " " << ileOperacjiMerge() << "\n";

        delete [] tab;
        resetBubble();
        resetMerge();
    }

    cout << "\nZakonczono.\n";
    cout << "\nSzczegolowe informacje w README\n";

    fileBubble.close();
    fileMerge.close();

    return 0;
}