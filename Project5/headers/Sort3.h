// Sort3.h : Implements heap sort
// for Program 5
//
// By Drew Early
// for CS221-02
// Mrs. Delugach

#include "Sort.h"

class Sort3 : public Sort
{
private:
    void heapify(int array[], int len, int i);

public:
    Sort3();
    ~Sort3();
    void Sorted(int array[], int len);
    void Print(int array[], int len);
    void Print(int array[], int len, bool sortFirst);
    void Print(int array[], int len, int highlight1, int highlight2, bool isheap);
};