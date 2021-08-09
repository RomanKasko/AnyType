#include "Exception.h"
Exception::Exception(char *errorTypeMsg)
{
    msg += errorTypeMsg;
}

const char* Exception::what() const noexcept
{
    return msg.c_str();
}
