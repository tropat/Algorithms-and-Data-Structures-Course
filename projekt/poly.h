#ifndef POLY_H
#define POLY_H

#include <iostream>

class Poly {
    private:
        float * tab;
        int n;
        float horner_rek(float x, int i);
    
    public:
        Poly(int n);
        ~Poly();
        Poly add(Poly p);
        Poly subtract(Poly p);
        Poly multiply(Poly p);
        Poly multiply(float c);
        float horner(float x);
        void str();
        void set();
};

#endif