#include <iostream>
#include "poly.h"
using namespace std;

int main() {
    int n1, n2;

    cout << "Podaj stopien pierwszego wielomianu: ";
    cin >> n1;

    Poly poly1(n1);
    poly1.set();

    cout << "Podaj stopien drugiego wielomianu: ";
    cin >> n2;
    
    Poly poly2(n2);
    poly2.set();
    
    cout << endl;
    poly1.str();
    poly2.str();

    cout << "\nDodawanie wielomianow: \n";
    poly1.add(poly2).str();
    cout << "\nOdejmowanie wielomianow: \n";
    poly1.subtract(poly2).str();
    cout << "\nMnozenie wielomianow: \n";
    poly1.multiply(poly2).str();
    cout << "\nMnozenie wielomianu przez liczbe: c = ";
    float c;
    cin >> c;
    poly1.multiply(c).str();
    cout << "\nObliczanie wartosci wielomianu (schemat Hornera): x = ";
    float x;
    cin >> x;
    cout << poly1.horner(x) << endl;

    return 0;
}