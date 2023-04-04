// ItemType.cpp : This file contains the implementation of the ItemType class 
// for Program 3
//
// By Drew Early 
// for CS221-02 
// Mrs. Delugach

#include "ItemType.h"
#include <iostream>
#include <string>

ItemType::ItemType()
{
    stockNum = 0;
    title = "none";
}

ItemType::ItemType(int newStockNum, string newTitle)
{
    stockNum = newStockNum;
    title = newTitle;
}

ItemType::~ItemType()
{
    // Destructor not required when all members are static
}

bool ItemType::operator < (ItemType itemToCompare)
{
    if (stockNum < itemToCompare.stockNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ItemType::operator > (ItemType itemToCompare)
{
    if (stockNum > itemToCompare.stockNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ItemType::operator == (ItemType itemToCompare)
{
    if (stockNum == itemToCompare.stockNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int ItemType::GetData()
{
    return stockNum;
}

int ItemType::GetData(string &returnTitle)
{
    returnTitle = title;
    return stockNum;
}

void ItemType::SetData(int newStockNum, string newTitle)
{
    stockNum = newStockNum;
    title = newTitle;
}