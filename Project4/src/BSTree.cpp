// BSTree.h : This file contains the implementation of the BSTree class 
// for Program 4 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach

#include "BSTree.h"
#include "ItemType.h"
#include <fstream>
#include <iostream>

using namespace std;

BSTree::BSTree()
{
    root = nullptr;
    curPos = nullptr;
    count = 0;
    maxNodes = 500;
    cout << "\033[1m\033[92mHello! This is \033[96mDrew Early's \033[95mProgram 4 \033[92mfrom \033[93mCS221-02! \033[92mHave fun!\033[0m" << endl;
}

BSTree::BSTree(const BSTree &BSTreeToCopy)
{
    root = nullptr;
    curPos = nullptr;
    count = 0;
    maxNodes = 500;

    copyTree(root, BSTreeToCopy.root);
}

void BSTree::copyTree(TreeNode* &copy, const TreeNode* originalTree)
{
    if (originalTree == nullptr)
    {
        copy = nullptr;
    }
    else
    {
        copy = new TreeNode;
        copy->info = originalTree->info;
        copyTree(copy->left, originalTree->left);
        copyTree(copy->right, originalTree->right);
    }
}

BSTree::~BSTree()
{
    MakeEmpty();
}

bool BSTree::placeItemOnTree(TreeNode* &tree, ItemType newItem)
{
    if (tree == nullptr)
    {
        tree = new TreeNode;
        tree->info = newItem;
        tree->left = nullptr;
        tree->right = nullptr;
        string title;
        string author;
        newItem.GetData(title, author);
        cout << "Added " << title << endl;
        count++;
        return true;
    }
    else if (newItem < tree->info)
    {
        return placeItemOnTree(tree->left, newItem);
    }
    else if (newItem > tree->info)
    {
        return placeItemOnTree(tree->right, newItem);
    }
    else
    {
        return false;
        cout << "Item already in tree" << endl;
    }
}

bool BSTree::PutItem(ItemType newItem)
{
    if (count < maxNodes)
    {
        return placeItemOnTree(root, newItem);
    }
    else
    {
        return false;
    }
}

ItemType BSTree::getItemFromTree(TreeNode* tree, ItemType itemToGet)
{
    if (tree == nullptr)
    {
        return ItemType();
    }
    cout << tree->info.GetData() << endl;
    if (itemToGet < tree->info)
    {
        return getItemFromTree(tree->left, itemToGet);
    }
    if (itemToGet > tree->info)
    {
        return getItemFromTree(tree->right, itemToGet);
    }
    return tree->info;
}

ItemType BSTree::GetItem(ItemType itemToGet, bool &found)
{
    ItemType item;
    cout << "Searching...";
    item = getItemFromTree(root, itemToGet);
    if (item == ItemType())
    {
        found = false;
        cout << "Not found." << endl;
    }
    else
    {
        found = true;
        cout << "Found!" << endl;
    }
    return item;
}

bool BSTree::deleteItemFromTree(TreeNode* &tree, ItemType itemToDelete)
{
    if (tree == nullptr)
    {
        return false;
    }
    else if (itemToDelete < tree->info)
    {
        return deleteItemFromTree(tree->left, itemToDelete);
    }
    else if (itemToDelete > tree->info)
    {
        return deleteItemFromTree(tree->right, itemToDelete);
    }
    else
    {
        return deleteRoot(tree);
    }
}

bool BSTree::deleteRoot(TreeNode* &tree)
{
    if (tree->left == nullptr && tree->right == nullptr)
    {
        delete tree;
        tree = nullptr;
        count--;
        return true;
    }
    else if (tree->left == nullptr)
    {
        TreeNode* treeToDelete = tree;
        tree = tree->right;
        delete treeToDelete;
        count--;
        return true;
    }
    else if (tree->right == nullptr)
    {
        TreeNode* treeToDelete = tree;
        tree = tree->left;
        delete treeToDelete;
        count--;
        return true;
    }
    else
    {
        TreeNode* smallestOnRight = tree->right;
        while (smallestOnRight->left != nullptr)
        {
            smallestOnRight = smallestOnRight->left;
        }
        tree->info = smallestOnRight->info;
        return deleteItemFromTree(tree->right, smallestOnRight->info);
    }
}

bool BSTree::DeleteItem(ItemType itemToDelete)
{
    bool success = deleteItemFromTree(root, itemToDelete);
    if (success)
    {
        string title;
        string author;
        itemToDelete.GetData(title, author);
        cout << "Deleted " << title << endl;
    }
    else
    {
        cout << "Item to delete was not found" << endl;
    }
    return success;
}

ItemType BSTree::ResetTree()
{
    curPos = root;
    if (curPos == nullptr)
    {
        return ItemType();
    }
    else
    {
        while (curPos->left != nullptr)
        {
            curPos = curPos->left;
        }
        return curPos->info;
    }
}

void BSTree::makeTreeEmpty(TreeNode* &tree)
{
    if (tree != nullptr)
    {
        makeTreeEmpty(tree->left);
        makeTreeEmpty(tree->right);
        delete tree;
        tree = nullptr;
    }
}

void BSTree::MakeEmpty()
{
    makeTreeEmpty(root);
    count = 0;
}

void BSTree::printTree(TreeNode* tree, ofstream &outputFile)
{
    if (tree != nullptr)
    {
        printTree(tree->left, outputFile);
        tree->info.PrintInfo();
        ItemType item = tree->info;
        string title;
        string author;
        outputFile << item.GetData(title, author) << ", " << title << ", " << author << endl;
        printTree(tree->right, outputFile);
    }
}

void BSTree::PrintTree(ofstream &outputFile)
{
    printTree(root, outputFile);
}

ItemType BSTree::GetNext()
{
    if (curPos == nullptr)
    {
        return ItemType();
    }
    if (curPos->right != nullptr)
    {
        curPos = curPos->right;
        while (curPos->left != nullptr)
        {
            curPos = curPos->left;
        }
        return curPos->info;
    }
    TreeNode* possibleNext = nullptr;
    TreeNode* currentSearchPos = root;
    while (currentSearchPos != curPos)
    {
        if (curPos->info < currentSearchPos->info)
        {
            possibleNext = currentSearchPos;
            currentSearchPos = currentSearchPos->left;
        }
        else
        {
            currentSearchPos = currentSearchPos->right;
        }
    }
    if (possibleNext == nullptr)
    {
        return ItemType();
    }
    else
    {
        curPos = possibleNext;
        return curPos->info;
    }
}

int BSTree::countNodes(TreeNode* tree)
{
    if (tree == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + countNodes(tree->left) + countNodes(tree->right);
    }
}

int BSTree::GetCount()
{
    return countNodes(root);
}