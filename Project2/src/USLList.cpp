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
    found = false;
    if (itemToGet == nullptr)
    {
        return nullptr;
    }
    ResetList();
    while (curPos != nullptr)
    {
        if (&curPos->GetItem() == itemToGet)
        {
            found = true;
            return &curPos->GetItem();
        }
        curPos = curPos->Next();
    }   
    return nullptr;
}

bool USLList::DeleteItem(ItemType *itemToDelete)
{
    if (itemToDelete == nullptr)
    {
        return false;
    }
    ResetList();
    if (curPos == nullptr)
    {
        return false;
    }
    if (&curPos->GetItem() == itemToDelete)
    {
        if (curPos->Next() == nullptr)
        {
            head = nullptr;
            delete curPos;
            curPos = nullptr;
            return true;
        }
        else
        {
            head = curPos->Next();
            delete curPos;
            curPos = head;
            return true;
        }
    }
    while (curPos->Next() != nullptr)
    {
        if (&curPos->Next()->GetItem() == itemToDelete)
        {
            if (curPos->Next()->Next() == nullptr)
            {
                delete curPos->Next();
                curPos->SetNext(nullptr);
                return true;
            }
            else
            {
                Node *nodeToDelete = curPos->Next();
                curPos->SetNext(curPos->Next()->Next());
                delete nodeToDelete;
                return true;
            }
        }
        else
        {
            curPos = curPos->Next();
        }
    }
    return false;
}

void USLList::ResetList()
{
    curPos = head;
}

void USLList::MakeEmpty()
{
    while (DeleteItem(&head->GetItem()));
}

Node *USLList::GetNext()
{
    if (curPos != nullptr)
    {
        curPos = curPos->Next();
        return curPos;
    }
    return curPos;
}