// Node.h : This file contains the declaration of the Node class 
// for Program 2 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach 

#pragma once
#include "ItemType.h"

class Node
{
private:
    ItemType *item;
    Node *next;

public:
    Node();
    Node(ItemType newItem);
    ~Node();
    void SetNext(Node *nextNode);
    ItemType GetItem();
    ItemType *GetItemPtr(); // For some reason, everything breaks if this isn't an option. I think it may be due to a conflict between the return type of Node::GetItem and the return type of USLList::GetItem
    Node *Next();
};