#include <iostream>
#include "AnyType.h"
#include "Exception.h"

int main()
{
    AnyType anyType = 2;
    anyType = 125.55;
    anyType = true;
    AnyType anyType2 = anyType;
    anyType = 123.33;

    try
    {
        //anyType.Swap(anyType2);
        //char a = anyType2.ToDouble();
        std::cout << anyType.ToDouble() << " " << anyType.GetType() << std::endl;
        std::cout << anyType2.ToBool() << " " << anyType2.GetType() << std::endl;
    }
    catch (const Exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }


    return 0;
}
