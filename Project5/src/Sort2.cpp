#include "Sort2.h"
#include <iostream>

using namespace std;

Sort2::Sort2()
{
    cout << "Drew Early, CS221-02, Program 5, Sort2, Quick Sort" << endl;
}

Sort2::~Sort2()
{
    // destructor unneeded for class with no dynamic memory
}

void Sort2::quickSort(int *array, int left, int right, int len)
{
    int currentLeft = left;
    int currentRight = right;
    int temp;
    int pivotindex = (left + right) / 2;
    int pivot = array[pivotindex];
    while (currentLeft <= currentRight)
    {
        while (array[currentLeft] < pivot)
        {
            currentLeft++;
        }
        while (array[currentRight] > pivot)
        {
            currentRight--;
        }
        if (currentLeft <= currentRight)
        {
            temp = array[currentLeft];
            array[currentLeft] = array[currentRight];
            array[currentRight] = temp;
            currentLeft++;
            currentRight--;
            if (GetShowWork())
            {
                Print(array, len, currentLeft, currentRight, pivotindex, left, right);
            }
        }
    }
    if (left < currentRight)
    {
        quickSort(array, left, currentRight, len);
    }
    if (currentLeft < right)
    {
        quickSort(array, currentLeft, right, len);
    }
}

void Sort2::Sorted(int array[], int len)
{
    quickSort(array, 0, len - 1, len);
}

void Sort2::Print(int array[], int len)
{
    Sorted(array, len);
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Sort2::Print(int array[], int len, bool sortFirst)
{   
    if (sortFirst)
    {
        Sorted(array, len);
    }
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Sort2::Print(int array[], int len, int highlight1, int highlight2, int highlightPivot, int left, int right)
{
    for (int i = 0; i < len; i++)
    {
        if (i == highlight1 || i == highlight2)
        {
            if (i == highlightPivot)
            {
                cout << "\033[1;33m";
            }
            else
            {
                cout << "\033[1;32m";
            }
        }
        else if (i == highlightPivot && !(i == highlight1 || i == highlight2))
        {
            cout << "\033[1;33m";
        }
        else if (i < left || i > right)
        {
            cout << "\033[1;30m";
        }
        cout << array[i] << " ";
        cout << "\033[0m";
    }
    cout << endl;
}