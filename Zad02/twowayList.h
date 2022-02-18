#ifndef twowayList_h
#define twowayList_h

#include "iList.h"

class TwoWayList : public IList {
private:
    int tab[N][3];
    int head;
public:
    TwoWayList();
    void printList() final;
    void printTab() final;

    void add(int e) final;
    void add(int e, int i) final;
    void removeValue(int e) final;
    void removePosition(int i) final;
    bool contains(int e) final;
    void sort() final;
};

#endif /* twowayList_h */
