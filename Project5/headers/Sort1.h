// Sort1.h : Implements bubble sort
// for Program 5
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach 

#include "Sort.h"

class Sort1: public Sort
{
    public:
        Sort1();
        ~Sort1();
        void Sorted(int array[], int len);
        void Print(int array[], int len);
};