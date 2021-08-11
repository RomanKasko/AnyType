#include <iostream>
#include "AnyType.h"
#include "Exception.h"

int main()
{
    AnyType anyType = 123;
    AnyType anyType2;

    anyType = 12.2f;
    std::cout << anyType.ToFloat() << " " << anyType.GetType() << std::endl;

    try
    {
        anyType2 = 999999999999999999;
    }
    catch (const char* ex)
    {
        std::cerr << ex;
    }

    anyType2 = 'A';
    std::cout << anyType.ToFloat() << " " << anyType.GetType() << std::endl;
    std::cout << anyType2.ToChar() << " " << anyType2.GetType() << std::endl;
    anyType.Swap(anyType2);
    std::cout << anyType.ToChar() << " " << anyType.GetType() << std::endl;
    std::cout << anyType2.ToFloat() << " " << anyType2.GetType() << std::endl;

    try
    {
        std::cout << anyType.ToInt() << " " << anyType.GetType() << std::endl;
    }
    catch (const Exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}