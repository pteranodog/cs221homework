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
    if (newItem != nullptr)
    {
        bool itemInList;
        GetItem(newItem, itemInList);
        if (!itemInList)
        {
            Node *newNext = new Node(*newItem);
            newNext->SetNext(head);
            head = newNext;
            length++;
            std::cout << "Item " << head->GetItem().GetData() << " added at " << head << std::endl;
            return true;
        }
        std::cout << "Item already in list" << std::endl;
        return false;
    }
    std::cout << "Cannot put item nullptr in list" << std::endl;
    return false;
}

ItemType *USLList::GetItem(ItemType *itemToGet, bool &found)
{
    std::cout << "Searching... ";
    found = false;
    if (itemToGet == nullptr)
    {
        std::cout << "Cannot find item nullptr in list" << std::endl;
        return nullptr;
    }
    ResetList();
    while (curPos != nullptr)
    {
        std::cout << curPos->GetItem().GetData() << " ";
        if (curPos->GetItemPtr() == itemToGet)
        {
            found = true;
            std::cout << "Found!" << std::endl;
            return curPos->GetItemPtr();
        }
        curPos = curPos->Next();
    }
    std::cout << "Not found" << std::endl;
    return nullptr;
}

// This function is very long and complex
// but there's too many edge cases to handle for it to be short, clear, and elegant
// Quite unfortunate, really
bool USLList::DeleteItem(ItemType *itemToDelete)
{
    if (itemToDelete == nullptr)
    {
        std::cout << "Cannot delete item nullptr" << std::endl;
        return false;
    }
    ResetList();
    if (curPos == nullptr)
    {
        std::cout << "Cannot delete from empty list" << std::endl;
        return false;
    }
    if (curPos->GetItemPtr() == itemToDelete)
    {
        if (curPos->Next() == nullptr)
        {
            std::cout << "Deleted " << itemToDelete->GetData() << "from " << itemToDelete << std::endl;
            head = nullptr;
            delete curPos;
            curPos = nullptr;
            length--;
            return true;
        }
        else
        {
            std::cout << "Deleted " << itemToDelete->GetData() << "from " << itemToDelete << std::endl;
            head = curPos->Next();
            delete curPos;
            curPos = head;
            length--;
            return true;
        }
    }
    while (curPos->Next() != nullptr)
    {
        if (curPos->Next()->GetItemPtr() == itemToDelete)
        {
            if (curPos->Next()->Next() == nullptr)
            {
                std::cout << "Deleted " << itemToDelete->GetData() << "from " << itemToDelete << std::endl;
                delete curPos->Next();
                curPos->SetNext(nullptr);
                length--;
                return true;
            }
            else
            {
                std::cout << "Deleted " << itemToDelete->GetData() << "from " << itemToDelete << std::endl;
                Node *nodeToDelete = curPos->Next();
                curPos->SetNext(curPos->Next()->Next());
                delete nodeToDelete;
                length--;
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
    while (head != nullptr)
    {
        DeleteItem(head->GetItemPtr());
    }
    std::cout << "List has been emptied" << std::endl;
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

int USLList::GetLength()
{
    return length;
}