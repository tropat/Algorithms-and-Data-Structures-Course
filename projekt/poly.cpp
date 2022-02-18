#include <iostream>
#include "poly.h"
using namespace std;

Poly::Poly(int n) {
    tab = new float [n+1];
    this->n = n;
}
Poly::~Poly() {
    tab = NULL;
    delete tab;
}
Poly Poly::add(Poly p) {
    int size = n > p.n ? n : p.n;
    int less = n < p.n ? n : p.n;
    Poly poly(size);
    int i = 0;
    for(i=0;i<=less;i++) {
        poly.tab[i] = tab[i] + p.tab[i];
    }
    if(n > p.n) {
        for(i;i<=size;i++) {
            poly.tab[i] = tab[i];
        }
    } else {
        for(i;i<=size;i++) {
            poly.tab[i] = p.tab[i];
        }
    }
    return poly;
}
Poly Poly::subtract(Poly p) {
    int size = n > p.n ? n : p.n;
    int less = n < p.n ? n : p.n;
    Poly poly(size);
    int i = 0;
    for(i=0;i<=less;i++) {
        poly.tab[i] = tab[i] - p.tab[i];
    }
    if(n > p.n) {
        for(i;i<=size;i++) {
            poly.tab[i] = tab[i];
        }
    } else {
        for(i;i<=size;i++) {
            poly.tab[i] = -p.tab[i];
        }
    }
    return poly;
}
Poly Poly::multiply(Poly p) {
    int size = n+p.n;
    Poly poly(size);

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=p.n;j++) {
            poly.tab[i+j] += tab[i] * p.tab[j];
        }
    }

    return poly;
}
Poly Poly::multiply(float c) {
    Poly poly(n);

    for(int i=0;i<=n;i++) {
        poly.tab[i] = tab[i]*c;
    }

    return poly;
}
float Poly::horner(float x) {
    return horner_rek(x,n);
}
float Poly::horner_rek(float x, int i) {
    if(i==0) {
        return tab[i];
    }
    return x*horner_rek(x,i-1)+tab[i];
}
void Poly::str(){
    for(int i=n;i>=0;i--) {
        if(i!=n) cout << " + ";
        if(i!=0 && i!=1) cout << tab[i] << "x^" << i;
        else if(i==1) cout << tab[i] << "x";
        else cout << tab[i];
    }

    cout << endl;
}
void Poly::set() {
    for(int i=n;i>=0;i--) {
        cout << "(x^" << i << ") * ";
        cin >> tab[i];
    }
}