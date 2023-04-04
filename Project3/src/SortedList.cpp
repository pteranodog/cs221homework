// SortedList.cpp : This file contains the implemetation of the SortedList class 
// for Program 3
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach

#include "SortedList.h"
#include "ItemType.h"
#include <iostream>

using namespace std;

SortedList::SortedList()
{
    MaxArraySize = 100;
    itemList = new ItemType[MaxArraySize];
    curPos = -1;
    length = 0;
}

SortedList::SortedList(int maxArraySize)
{
    cout << "Hi! This code was written by Drew Early for Assignment 3 of CS221 with Mrs. Delugach and I hope you're having a wonderful day!" << endl;
    MaxArraySize = maxArraySize;
    itemList = new ItemType[MaxArraySize];
    curPos = -1;
    length = 0;
}

SortedList::SortedList(const SortedList &listToCopy)
{
    MaxArraySize = listToCopy.MaxArraySize;
    itemList = new ItemType[MaxArraySize];
    curPos = listToCopy.curPos;
    length = listToCopy.length;
    for (int i = 0; i < length; i++)
    {
        itemList[i] = listToCopy.itemList[i];
    }
}

SortedList::~SortedList()
{
    delete[] itemList;
}

bool SortedList::PutItem(ItemType newItem)
{
    bool success = false;
    if (length == 0)
    {
        itemList[0] = newItem;
        length++;
        curPos = 0;
        success = true;
        string titleToPrint;
        cout << "Added " << newItem.GetData(titleToPrint) << ", \"" << titleToPrint << "\"" << endl;
    }
    else if (length < MaxArraySize)
    {
        bool found = false;
        GetItem(newItem, found);
        if (!found)
        {
            int possiblePlacePosition = 0;
            while (possiblePlacePosition < length && newItem > itemList[possiblePlacePosition])
            {
                possiblePlacePosition++;
            }
            for (int itemsAbovePlacePosition = length; itemsAbovePlacePosition > possiblePlacePosition; itemsAbovePlacePosition--)
            {
                itemList[itemsAbovePlacePosition] = itemList[itemsAbovePlacePosition - 1];
            }
            itemList[possiblePlacePosition] = newItem;
            length++;
            success = true;
            string titleToPrint;
            cout << "Added " << newItem.GetData(titleToPrint) << ", \"" << titleToPrint << "\"" << endl;
        }
        else
        {
            cout << "Cannot add duplicate item" << endl;
        }
    }
    else
    {
        cout << "Cannot add item to full list" << endl;
    }
    return success;
}

ItemType SortedList::getItemInternal(ItemType itemToGet, bool &found, int start, int end)
{
    if (start > end)
    {
        cout << "Not Found!" << endl;
        found = false;
        return ItemType();
    }
    else
    {
        int middleElement = (start + end) / 2;
        cout << itemList[middleElement].GetData() << "...";
        if (itemToGet == itemList[middleElement])
        {
            cout << "Found!" << endl;
            found = true;
            return itemList[middleElement];
        }
        else if (itemToGet < itemList[middleElement])
        {
            return getItemInternal(itemToGet, found, start, middleElement - 1);
        }
        else
        {
            return getItemInternal(itemToGet, found, middleElement + 1, end);
        }
    }
}

ItemType SortedList::GetItem(ItemType itemToGet, bool &found)
{
    if (length == 0)
    {
        cout << "Cannot get item from empty list" << endl;
        found = false;
        return ItemType();
    }
    cout << "Searching...";
    return getItemInternal(itemToGet, found, 0, length - 1);
}

bool SortedList::DeleteItem(ItemType itemToDelete)
{
    bool deleted = false;
    bool found = false;
    GetItem(itemToDelete, found);
    if (found)
    {
        int itemToDeletePosition = 0;
        while (itemToDelete > itemList[itemToDeletePosition])
        {
            itemToDeletePosition++;
        }
        for (int itemsAboveDeletePosition = itemToDeletePosition; itemsAboveDeletePosition < length - 1; itemsAboveDeletePosition++)
        {
            itemList[itemsAboveDeletePosition] = itemList[itemsAboveDeletePosition + 1];
        }
        length--;
        if (curPos == length)
        {
            curPos--;
        }
        deleted = true;
        string titleToPrint;
        cout << "Deleted " << itemToDelete.GetData(titleToPrint) << ", \"" << titleToPrint << "\"" << endl;
    }
    else
    {
        cout << "Cannot delete missing item" << endl;
    }
    return deleted;
}

ItemType SortedList::ResetList()
{
    if (length == 0)
    {
        cout << "Cannot reset list with no items" << endl;
        return ItemType();
    }
    curPos = 0;
    return itemList[curPos];
}

void SortedList::MakeEmpty()
{
    delete[] itemList;
    itemList = new ItemType[MaxArraySize];
    curPos = -1;
    length = 0;
}

void SortedList::PrintList()
{
    if (length == 0)
    {
        cout << "Cannot print empty list" << endl;
    }
    else
    {
        cout << "Printing List:" << endl;
        string titleToShow;
        for (int i = 0; i < length; i++)
        {
            cout << i+1 << ". " << itemList[i].GetData(titleToShow) << ", \"" << titleToShow << "\"" << endl;
        }
    }
    
}

ItemType SortedList::GetNext()
{
    ItemType itemToReturn;
    if (curPos == length - 1)
    {
        itemToReturn = ItemType();
    }
    else
    {
        curPos++;
        itemToReturn = itemList[curPos];
    }
    return itemToReturn;
}

int SortedList::GetLength()
{
    return length;
}