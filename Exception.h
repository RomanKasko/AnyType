#ifndef ANYTYPE_EXCEPTION_H
#define ANYTYPE_EXCEPTION_H
#include <iostream>

class Exception
{
private:
    std::string msg = "Failed! Non-type-safe access to ";
public:
    explicit Exception(char* errorTypeMsg);
    const char* what() const noexcept;
};
#endif //ANYTYPE_EXCEPTION_H