#ifndef ANYTYPE_ANYTYPE_H
#define ANYTYPE_ANYTYPE_H
#include <iostream>
#include <map>

static std::map<int,std::string> Types =
        {
                {0,"none"},
                {1,"bool"},
                {2,"char"},
                {3,"int"},
                {4,"unsigned"},
                {5,"float"},
                {6,"double"}
        };

enum DataType
{
    NONE,
    BOOL,
    CHAR,
    INT,
    UNSIGNED,
    FLOAT,
    DOUBLE
};

union SingleValue
{
    bool boolType;
    char charType;
    int intType;
    unsigned unsignedType;
    float floatType;
    double doubleType;
};

class AnyType
{
private:
    SingleValue singleValue;
    int type;

public:
    AnyType();
    AnyType(AnyType &other);
    AnyType(AnyType &&other);
    template<typename T> AnyType(const T& data);

    bool ToBool();
    char ToChar();
    int ToInt();
    unsigned ToUnsigned();
    float ToFloat();
    double ToDouble();

    template<typename T> AnyType& operator=(const T &data);
    AnyType& operator= (AnyType& other);
    AnyType& operator= (AnyType&& other);

    template <typename T> bool IsAvailableType(const T &data);
    void CheckType(const DataType dataType);
    std::string GetType();
    void Swap(AnyType& data);
    void DestroyObject();
};

template<typename T>
AnyType::AnyType(const T& data)
{
    this->operator=(data);
}

template<typename T>
AnyType& AnyType::operator=(const T &data)
{
    if(!IsAvailableType(data))
    {
        throw "Can't assign invalid type \n";
    }
    std::string typeName = typeid(data).name();
    if(typeName == typeid(bool).name())
    {
        this->singleValue.boolType = data;
        this->type = BOOL;
    }
    else if(typeName == typeid(char).name())
    {
        this->singleValue.charType = (char) data;
        this->type = CHAR;
    }
    else if(typeName == typeid(int).name())
    {
        this->singleValue.intType = data;
        this->type = INT;
    }
    else if(typeName == typeid(unsigned).name())
    {
        this->singleValue.unsignedType = data;
        this->type = UNSIGNED;
    }
    else if(typeName == typeid(float).name())
    {
        this->singleValue.floatType = data;
        this->type = FLOAT;
    }
    else if(typeName == typeid(double).name())
    {
        this->singleValue.doubleType = data;
        this->type = DOUBLE;
    }
    return *this;
}

template<typename T>
bool AnyType::IsAvailableType(const T &data)
{
    std::string typeName = typeid(data).name();
    for(int i = 0; i < Types.size(); ++i)
    {
        if(typeName == Types[i])
        {
            return true;
        }
    }
    return false;
}
#endif //ANYTYPE_ANYTYPE_H