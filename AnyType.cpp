#include "AnyType.h"
#include "Exception.h"

AnyType::AnyType()
{
    type = DataType::NONE;
}

AnyType::AnyType(bool data)
{
    singleValue.boolType = data;
    type = DataType::BOOL;
}

AnyType::AnyType(char data)
{
    singleValue.charType = data;
    type = DataType::CHAR;
}

AnyType::AnyType(int data)
{
    singleValue.intType = data;
    type = DataType::INT;
}

AnyType::AnyType(float data)
{
    singleValue.floatType = data;
    type = DataType::FLOAT;
}

AnyType::AnyType(double data)
{
    singleValue.doubleType = data;
    type = DataType::DOUBLE;
}

AnyType::AnyType(unsigned int data)
{
    singleValue.unsignedType = data;
    type = DataType::UNSIGNED;
}

AnyType::AnyType(const AnyType &other)
{
    this->type = other.type;
    this->singleValue = other.singleValue;
}

AnyType& AnyType::operator=(const bool &data)
{
    this->singleValue.boolType = data;
    this->type = DataType::BOOL;
    return *this;
}

AnyType& AnyType::operator=(const char &data)
{
    this->singleValue.charType = data;
    this->type = DataType::CHAR;
    return *this;
}

AnyType& AnyType::operator=(const int &data)
{
    this->singleValue.intType = data;
    this->type = DataType::INT;
    return *this;
}

AnyType& AnyType::operator=(const float &data)
{
    this->singleValue.floatType = data;
    this->type = DataType::FLOAT;
    return *this;
}

AnyType& AnyType::operator=(const double &data)
{
    this->singleValue.doubleType = data;
    this->type = DataType::DOUBLE;
    return *this;
}

AnyType& AnyType::operator=(const unsigned &data)
{
    this->singleValue.unsignedType = data;
    this->type = DataType::UNSIGNED;
    return *this;
}

bool AnyType::ToBool()
{
    if(this->type != DataType::BOOL)
    {
        throw Exception((char*)"bool");
    }
    return singleValue.boolType;
}

char AnyType::ToChar()
{
    if(this->type != DataType::CHAR)
    {
        throw Exception((char*)"char");
    }
    return singleValue.charType;
}

int AnyType::ToInt()
{
    if(this->type != DataType::INT)
    {
        throw Exception((char*)"int");
    }
    return singleValue.intType;
}

unsigned AnyType::ToUnsigned()
{
    if(this->type != DataType::UNSIGNED)
    {
        throw Exception((char*)"unsigned");
    }
    return singleValue.unsignedType;
}

float AnyType::ToFloat()
{
    if(this->type != DataType::FLOAT)
    {
        throw Exception((char*)"float");
    }
    return singleValue.floatType;
}

double AnyType::ToDouble()
{
    if(this->type != DataType::DOUBLE)
    {
        throw Exception((char*)"double");
    }
    return singleValue.doubleType;
}

std::string AnyType::GetType()
{
    switch(type)
    {
        case DataType::BOOL:
            return typeid(singleValue.boolType).name();
        case DataType::CHAR:
            return typeid(singleValue.charType).name();
        case DataType::INT:
            return typeid(singleValue.intType).name();
        case DataType::UNSIGNED:
            return typeid(singleValue.unsignedType).name();
        case DataType::FLOAT:
            return typeid(singleValue.floatType).name();
        case DataType::DOUBLE:
            return typeid(singleValue.doubleType).name();
        default:
            return "none";
    }
}

void AnyType::DestroyObject()
{
    this->type = DataType::NONE;
}

void AnyType::Swap(AnyType& data)
{
    if(this->type != data.type)
    {
        throw "Can't swap elements due to different types";
    }
    AnyType tmp = *this;
    *this = data;
    data = tmp;
}