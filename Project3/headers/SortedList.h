// SortedList.h : This file contains the declaration of the SortedList class 
// for Program 3
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach

#pragma once
#include "ItemType.h"

class SortedList
{
private:
    int MaxArraySize;
    ItemType* itemList;
    int curPos;
    int length;
    ItemType getItemInternal(ItemType itemToGet, bool &found, int start, int end);

public:
    SortedList();
    SortedList(int maxArraySize);
    SortedList(const SortedList &listToCopy);
    ~SortedList();
    bool PutItem(ItemType newItem);
    ItemType GetItem(ItemType itemToGet, bool &found);
    bool DeleteItem(ItemType itemToDelete);
    ItemType ResetList();
    void MakeEmpty();
    void PrintList();
    ItemType GetNext();
    int GetLength();
};