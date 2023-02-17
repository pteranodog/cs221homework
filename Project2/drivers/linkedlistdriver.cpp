#include "ItemType.h"
#include "Node.h"
#include "USLList.h"
#include <iostream>

int main()
{
    ItemType item3 = ItemType(7);
    USLList *list = new USLList;
    list->PutItem(new ItemType(5));
    list->PutItem(new ItemType(2));
    list->PutItem(nullptr);
    list->PutItem(new ItemType(7));
    list->PutItem(new ItemType(1));
    list->PutItem(&item3);

    bool foundItemLol;
    ItemType* foundThisItem = list->GetItem(new ItemType(3), foundItemLol);

    bool foundItemLol2;
    ItemType* foundThisItem2 = list->GetItem(new ItemType(234), foundItemLol2);

    std::cout << list->GetLength() << std::endl;
    

    system("pause");
    return 0;
}