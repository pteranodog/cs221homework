// Sort4.h : Implements heap sort
// for Program 5
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach 

#include "Sort.h"

class Sort4: public Sort
{
    public:
        Sort4();
        ~Sort4();
        void Sorted(int array[], int len);
        void Print(int array[], int len);
};