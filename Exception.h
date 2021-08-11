#ifndef ANYTYPE_EXCEPTION_H
#define ANYTYPE_EXCEPTION_H
#include <iostream>

class Exception
{
private:
    std::string msg = "Failed! Non-type-safe cast from ";
public:
    explicit Exception() =default;
    explicit Exception(char* errorTypeMsg);
    explicit Exception(std::string &firstType, std::string &secondType);
    const char* what() const noexcept;
};
#endif //ANYTYPE_EXCEPTION_H