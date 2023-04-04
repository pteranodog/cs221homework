// CS221Program4.cpp : This file contains the driver 
// for Program 4 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach 

#include "ItemType.h"
#include "BSTree.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    BSTree tree;

    ifstream inFile;
    inFile.open("BookList.csv");
    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1);
    }
    int lineNum = 0;
    while (!inFile.eof())
    {
        string line;
        getline(inFile, line);
        if (line.length() > 0)
        {
            try
            {
                lineNum++;
                int stockNum = stoi(line.substr(0, line.find(",")));
                line = line.substr(line.find(",") + 1);
                string author = line.substr(0, line.find(","));
                line = line.substr(line.find(",") + 1);
                string title = line;
                if (title[0]=='"' && title[title.length()-1]!='"')
                {
                    title = title.substr(1, title.length() - 1);
                }
                else if (title[0] == '"' && title[title.length() - 1] == '"')
                {
                    title = title.substr(1, title.length() - 2);
                }
                ItemType item(stockNum, title, author);
                tree.PutItem(item);
            }
            catch (exception e)
            {
                cout << "\033[91mError reading line " << lineNum << "\033[0m" << endl;
            }
        }
        else
        {
            lineNum++;
            cout << "\033[93mLine " << lineNum << " is blank\033[0m" << endl;
        }
    }
    inFile.close();

    ofstream outFile;
    outFile.open("BooksSorted.csv");
    tree.PrintTree(outFile);
    outFile.close();

    bool done = false;
    while (!done)
    {
        cout << "1. Add item" << endl;
        cout << "2. Delete item" << endl;
        cout << "3. Get item" << endl;
        cout << "4. Print tree" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        
        switch (choice)
        {
        case 1:
        {
            cout << "Enter stock number: ";
            int stockNum;
            cin >> stockNum;
            cin.ignore();
            cout << "Enter author: ";
            string author;
            getline(cin, author);
            cout << "Enter title: ";
            string title;
            getline(cin, title);
            ItemType item(stockNum, title, author);
            tree.PutItem(item);
            break;
        }
        case 2:
        {
            cout << "Enter stock number: ";
            int stockNum;
            cin >> stockNum;
            cin.ignore();
            cout << "Enter author: ";
            string author;
            getline(cin, author);
            cout << "Enter title: ";
            string title;
            getline(cin, title);
            ItemType item(stockNum, title, author);
            tree.DeleteItem(item);
            break;
        }
        case 3:
        {
            cout << "Enter stock number: ";
            int stockNum;
            cin >> stockNum;
            cin.ignore();
            cout << "Enter author: ";
            string author;
            getline(cin, author);
            cout << "Enter title: ";
            string title;
            getline(cin, title);
            ItemType item(stockNum, title, author);
            bool found;
            tree.GetItem(item, found);
            break;
        }
        case 4:
        {
            ofstream outFile2;
            outFile2.open("UserPrintTreeOutput.csv");
            tree.PrintTree(outFile2);
            outFile2.close();
            break;
        }
        case 5:
            done = true;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    tree.MakeEmpty();
    outFile.close();
    system("pause");
    return 0;
}