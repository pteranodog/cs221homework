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
        cout << "Attempting to add " << newItem->GetData() << " to list..." << endl << "- ";
        bool itemAlreadyExists;
        GetItem(newItem, itemAlreadyExists);
        if (itemAlreadyExists)
        {
            // Input item is already in list, add nothing to list
            cout << "- Item " << newItem->GetData() << " is already in list" << endl;
        }
        else
        {
            // Item is not already in list, add item to list
            Node* newNode = new Node(*newItem);
            newNode->SetNext(head);
            head = newNode;
            length++;
            success = true;
            cout << "- Added " << newItem->GetData() << " at " << head << endl;
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
    cout << "Searching... ";
    while (curPos != nullptr)
    {
        cout << curPos->GetItem().GetData() << " ";
        if (curPos->GetItem().Compare(itemToGet->GetData()) == EQUAL)
        {
            // Item is found, return item
            foundItem = new ItemType(curPos->GetItem());
            found = true;
            cout << "...Found!" << endl;
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
        // Item was not present in list
        cout << "...Item " << itemToGet->GetData() << " not found" << endl;
    }
    return foundItem;
}


// THIS FUNCTION ASSUMES THE INPUTS HAVE BEEN VALIDATED
// DO NOT USE WITH UNVALIDATED INPUTS
bool USLList::DeleteItemValidated(ItemType *itemToDelete)
{
    ResetList();
    bool found = false;
    if (head->GetItem().Compare(itemToDelete->GetData()) == EQUAL)
    {
        // Item is in head, delete item
        if (head->Next() != nullptr)
        {
            // Head is not the only node
            Node* headToDelete = head;
            head = head->Next();
            delete headToDelete;
            cout << "Deleted " << itemToDelete->GetData() << " from " << headToDelete << endl;
            headToDelete = nullptr;
            ResetList();
        }
        else
        {
            // Head is the only node
            delete head;
            cout << "Deleted " << itemToDelete->GetData() << " from " << head << endl;
            head = nullptr;
            ResetList();
        }
        // Once the head is deleted, do the following
        length--;
        found = true;
    }
    else if (head->Next() != nullptr)
    {
        // Second node is valid, begin traversing list
        while (curPos->Next() != nullptr)
        {
            if (curPos->Next()->GetItem().Compare(itemToDelete->GetData()) == EQUAL)
            {
                // Next item is the correct item, check if it's the last item
                if (curPos->Next()->Next() == nullptr)
                {
                    // Correct item is last in list
                    delete curPos->Next();
                    cout << "Deleted " << itemToDelete->GetData() << " from " << curPos->Next() << endl;
                    curPos->SetNext(nullptr);
                }
                else
                {
                    // Correct item is in middle of list
                    Node* nodeToDelete = curPos->Next();
                    curPos->SetNext(nodeToDelete->Next());
                    delete nodeToDelete;
                    cout << "Deleted " << itemToDelete->GetData() << " from " << nodeToDelete << endl;
                    nodeToDelete = nullptr;
                }
                // Once item is deleted, do the following
                length--;
                found = true;
                break;
            }
            else
            {
                // Not the correct item, move forward
                curPos = curPos->Next();
            }
        }
    }
    if (!found)
    {
        cout << "Item " << itemToDelete->GetData() << " could not be deleted because it was not found" << endl;
    }
    return found;
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
            cout << "Cannot get item " << itemToGet->GetData() << " from empty list" << endl;
        }
    }
    else
    {
        // Input item is invalid
        cout << "Cannot get item \"nullptr\" from list" << endl;
    }
    return foundItem;
}

bool USLList::DeleteItem(ItemType *itemToDelete)
{
    // Validates inputs and then call DeleteItemValidated
   bool found = false;
    ItemType* foundItem = nullptr;
    if (itemToDelete != nullptr)
    {
        // Input item is valid, check against all list members
        if (head != nullptr)
        {
            // List is not empty, so we can check for the item!
            found = DeleteItemValidated(itemToDelete);
        }
        else
        {
            cout << "Cannot delete item " << itemToDelete->GetData() << " from empty list" << endl;
        }
    }
    else
    {
        // Input item is invalid
        cout << "Cannot delete item \"nullptr\" from list" << endl;
    }
    return found;
}

void USLList::ResetList()
{
    curPos = head;
}

void USLList::MakeEmpty()
{
    cout << "Emptying list..." << endl;
    while (length != 0)
    {
        ItemType* firstItemInList = new ItemType(head->GetItem().GetData());
        cout << "- ";
        DeleteItem(firstItemInList);
    }
    cout << "- All items deleted. List is now empty" << endl;
}

void USLList::PrintList()
{
    if (head != nullptr)
    {
        // List is not empty, print list
        Node* curPrintPos = head;
        cout << "Printing list:" << endl;
        while (curPrintPos != nullptr)
        {
            cout << "- " << curPrintPos->GetItem().GetData() << " is at " << curPrintPos << endl;
            curPrintPos = curPrintPos->Next();
        }
        cout << "List print complete" << endl;
    }
    else
    {
        // List is empty
        cout << "Cannot print empty list" << endl;
    }
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