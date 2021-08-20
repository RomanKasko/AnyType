#include "Exception.h"
Exception::Exception(const std::string &firstType,const std::string &secondType)
{
    msg += firstType + " to " + secondType;
}

const char* Exception::what() const
{
    return msg.c_str();
}
