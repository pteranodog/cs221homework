// ItemType.cpp : This file contains the implementation of the ItemType class 
// for Program 2 
//  
// By Drew Early 
// for CS221-02 
// Mrs. Delugach

ItemType::ItemType()
{
    data = 0;
}

ItemType::ItemType(int newValue);
{
    data = newValue;
}

ItemType::~ItemType()
{
    // nothing here?
}

ItemType::Compare(int intToCompare)
{
    comparison result;
    if (intToCompare == data)
    {
        result = EQUAL
    }
    else if (intToCompare < data)
    {
        result = LESS
    }
    else
    {
        result = GREATER
    }
    return result;
}

ItemType::GetData();
{
    return data;
}

ItemType::SetData(int dataToSet)
{
    data = dataToSet;
}