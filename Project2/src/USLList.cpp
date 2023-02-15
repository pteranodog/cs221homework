// USLlist.cpp : This file contains the implemetation of the USLList class 
// for Program 2 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach

USLList::USLList()
{
    head = nullPtr;
    curPos = nullPtr;
    length = 0;
}

USLList::~USLList()
{
    MakeEmpty();
}

USLList::PutItem(ItemType *newItem)
{
    bool successful = false
    if (newItem != nullPtr)
    {
        bool itemInList;
        GetItem(newItem, itemInList)
        if (itemInList)
        {
            newItem->SetNext(head);
            head = newItem;
            length++;
            successful = true;
        }
    }
    return successful;
}

USLList::GetItem(ItemType *itemToGet, bool &found)
{

}

USLList::DeleteItem(ItemType *itemToDelete)
{

}

USLList::ResetList()
{
    *curPos = head;
}

USLList::MakeEmpty()
{

}

USLList::GetNext()
{
    if (head != nullPtr)
    {
        
    }
}