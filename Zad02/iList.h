#ifndef iList_h
#define iList_h

class IList {
public:
    virtual void printTab() = 0;
    virtual void printList() = 0;
    virtual void add(int e) = 0;
    virtual void add(int e, int i) = 0;
    virtual void removeValue(int e) = 0;
    virtual void removePosition(int i) = 0;
    virtual bool contains(int e) = 0;
    virtual void sort() = 0;
};

#define N 1000

#endif /* iList_h */
