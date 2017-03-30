#ifndef ANYTYPE_H
#define ANYTYPE_H

#include <bitset>

namespace SpaceOfTypes {

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ulongLong;

typedef union{

    bool _bool;
    char _char;
    uchar _uchar;
    wchar_t _wchar_t;
    short _short;
    ushort _ushort;
    int _int;
    uint _uint;
    long _long;
    ulong _ulong;
    long long _longLong;
    ulongLong _ulongLong;
    float _float;
    double _double;
    long double _longDouble;

} Type;

enum class TypeName{

    BOOL = 0, CHAR, UCHAR, WCHAR_T, SHORT, USHORT, INT, UINT,
    LONG, ULONG, LONG_LONG, ULONG_LONG, FLOAT, DOUBLE, LONG_DOUBLE
};

enum class ValueSign{

    NEGATIVE = -1, POSITIVE
};

class AnyType
{
public:

    /**
     * @brief AnyType - deleted c-tor as we dont need it
     */
    AnyType() = delete;

    /**
      * @brief AnyType - default d-tor
      */
    ~AnyType();

    /**
     * @brief AnyType - copy c-tor
     * @param copy - instance of another object which will be coppied
     */
    AnyType(const AnyType &copy);

    /**
     * @brief AnyType - move c-tor
     * @param move - instance of another object which will be moved
     */
    AnyType(AnyType &&move);

    /**
     * @brief AnyType - paramater c-tor which will host our data
     * @param value - type of stored data
     */
    AnyType(bool value);

    AnyType(char value);
    AnyType(uchar value);
    AnyType(wchar_t value);

    AnyType(short value);
    AnyType(ushort value);

    AnyType(int value);
    AnyType(uint value);

    AnyType(long value);
    AnyType(ulong value);

    AnyType(long long value);
    AnyType(ulongLong value);

    AnyType(float value);

    AnyType(double value);
    AnyType(long double value);

    /**
     * @brief operator = overloaded to our needs assignment operator
     * @param assign - instance of another object which will be assigned
     * @return - pointer to this object
     */
    AnyType &operator = (const AnyType &assign);

    /**
     * @brief operator = overloaded to our needs move assignment operator
     * @param moveAssign - instance of another object which will be moved
     * @return - pointer to this object
     */
    AnyType &operator = (AnyType &&moveAssign);

    /**
     * @brief toType - method converts one type to another
     * as for now it converts only positive numbers
     * @return - converted type
     */
    bool toBool();

    short toShort();
    ushort toUshort();

    int toInt();
    uint toUint();

    long toLong();
    ulong toUlong();

    long long toLongLong();
    ulongLong toUlongLong();

    float toFloat();

    double toDouble();
    long double toLongDouble();

    /**
     * @brief getTypeData - if needed type is the same as we use to get it return that type
     * in other ways it throwing the bad cast exception
     * @return - stored data
     */
    bool getBoolData();

    char getCharData();
    uchar getUcharData();
    wchar_t getWchar_tData();

    short getShortData();
    ushort getUshortData();

    int getIntData();
    uint getUintData();

    long getLongData();
    ulong getUlongData();

    long long getLongLongData();
    ulongLong getUlongLongData();

    float getFloatData();

    double getDoubleData();
    long double getLongDoubleData();

    /**
     * @brief printTypeName - method prints the type of variable
     */
    void printTypeName();


private:

    /**
     * @brief setBitsAccordingToType - set the bits according to the last stored type
     */
    void setBitsAccordingToType();

    /**
     * @brief _type - union which holds types
     */
    Type _type;

    /**
     * @brief _typeName - enum class which holds type names
     */
    TypeName _typeName;


    /**
     * @brief _valueSign - enum class which holds value sign
     */
    ValueSign _valueSign;

    /**
     * @brief bits - array of bits which is used to convert one type to another
     * size accordnig to the biggest size(long double, 8bytes)
     */
    std::bitset<64> _bits;

};

}

#endif // ANYTYPE_H
