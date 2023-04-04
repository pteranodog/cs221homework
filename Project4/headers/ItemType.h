// ItemType.h : This file contains the declaration of the ItemType class 
// for Program 4 
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
        string author;

    public:
        ItemType();
        ItemType(int newStockNum, string newTitle, string newAuthor);
        ~ItemType();
        bool operator < (const ItemType& itemToCompare);
        bool operator > (const ItemType& itemToCompare);
        bool operator == (const ItemType& itemToCompare);
        int GetData();
        int GetData(string &returnTitle, string &returnAuthor);
        void SetData(int newStockNum, string newTitle, string newAuthor);
        void PrintInfo();
};