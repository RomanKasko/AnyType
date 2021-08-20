#ifndef ANYTYPE_EXCEPTION_H
#define ANYTYPE_EXCEPTION_H
#include <iostream>

class Exception
{
private:
    std::string msg = "Failed! Non-type-safe cast from ";
public:
    Exception(const std::string &firstType,const std::string &secondType);
    const char* what() const;
};
#endif //ANYTYPE_EXCEPTION_H