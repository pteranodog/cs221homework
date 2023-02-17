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
    item = new ItemType(newItem);
    next = nullptr;
}

Node::~Node()
{
    // This shouldn't be possible but I'm checking anyway
    if (item != nullptr)
    {
        delete item;
    }
    item = nullptr;
}

void Node::SetNext(Node* nextNode)
{
    // Does not check for nulltr
    // Node::next is allowed to be nullptr
    next = nextNode;
}

ItemType Node::GetItem()
{
    ItemType itemToGet;
    if (item != nullptr)
    {
        itemToGet = *item;
    }
    else
    {
        itemToGet = ItemType();
    }
    return itemToGet;
}

Node* Node::Next()
{
    // Does not check for nulltr
    // Node::next is allowed to be nullptr
    return next;
}