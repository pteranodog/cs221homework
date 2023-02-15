// Node.cpp : This file contains the implemetation of the Node class 
// for Program 2 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach

Node::Node()
{
    item = new ItemType;
    next = nullPtr;
}

Node::Node(ItemType newItem)
{
    item = &newItem;
    next = nullPtr;
}

Node::~Node()
{
    delete item;
    delete next;
    item = nullPtr;
    next = nullPtr;
}

Node::SetNext(Node *nextNode)
{
    next = nextNode;
}

Node::GetItem()
{
    return *item;
}

Node::Next()
{
    return next;
}