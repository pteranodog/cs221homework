#include "Sort.h"
#include <iostream>

using namespace std;

Sort::Sort()
{
    // Does this actually run every time a subclass is created?
    // Didn't know that happened but it's cool.
}

Sort::~Sort()
{
    // destructor unneeded for class with no dynamic memory
}

void Sort::SetShowWork(bool show)
{
    showWork = show;
}

bool Sort::GetShowWork()
{
    return showWork;
}