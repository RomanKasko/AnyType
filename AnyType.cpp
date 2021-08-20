#include "AnyType.h"
#include "Exception.h"

AnyType::AnyType()
{
    type = NONE;
}

AnyType::AnyType(AnyType &other)
{
    this->singleValue = other.singleValue;
    this->type = other.type;
}

AnyType::AnyType(AnyType &&other)
{
    this->singleValue = std::move(other.singleValue);
    this->type = std::move(other.type);
}

AnyType& AnyType::operator= (AnyType& other)
{
    this->singleValue = other.singleValue;
    this->type = other.type;
    return *this;
}

AnyType& AnyType::operator= (AnyType&& other)
{
    this->singleValue = std::move(other.singleValue);
    this->type = std::move(other.type);
    return *this;
}

bool AnyType::ToBool()
{
    CheckType(BOOL);
    return singleValue.boolType;
}

char AnyType::ToChar()
{
    CheckType(CHAR);
    return singleValue.charType;
}

int AnyType::ToInt()
{
    CheckType(INT);
    return singleValue.intType;
}

unsigned AnyType::ToUnsigned()
{
    CheckType(UNSIGNED);
    return singleValue.unsignedType;
}

float AnyType::ToFloat()
{
    CheckType(FLOAT);
    return singleValue.floatType;
}

double AnyType::ToDouble()
{
    CheckType(DOUBLE);
    return singleValue.doubleType;
}

void AnyType::CheckType(const DataType dataType)
{
    if(this->type != dataType)
    {
        throw (Exception(Types[this->type],Types[dataType]));
    }
}

const std::string AnyType::GetType() noexcept
{
    return Types[this->type];
}

void AnyType::DestroyObject()
{
    this->type = NONE;
}

void AnyType::Swap(AnyType& data)
{
    AnyType tmp = *this;
    *this = data;
    data = tmp;
}