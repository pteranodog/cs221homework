// ItemType.cpp : This file contains the implementation of the ItemType class 
// for Program 2 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach
#include "ItemType.h"

ItemType::ItemType()
{
    data = 0;
}

ItemType::ItemType(int newValue)
{
    data = newValue;
}

ItemType::~ItemType()
{
    // Nothing is needed in a destructor if the class has no dynamic memory
}

comparison ItemType::Compare(int intToCompare)
{
    comparison result;
    if (intToCompare == data)
    {
        result = EQUAL;
    }
    else if (intToCompare < data)
    {
        result = LESS;
    }
    else
    {
        result = GREATER;
    }
    return result;
}

int ItemType::GetData()
{
    return data;
}

void ItemType::SetData(int dataToSet)
{
    data = dataToSet;
}