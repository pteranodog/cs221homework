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
    ItemType* item;
    Node* next;

public:
    Node();
    Node(ItemType newItem);
    ~Node();
    void SetNext(Node* nextNode);
    ItemType GetItem();
    Node* Next();
};