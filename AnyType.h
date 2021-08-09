#ifndef ANYTYPE_ANYTYPE_H
#define ANYTYPE_ANYTYPE_H
#include <iostream>
#include <memory>

class AnyType
{
private:
    union
    {
        bool boolType;
        char charType;
        int intType;
        unsigned unsignedType;
        float floatType;
        double doubleType;
    }singleValue;

    enum class DataType
    {
        NONE,
        BOOL,
        CHAR,
        INT,
        UNSIGNED,
        FLOAT,
        DOUBLE
    }type;

public:
    AnyType();
    AnyType(bool data);
    AnyType(char data);
    AnyType(int data);
    AnyType(unsigned data);
    AnyType(float data);
    AnyType(double data);
    AnyType(const AnyType &other);

    bool ToBool();
    char ToChar();
    int ToInt();
    unsigned ToUnsigned();
    float ToFloat();
    double ToDouble();

    AnyType& operator= (const bool &data);
    AnyType& operator= (const char &data);
    AnyType& operator= (const int &data);
    AnyType& operator= (const unsigned &data);
    AnyType& operator= (const float &data);
    AnyType& operator= (const double &data);

    void DestroyObject();
    void Swap(AnyType& data);
    std::string GetType();
};

#endif //ANYTYPE_ANYTYPE_H