#include "Sort3.h"
#include <iostream>

using namespace std;

Sort3::Sort3()
{
    cout << "Drew Early, CS221-02, Program 5, Sort3, Heap Sort" << endl;
}

Sort3::~Sort3()
{
    // destructor unneeded for class with no dynamic memory
}

void Sort3::heapify(int array[], int len, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < len && array[left] > array[largest])
    {
        largest = left;
    }
    if (right < len && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        if (GetShowWork())
        {
            Print(array, len, i, largest, true);
        }
        heapify(array, len, largest);
    }
}

void Sort3::Sorted(int array[], int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        heapify(array, len, i);
    }
    for (int i = len - 1; i >= 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        if (GetShowWork())
        {
            Print(array, len, 0, i, false);
        }
        heapify(array, i, 0);
    }
}

void Sort3::Print(int array[], int len)
{
    cout << "Heap Sort: ";
    Sorted(array, len);
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Sort3::Print(int array[], int len, bool sortFirst)
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

void Sort3::Print(int array[], int len, int highlight1, int highlight2, bool isheap)
{
    for (int i = 0; i < len; i++)
    {
        if (i == highlight1 || i == highlight2)
        {
            if (isheap)
            {
                cout << "\033[1;33m";
            }
            else
            {
                cout << "\033[1;32m";
            }
        }
        cout << array[i] << " ";
        cout << "\033[0m";
    }
    cout << endl;
}