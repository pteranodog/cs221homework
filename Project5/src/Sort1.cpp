#include "Sort1.h"
#include <iostream>

using namespace std;

Sort1::Sort1()
{
    cout << "Drew Early, CS221-02, Program 5, Sort1, Bubble Sort" << endl;
}

Sort1::~Sort1()
{
    // destructor unneeded for class with no dynamic memory
}

void Sort1::Sorted(int array[], int len)
{
    int temp;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                if (GetShowWork())
                {
                    Print(array, len, j, j + 1);
                }
            }
        }
    }
}

void Sort1::Print(int array[], int len)
{
    cout << "Bubble Sort: ";
    Sorted(array, len);
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Sort1::Print(int array[], int len, bool sortFirst)
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

void Sort1::Print(int array[], int len, int highlight1, int highlight2)
{
    for (int i = 0; i < len; i++)
    {
        if (i == highlight1 || i == highlight2)
        {
            cout << "\033[1;32m";
        }
        cout << array[i] << " ";
        cout << "\033[0m";
    }
    cout << endl;
}