// Sort2.h : Implements quick sort
// for Program 5
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach 

#include "Sort.h"

class Sort2: public Sort
{
    public:
        Sort2();
        ~Sort2();
        void Sorted(int array[], int len);
        void Print(int array[], int len);
};