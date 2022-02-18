#include <iostream>
#include "onewayList.h"
#include "twowayList.h"
using namespace std;

void print(IList * lista) {
    lista->printTab();
    lista->printList();
}

void test(IList * lista);

int main() {
    cout << "\tOne-Way List:\n\n";

    OneWayList lista;

    test(&lista);

    cout << "\n\n\tTwo-Way List:\n\n";

    TwoWayList lista2;

    test(&lista2);

    return 0;
}

void test(IList * lista) {
    print(lista);

    cout << "---\n" << "Add 1\n";
    lista->add(1);
    print(lista);
    
    cout << "---\n" <<  "Add 2\n";
    lista->add(2);
    print(lista);
    
    cout << "---\n" <<  "Add 3, position 1\n";
    lista->add(3,1);
    print(lista);
    
    cout << "---\n" <<  "Remove 2\n";
    lista->removeValue(2);
    print(lista);
    
    cout << "---\n" <<  "Remove 1\n";
    lista->removeValue(1);
    print(lista);

    cout << "---\n" <<  "Remove, position 0\n";
    lista->removePosition(0);
    print(lista);

    cout << "---\n" <<  "Add 6\n";
    lista->add(6);
    print(lista);
    
    cout << "---\n" <<  "Add 8, position 1\n";
    lista->add(8,1);
    print(lista);
    
    cout << "---\n" <<  "Add 4\n";
    lista->add(4);
    print(lista);
    
    cout << "---\n" <<  "Add 9\n";
    lista->add(9);
    print(lista);
    
    cout << "---\n" <<  "Add 0, position 0\n";
    lista->add(0,0);
    print(lista);

    cout << "---\n" <<  "Add 0, position 5\n";
    lista->add(0,5);
    print(lista);

    cout << "---\n" <<  "Remove, position 3\n";
    lista->removePosition(3);  
    print(lista);

    cout << "---\n" <<  "Contains 3: ";
    if(lista->contains(3)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    cout <<  "---\n" << "Contains 0: ";
    if(lista->contains(0)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    cout << "---\n" <<  "Sort\n";
    lista->sort();
    print(lista);
}