// USLlist.cpp : This file contains the implemetation of the USLList class 
// for Program 2 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach

#include "USLList.h"
#include "Node.h"
#include "ItemType.h"

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

bool USLList::PutItem(ItemType *newItem)
{
    bool successful = false;
    if (newItem != nullptr)
    {
        bool itemInList;
        GetItem(newItem, itemInList);
        if (itemInList)
        {
            Node *newNext = new Node(*newItem);
            newNext->SetNext(head);
            head = newNext;
            length++;
            successful = true;
        }
    }
    return successful;
}

ItemType *USLList::GetItem(ItemType *itemToGet, bool &found)
{

}

bool USLList::DeleteItem(ItemType *itemToDelete)
{

}

void USLList::ResetList()
{
    curPos = head;
}

void USLList::MakeEmpty()
{

}

Node *USLList::GetNext()
{
    if (head != nullptr)
    {
        
    }
}