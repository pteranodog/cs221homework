// CS221Program5.cpp : This file contains the driver
// for Program 5
//
// By Drew Early
// for CS221-02
// Mrs. Delugach

#include <iostream>
#include <ctime>
#include <chrono>
#include "Sort.h"
#include "Sort1.h"
#include "Sort2.h"
#include "Sort3.h"

using namespace std;

void InitArray(int array[], int len);
void SortItOut(Sort &sorter, int Array[], int len);
void SortItOut(Sort &sorter, int Array[], int len, bool work, bool beforeAndAfter);

int main()
{
    srand(time(NULL));
    cout << endl << "\033[0m" << endl;

    int displayedLength = 20;
    int timedLength = 100000;
    bool work = false;

    cout << "Displayed Sorts" << endl;
    cout << "Creating arrays, length: " << displayedLength << endl;

    int array1[displayedLength];
    InitArray(array1, displayedLength);
    int array2[displayedLength];
    InitArray(array2, displayedLength);
    int array3[displayedLength];
    InitArray(array3, displayedLength);

    Sort1 sort1;
    SortItOut(sort1, array1, displayedLength);
    cout << endl;
    
    Sort2 sort2;
    SortItOut(sort2, array2, displayedLength);
    cout << endl;

    Sort3 sort3;
    SortItOut(sort3, array3, displayedLength);
    cout << endl;

    cout << "Timed Sorts" << endl;
    cout << "Creating arrays, length: " << timedLength << endl;
    int array4[timedLength];
    InitArray(array4, timedLength);
    int array5[timedLength];
    InitArray(array5, timedLength);
    int array6[timedLength];
    InitArray(array6, timedLength);
    
    cout << "Bubble Sort (May take up to 30 seconds):" << endl;
    auto start = chrono::high_resolution_clock::now();
    SortItOut(sort1, array4, timedLength, false, false);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << (float) duration.count() / 1000000.0 << " seconds" << endl;

    cout << "Quick Sort: " << endl;
    start = chrono::high_resolution_clock::now();
    SortItOut(sort2, array5, timedLength, false, false);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << (float) duration.count() / 1000000.0 << " seconds" << endl;

    cout << "Heap Sort: " << endl;
    start = chrono::high_resolution_clock::now();
    SortItOut(sort3, array6, timedLength, false, false);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << (float) duration.count() / 1000000.0 << " seconds" << endl;

    cout << endl;
    cout << "All tests complete." << endl;

    system("pause");
    return 0;
}

void InitArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        array[i] = rand() % (len * 10);
    }
}

void SortItOut(Sort &sorter, int Array[], int len)
{
    cout << "\033[31m";
    sorter.Print(Array, len, false);
    cout << "\033[0m";

    sorter.SetShowWork(true); // or false, as I choose
    sorter.Sorted(Array, len);

    cout << "\033[32m";
    sorter.Print(Array, len, false);
    cout << "\033[0m";
}

void SortItOut(Sort &sorter, int Array[], int len, bool work, bool beforeAndAfter)
{
    if (beforeAndAfter)
    {
        cout << "\033[31m";
        sorter.Print(Array, len, false);
        cout << "\033[0m";
    }

    sorter.SetShowWork(work); // defined by the caller
    sorter.Sorted(Array, len);

    if (beforeAndAfter)
    {
        cout << "\033[32m";
        sorter.Print(Array, len, false);
        cout << "\033[0m";
    }
}