// USLList.h : This file contains the declaration of the USLList class 
// for Program 2 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach

#pragma once
#include "ItemType.h"
#include "Node.h"

class USLList
{
private:
    Node* head;
    Node* curPos;
    int length;
    ItemType* GetItemValidated(ItemType* itemToGet, bool &found);
    bool DeleteItemValidated(ItemType* itemToDelete);

public:
    USLList();
    ~USLList();
    bool PutItem(ItemType* newItem);
    ItemType* GetItem(ItemType* itemToGet, bool &found);
    bool DeleteItem(ItemType* itemToDelete);
    void ResetList();
    void MakeEmpty();
    void PrintList();
    Node* GetNext();
    int GetLength();
};