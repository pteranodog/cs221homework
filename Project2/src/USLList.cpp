// USLlist.cpp : This file contains the implemetation of the USLList class 
// for Program 2 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach

#include "USLList.h"
#include "Node.h"
#include "ItemType.h"
#include <iostream>

using namespace std;

USLList::USLList()
{
    head = nullptr;
    curPos = nullptr;
    length = 0;
}

USLList::~USLList()
{
    MakeEmpty();
}

bool USLList::PutItem(ItemType* newItem)
{
    bool success = false;
    if (newItem != nullptr)
    {
        // Input item is valid, check if it's in the list already
        bool itemAlreadyExists;
        GetItem(newItem, itemAlreadyExists);
        if (itemAlreadyExists)
        {
            // Input item is already in list, add nothing to list
            cout << "Item " << newItem->GetData() << " is already in list" << endl;
        }
        else
        {
            // Item is not already in list, add item to list
            Node* newNode = new Node(*newItem);
            newNode->SetNext(head);
            head = newNode;
            length++;
            success = true;
            cout << "Added " << newItem->GetData() << " at " << head << endl;
        }
    }
    else
    {
        // Input item is null, add nothing to list
        cout << "Cannot add item \"nullptr\" to list" << endl;
    }
    return success;
}

// THIS FUNCTION ASSUMES THE INPUTS HAVE BEEN VALIDATED
// DO NOT USE WITH UNVALIDATED INPUTS
ItemType* USLList::GetItemValidated(ItemType* itemToGet, bool &found)
{
    ItemType* foundItem = nullptr;
    ResetList();
    while (curPos != nullptr)
    {
        if (curPos->GetItem().Compare(itemToGet->GetData()) == EQUAL)
        {
            // Item is found, return item
            foundItem = new ItemType(curPos->GetItem());
            found = true;
            break;
        }
        else
        {
            // Item is not found, move to next node
            curPos = curPos->Next();
        }
    }
    if (!found)
    {

    }
    return foundItem;
}

ItemType* USLList::GetItem(ItemType* itemToGet, bool &found)
{
    // Validate inputs and then call GetItemValidated
    found = false;
    ItemType* foundItem = nullptr;
    if (itemToGet != nullptr)
    {
        // Input item is valid, check against all list members
        if (head != nullptr)
        {
            // List is not empty, so we can check for the item!
            foundItem = GetItemValidated(itemToGet, found);
        }
        else
        {
            // List is empty
        }
    }
    else
    {
        // Input item is invalid
    }
    return foundItem;
}

bool USLList::DeleteItem(ItemType *itemToDelete)
{
   return false;
}

void USLList::ResetList()
{
    curPos = head;
}

void USLList::MakeEmpty()
{

}

Node* USLList::GetNext()
{
    if (curPos != nullptr)
    {
        curPos = curPos->Next();
        return curPos;
    }
    return curPos;
}

int USLList::GetLength()
{
    return length;
}