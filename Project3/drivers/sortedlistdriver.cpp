#include "ItemType.h"
#include "SortedList.h"
#include <iostream>

int main()
{
    
    SortedList list(10);
    ItemType item1(1, "one");
    ItemType item2(2, "two");
    ItemType item3(3, "three");
    ItemType item4(4, "four");
    ItemType item5(5, "five");
    ItemType item6(6, "six");
    ItemType item7(7, "seven");
    ItemType item8(8, "eight");
    ItemType item9(9, "nine");
    ItemType item10(10, "ten");
    ItemType item11(11, "eleven");
    list.PutItem(item2);
    list.PutItem(item5);
    list.PutItem(item3);
    list.PutItem(item6);
    list.PutItem(item7);
    list.PutItem(item4);
    list.PutItem(item1);
    list.PutItem(item2);
    list.PutItem(item7);
    list.PutItem(item9);
    list.PutItem(item8);
    list.PutItem(item10);
    list.PutItem(item11);
    list.PrintList();
    list.DeleteItem(item11);
    list.DeleteItem(item1);
    list.DeleteItem(item5);
    list.DeleteItem(item9);
    list.PrintList();
    cout << "List length: " << list.GetLength() << endl;
    cout << "First item: " << list.ResetList().GetData() << endl;
    ItemType nextItem = list.GetNext();
    cout << "Next item: " << nextItem.GetData() << endl;    
    list.PrintList();

    SortedList list2 = list;
    list2.PrintList();

    list.MakeEmpty();
    list.PrintList();

    bool found = false;
    cout << list2.GetItem(item1, found).GetData() << endl;
    cout << list2.GetItem(item11, found).GetData() << endl;

    list2.DeleteItem(item2);
    list2.DeleteItem(item5);
    list2.DeleteItem(item3);
    list2.DeleteItem(item6);
    list2.DeleteItem(item7);
    list2.DeleteItem(item4);
    list2.DeleteItem(item1);
    list2.DeleteItem(item2);
    list2.DeleteItem(item7);
    list2.DeleteItem(item9);
    list2.DeleteItem(item8);
    list2.DeleteItem(item10);
    list2.DeleteItem(item11);

    cout << list2.ResetList().GetData() << endl;
    cout << list2.GetNext().GetData() << endl;
    list2.PrintList();
    list2.GetItem(item1, found);
    

    system("pause");
    return 0;
}