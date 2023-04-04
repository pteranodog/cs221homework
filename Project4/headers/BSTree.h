// BSTree.h : This file contains the declaration of the BSTree class 
// for Program 4 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach 

#pragma once
#include "ItemType.h"
#include <fstream>

struct TreeNode
{
    ItemType info;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

using namespace std;

class BSTree
{
    private:
        TreeNode *root;
        TreeNode *curPos;
        int count;
        int maxNodes;

        bool placeItemOnTree(TreeNode* &tree, ItemType newItem);
        ItemType getItemFromTree(TreeNode* tree, ItemType itemToGet);
        bool deleteItemFromTree(TreeNode* &tree, ItemType itemToDelete);
        bool deleteRoot(TreeNode* &tree);
        void makeTreeEmpty(TreeNode* &tree);
        void printTree(TreeNode* tree, ofstream &outFile);
        int countNodes(TreeNode* tree);
        void copyTree(TreeNode* &copy, const TreeNode* originalTree);

    public:
        BSTree();
        BSTree(const BSTree &BSTreeToCopy);
        ~BSTree();
        bool PutItem(ItemType newItem);
        ItemType GetItem(ItemType itemToGet, bool &found);
        bool DeleteItem(ItemType itemToDelete);
        ItemType ResetTree();
        void MakeEmpty();
        void PrintTree(ofstream &outFile);
        ItemType GetNext();
        int GetCount();
};