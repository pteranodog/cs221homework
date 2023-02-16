// Node.cpp : This file contains the implemetation of the Node class 
// for Program 2 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach

#include "Node.h"
#include "ItemType.h"

Node::Node()
{
    item = new ItemType;
    next = nullptr;
}

Node::Node(ItemType newItem)
{
    item = &newItem;
    next = nullptr;
}

Node::~Node()
{
    delete item;
    delete next;
    item = nullptr;
    next = nullptr;
}

void Node::SetNext(Node *nextNode)
{
    next = nextNode;
}

ItemType Node::GetItem()
{
    return *item;
}

Node *Node::Next()
{
    return next;
}