#include "anytype.h"

#include <memory>
#include <iostream>
#include <bitset>

namespace SpaceOfTypes {

AnyType::AnyType(const AnyType &copy)
    : _type(copy._type),
      _typeName(copy._typeName),
      _valueSign(copy._valueSign)
{

    std::cout << "copy c-tor called" << std::endl;
}

AnyType::AnyType(AnyType &&move)
    : _type(std::move(move._type)),
      _typeName(std::move(move._typeName)),
      _valueSign(std::move(move._valueSign))
{

    std::cout << "move c-tor called" << std::endl;
}

AnyType::AnyType(bool value)
{
    _type._bool = value;
    _typeName = TypeName::BOOL;
    _valueSign = ValueSign::POSITIVE;

    std::cout << "bool ctor called, value: " << value << std::endl;
}

AnyType::AnyType(char value)
{
    _type._char = value;
    _typeName = TypeName::CHAR;

    if(value < 0)
        _valueSign = ValueSign::NEGATIVE;
    else
        _valueSign = ValueSign::POSITIVE;


    std::cout << "char ctor called, value: " << value << std::endl;
}

AnyType::AnyType(uchar value)
{
    _type._uchar = value;
    _typeName = TypeName::UCHAR;
    _valueSign = ValueSign::POSITIVE;

    std::cout << "uchar ctor called, value: " << value << std::endl;
}

AnyType::AnyType(wchar_t value)
{
    _type._wchar_t = value;
    _typeName = TypeName::WCHAR_T;
    _valueSign = ValueSign::POSITIVE;

    std::cout << "wchar_t ctor called, value: " << value << std::endl;
}

AnyType::AnyType(short value)
{
    _type._short = value;
    _typeName = TypeName::SHORT;

    if(value < 0)
        _valueSign = ValueSign::NEGATIVE;
    else
        _valueSign = ValueSign::POSITIVE;

    std::cout << "short ctor called, value: " << value << std::endl;
}

AnyType::AnyType(ushort value)
{
    _type._ushort = value;
    _typeName = TypeName::USHORT;
    _valueSign = ValueSign::POSITIVE;

    std::cout << "ushort ctor called, value: " << value << std::endl;
}

AnyType::AnyType(int value)
{
    _type._int = value;
    _typeName = TypeName::INT;

    if(value < 0)
        _valueSign = ValueSign::NEGATIVE;
    else
        _valueSign = ValueSign::POSITIVE;

    std::cout << "int ctor called, value: " << value << std::endl;
}

AnyType::AnyType(uint value)
{
    _type._uint = value;
    _typeName = TypeName::UINT;
    _valueSign = ValueSign::POSITIVE;

    std::cout << "uint ctor called, value: " << value << std::endl;
}

AnyType::AnyType(long value)
{
    _type._long = value;
    _typeName = TypeName::LONG;

    if(value < 0)
        _valueSign = ValueSign::NEGATIVE;
    else
        _valueSign = ValueSign::POSITIVE;

    std::cout << "long ctor called, value: " << value << std::endl;
}

AnyType::AnyType(ulong value)
{
    _type._ulong = value;
    _typeName = TypeName::ULONG;
    _valueSign = ValueSign::POSITIVE;

    std::cout << "ulong ctor called, value: " << value << std::endl;
}

AnyType::AnyType(long long value)
{
    _type._longLong = value;
    _typeName = TypeName::LONG_LONG;

    if(value < 0)
        _valueSign = ValueSign::NEGATIVE;
    else
        _valueSign = ValueSign::POSITIVE;

    std::cout << "long long ctor called, value: " << value << std::endl;
}

AnyType::AnyType(ulongLong value)
{
    _type._ulongLong = value;
    _typeName = TypeName::ULONG_LONG;
    _valueSign = ValueSign::POSITIVE;

    std::cout << "ulong long ctor called, value: " << value << std::endl;
}

AnyType::AnyType(float value)
{
    _type._float = value;
    _typeName = TypeName::FLOAT;

    if(value < 0)
        _valueSign = ValueSign::NEGATIVE;
    else
        _valueSign = ValueSign::POSITIVE;

    std::cout << "float ctor called, value: " << value << std::endl;
}

AnyType::AnyType(double value)
{
    _type._double = value;
    _typeName = TypeName::DOUBLE;

    if(value < 0)
        _valueSign = ValueSign::NEGATIVE;
    else
        _valueSign = ValueSign::POSITIVE;

    std::cout << "double ctor called, value: " << value << std::endl;
}

AnyType::AnyType(long double value)
{
    _type._longDouble = value;
    _typeName = TypeName::LONG_DOUBLE;

    if(value < 0)
        _valueSign = ValueSign::NEGATIVE;
    else
        _valueSign = ValueSign::POSITIVE;

    std::cout << "long double ctor called, value: " << value << std::endl;
}

AnyType &AnyType::operator =(const AnyType &assign)
{
    _type = assign._type;
    _typeName = assign._typeName;
    _valueSign = assign._valueSign;

    std::cout << "assigment operator called " << std::endl;

    return *this;
}

AnyType &AnyType::operator =(AnyType &&moveAssign)
{

    _type = std::move(moveAssign._type);
    _typeName = std::move(moveAssign._typeName);
    _valueSign = std::move(moveAssign._valueSign);

    std::cout << "move assigment operator called " << std::endl;

    return *this;
}

bool AnyType::toBool()
{
    if(_valueSign == ValueSign::POSITIVE){

        setBitsAccordingToType();

        _type._bool = static_cast<bool>(_bits.to_ulong());
        _typeName = TypeName::BOOL;

        return _type._bool;

    } else {

        std::cout << "can't covnert negative value to positive value " << std::endl;
        throw std::bad_cast();
    }
}

short AnyType::toShort()
{
    if(_valueSign == ValueSign::POSITIVE){

        setBitsAccordingToType();

        _type._short = static_cast<short>(_bits.to_ulong());
        _typeName = TypeName::SHORT;

        return _type._short;

    } else {

        std::cout << "can't covnert negative value to positive value " << std::endl;
        throw std::bad_cast();
    }
}

ushort AnyType::toUshort()
{
    if(_valueSign == ValueSign::POSITIVE){

        setBitsAccordingToType();

        _type._ushort = static_cast<ushort>(_bits.to_ulong());
        _typeName = TypeName::USHORT;

        return _type._ushort;

    } else {

        std::cout << "can't covnert negative value to positive value " << std::endl;
        throw std::bad_cast();
    }
}

int AnyType::toInt()
{
    if(_valueSign == ValueSign::POSITIVE){

        setBitsAccordingToType();

        _type._int = static_cast<int>(_bits.to_ulong());
        _typeName = TypeName::INT;

        return _type._int;

    } else {

        std::cout << "can't covnert negative value to positive value " << std::endl;
        throw std::bad_cast();
    }
}

uint AnyType::toUint()
{
    if(_valueSign == ValueSign::POSITIVE){

        setBitsAccordingToType();

        _type._uint = static_cast<uint>(_bits.to_ulong());
        _typeName = TypeName::UINT;

        return _type._uint;

    } else {

        std::cout << "can't covnert negative value to positive value " << std::endl;
        throw std::bad_cast();
    }
}

long AnyType::toLong()
{
    if(_valueSign == ValueSign::POSITIVE){

        setBitsAccordingToType();

        _type._long = static_cast<long>(_bits.to_ulong());
        _typeName = TypeName::LONG;

        return _type._long;

    } else {

        std::cout << "can't covnert negative value to positive value " << std::endl;
        throw std::bad_cast();
    }
}

ulong AnyType::toUlong()
{
    if(_valueSign == ValueSign::POSITIVE){

        setBitsAccordingToType();

        _type._ulong = static_cast<ulong>(_bits.to_ulong());
        _typeName = TypeName::ULONG;

        return _type._ulong;

    } else {

        std::cout << "can't covnert negative value to positive value " << std::endl;
        throw std::bad_cast();
    }
}

long long AnyType::toLongLong()
{
    if(_valueSign == ValueSign::POSITIVE){

        setBitsAccordingToType();

        _type._longLong = static_cast<long long>(_bits.to_ullong());
        _typeName = TypeName::LONG_LONG;

        return _type._longLong;

    } else {

        std::cout << "can't covnert negative value to positive value " << std::endl;
        throw std::bad_cast();
    }
}

ulongLong AnyType::toUlongLong()
{
    if(_valueSign == ValueSign::POSITIVE){

        setBitsAccordingToType();

        _type._ulongLong = static_cast<ulongLong>(_bits.to_ullong());
        _typeName = TypeName::ULONG_LONG;

        return _type._ulongLong;

    } else {

        std::cout << "can't covnert negative value to positive value " << std::endl;
        throw std::bad_cast();
    }
}

float AnyType::toFloat()
{
    if(_valueSign == ValueSign::POSITIVE){

        setBitsAccordingToType();

        _type._float = static_cast<float>(_bits.to_ulong());
        _typeName = TypeName::FLOAT;

        return _type._float;

    } else {

        std::cout << "can't covnert negative value to positive value " << std::endl;
        throw std::bad_cast();
    }
}

double AnyType::toDouble()
{
    if(_valueSign == ValueSign::POSITIVE){

        setBitsAccordingToType();

        _type._double = static_cast<double>(_bits.to_ullong());
        _typeName = TypeName::DOUBLE;

        return _type._double;

    } else {

        std::cout << "can't covnert negative value to positive value " << std::endl;
        throw std::bad_cast();
    }
}

long double AnyType::toLongDouble()
{
    if(_valueSign == ValueSign::POSITIVE){

        setBitsAccordingToType();

        _type._longDouble = static_cast<long double>(_bits.to_ullong());
        _typeName = TypeName::LONG_DOUBLE;

        return _type._longDouble;

    } else {

        std::cout << "can't covnert negative value to positive value " << std::endl;
        throw std::bad_cast();
    }
}

std::string AnyType::getTypeName()
{
    std::string typeInfo;

    switch (_typeName) {

    case TypeName::BOOL:

        typeInfo = "bool";
        break;

    case TypeName::CHAR:

        typeInfo = "char";
        break;

    case TypeName::UCHAR:

        typeInfo = "unsigned char";
        break;

    case TypeName::WCHAR_T:

        typeInfo = "wchar_t";
        break;

    case TypeName::SHORT:

        typeInfo = "short";
        break;

    case TypeName::USHORT:

        typeInfo = "unsigned short";
        break;

    case TypeName::INT:

        typeInfo = "int";
        break;

    case TypeName::UINT:

        typeInfo = "unsigned int";
        break;

    case TypeName::LONG:

        typeInfo = "long";
        break;

    case TypeName::ULONG:

        typeInfo = "unsigned long";
        break;

    case TypeName::LONG_LONG:

        typeInfo = "long long";
        break;

    case TypeName::ULONG_LONG:

        typeInfo = "unsigned long long";
        break;

    case TypeName::FLOAT:

        typeInfo = "float";
        break;

    case TypeName::DOUBLE:

        typeInfo = "double";
        break;

    case TypeName::LONG_DOUBLE:

        typeInfo = "long double";
        break;

    default:

        typeInfo = "uknown type";
        break;
    }

    return typeInfo;
}

bool AnyType::getBoolData() const
{
    if(_typeName == TypeName::BOOL){

        return _type._bool;
    }

    else {

        std::cout << "can't get data, type is not bool " << std::endl;
        throw std::bad_cast();
    }
}

char AnyType::getCharData() const
{
    if(_typeName == TypeName::CHAR){

        return _type._char;
    }

    else {

        std::cout << "can't get data, type is not char " << std::endl;
        throw std::bad_cast();
    }
}

uchar AnyType::getUcharData() const
{
    if(_typeName == TypeName::UCHAR){

        return _type._uchar;
    }

    else {

        std::cout << "can't get data, type is not unsigned char " << std::endl;
        throw std::bad_cast();
    }
}

wchar_t AnyType::getWchar_tData() const
{
    if(_typeName == TypeName::WCHAR_T){

        return _type._wchar_t;
    }

    else {

        std::cout << "can't get data, type is not wchar_t " << std::endl;
        throw std::bad_cast();
    }
}

short AnyType::getShortData() const
{
    if(_typeName == TypeName::SHORT){

        return _type._short;
    }

    else {

        std::cout << "can't get data, type is not short " << std::endl;
        throw std::bad_cast();
    }
}

ushort AnyType::getUshortData() const
{
    if(_typeName == TypeName::USHORT){

        return _type._ushort;
    }

    else {

        std::cout << "can't get data, type is not unsigned short " << std::endl;
        throw std::bad_cast();
    }
}

int AnyType::getIntData() const
{
    if(_typeName == TypeName::INT){

        return _type._int;
    }

    else {

        std::cout << "can't get data, type is not int " << std::endl;
        throw std::bad_cast();
    }
}

uint AnyType::getUintData() const
{
    if(_typeName == TypeName::UINT){

        return _type._uint;
    }

    else {

        std::cout << "can't get data, type is not unsigned int " << std::endl;
        throw std::bad_cast();
    }
}

long AnyType::getLongData() const
{
    if(_typeName == TypeName::LONG){

        return _type._long;
    }

    else {

        std::cout << "can't get data, type is not long " << std::endl;
        throw std::bad_cast();
    }
}

ulong AnyType::getUlongData() const
{
    if(_typeName == TypeName::ULONG){

        return _type._ulong;
    }

    else {

        std::cout << "can't get data, type is not unsigned long " << std::endl;
        throw std::bad_cast();
    }
}

long long AnyType::getLongLongData() const
{
    if(_typeName == TypeName::LONG_LONG){

        return _type._longLong;
    }

    else {

        std::cout << "can't get data, type is not long long " << std::endl;
        throw std::bad_cast();
    }
}

ulongLong AnyType::getUlongLongData() const
{
    if(_typeName == TypeName::ULONG_LONG){

        return _type._ulongLong;
    }

    else {

        std::cout << "can't get data, type is not unsigned long long" << std::endl;
        throw std::bad_cast();
    }
}

float AnyType::getFloatData() const
{
    if(_typeName == TypeName::FLOAT){

        return _type._float;
    }

    else {

        std::cout << "can't get data, type is not float " << std::endl;
        throw std::bad_cast();
    }
}

double AnyType::getDoubleData() const
{
    if(_typeName == TypeName::DOUBLE){

        return _type._double;
    }

    else {

        std::cout << "can't get data, type is not double " << std::endl;
        throw std::bad_cast();
    }
}

long double AnyType::getLongDoubleData() const
{
    if(_typeName == TypeName::LONG_DOUBLE){

        return _type._longDouble;
    }

    else {

        std::cout << "can't get data, type is not long double " << std::endl;
        throw std::bad_cast();
    }
}

void AnyType::setBitsAccordingToType()
{

    switch (_typeName) {

    case TypeName::BOOL:

        _bits = _type._bool;
        break;

    case TypeName::CHAR:

        _bits = _type._char;
        break;

    case TypeName::UCHAR:

        _bits = _type._uchar;
        break;

    case TypeName::WCHAR_T:

        _bits = _type._wchar_t;
        break;

    case TypeName::SHORT:

        _bits = _type._short;
        break;

    case TypeName::USHORT:

        _bits = _type._ushort;
        break;

    case TypeName::INT:

        _bits = _type._int;
        break;

    case TypeName::UINT:

        _bits = _type._uint;
        break;

    case TypeName::LONG:

        _bits = _type._long;
        break;

    case TypeName::ULONG:

        _bits = _type._ulong;
        break;

    case TypeName::LONG_LONG:

        _bits = _type._longLong;
        break;

    case TypeName::ULONG_LONG:

        _bits = _type._ulongLong;
        break;

    case TypeName::FLOAT:

        _bits = _type._float;
        break;

    case TypeName::DOUBLE:

        _bits = _type._double;
        break;

    case TypeName::LONG_DOUBLE:

        _bits = _type._longDouble;
        break;

    default:

        _bits = 0;
        break;
    }
}

}

