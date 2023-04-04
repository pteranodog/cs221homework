// ItemType.h : This file contains the implementation of the ItemType class 
// for Program 4 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach

#include "ItemType.h"
#include <string>
#include <iostream>

using namespace std;

ItemType::ItemType()
{
    stockNum = 0;
    title = "none";
    author = "none";
}

ItemType::ItemType(int newStockNum, string newTitle, string newAuthor)
{
    stockNum = newStockNum;
    title = newTitle;
    author = newAuthor;
}

ItemType::~ItemType()
{
    // Destructor not required when all members are static
}

bool ItemType::operator < (const ItemType& itemToCompare)
{
    if (title.compare(itemToCompare.title) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ItemType::operator > (const ItemType& itemToCompare)
{
    if (title.compare(itemToCompare.title) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ItemType::operator == (const ItemType& itemToCompare)
{
    if (title.compare(itemToCompare.title) == 0)
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

int ItemType::GetData(string &returnTitle, string &returnAuthor)
{
    returnTitle = title;
    returnAuthor = author;
    return stockNum;
}

void ItemType::SetData(int newStockNum, string newTitle, string newAuthor)
{
    stockNum = newStockNum;
    title = newTitle;
    author = newAuthor;
}

void ItemType::PrintInfo()
{
    cout << stockNum << "," << author << "," << title << endl;
}