#ifndef onewayList_h
#define onewayList_h

#include "iList.h"

class OneWayList : public IList {
private:
    int tab[N][2];
    int head;
public:
    OneWayList();
    void printList() final;
    void printTab() final;

    void add(int e) final;
    void add(int e, int i) final;
    void removeValue(int e) final;
    void removePosition(int i) final;
    bool contains(int e) final;
    void sort() final;
};

#endif /* onewayList_h */
