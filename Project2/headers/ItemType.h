// ItemType.h : This file contains the declaration of the ItemType class 
// for Program 2 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach 

#pragma once

enum comparison
{
    LESS,
    EQUAL,
    GREATER
};

class ItemType
{
private:
    int data;

public:
    ItemType();
    ItemType(int newValue);
    ~ItemType();
    comparison Compare(int intToCompare);
    int GetData();
    void SetData();
};