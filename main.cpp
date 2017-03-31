#include "anytype.h"

#include <iostream>
#include <exception>

using namespace SpaceOfTypes;

int main()
{
    int x = 98;

    AnyType any = x;

    AnyType any2 = any;

    try{

        any2.toDouble();

    }
    catch (std::exception &e){

        std::cout << e.what() << std::endl;
    }

    any2.getTypeName();

    any = any2;

    try{

        any.getDoubleData();
    }
    catch (std::exception &e){

        std::cout << e.what() << std::endl;
    }

    try{

        any.getLongData();
    }
    catch (std::exception &e){

        std::cout << e.what() << std::endl;
    }


    std::cout << "data is: " << any.getDoubleData() << " type is: " << any.getTypeName() << std::endl;

    return 0;
}
