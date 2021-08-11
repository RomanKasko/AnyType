#include "Exception.h"
Exception::Exception(char *errorTypeMsg)
{
    msg += errorTypeMsg;
}

Exception::Exception(std::string &firstType, std::string &secondType)
{
    msg += firstType + " to " + secondType;
}

const char* Exception::what() const noexcept
{
    return msg.c_str();
}
