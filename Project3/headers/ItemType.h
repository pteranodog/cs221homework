// ItemType.h : This file contains the declaration of the ItemType class 
// for Program 3 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach 

#pragma once
#include <string>

using namespace std;

class ItemType
{
private:
    int stockNum;
    string title;

public:
    ItemType();
    ItemType(int newStockNum, string newTitle);
    ~ItemType();
    bool operator < (ItemType itemToCompare);
    bool operator > (ItemType itemToCompare);
    bool operator == (ItemType itemToCompare);
    int GetData();
    int GetData(string &returnTitle);
    void SetData(int newStockNum, string newTitle);
};