// Sort3.h : Implements merge sort
// for Program 5
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach 

#include "Sort.h"

class Sort3: public Sort
{
    public:
        Sort3();
        ~Sort3();
        void Sorted(int array[], int len);
        void Print(int array[], int len);
};