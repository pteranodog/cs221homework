#include "ItemType.h"
#include "Node.h"
#include "USLList.h"
#include <string>
#include <iostream>

void outputTestInt(int expected, int actual)
{
    if (expected == actual)
    {
        std::cout << "\033[32mPASS\033[0m\t";
        std::cout << "Expected: " << expected << "\tActual: " << actual << std::endl;
    }
    else
    {
        std::cout << "\033[31mFAIL ->\033[0m\t";
        std::cout << "Expected: " << expected << "\tActual: \033[31m" << actual << "\033[0m" << std::endl;
    }
}

void outputTestFloat(float expected, float actual)
{
    if (abs(expected - actual) <= 0.01)
    {
        std::cout << "\033[32mPASS\033[0m\t";
        std::cout << "Expected: " << expected << "\tActual: " << actual << std::endl;
    }
    else
    {
        std::cout << "\033[31mFAIL ->\t\033[0m";
        std::cout << "Expected: " << expected << "\tActual: \033[31m" << actual << "\033[0m" << std::endl;
    }
}

void outputTestString(std::string expected, std::string actual)
{
    if (expected == actual)
    {
        std::cout << "\033[32mPASS\033[0m\t";
        std::cout << "Expected: " << expected << "\tActual: " << actual << std::endl;
    }
    else
    {
        std::cout << "\033[31mFAIL ->\033[0m\t";
        std::cout << "Expected: " << expected << "\tActual: \033[31m" << actual << "\033[0m" << std::endl;
    }
}

int main()
{

    system("pause");
    return 0;
}