#include "ItemType.h"
#include "Node.h"
#include "USLList.h"
#include <iostream>

int main()
{
    ItemType item3 = ItemType(3);
    USLList list;
    list.PutItem(new ItemType(5));
    list.PutItem(new ItemType(2));
    list.PutItem(new ItemType(7));
    list.PutItem(new ItemType(1));
    list.PutItem(&item3);
    std::cout << list.GetLength() << std::endl;
    list.MakeEmpty();
    

    system("pause");
    return 0;
}