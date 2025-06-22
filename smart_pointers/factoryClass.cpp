#include "factoryClass.h"

factoryClass::~factoryClass()
{
    std::cout << "destroying factoryClass object " << std::endl;
}

factoryClass::factoryClass()
    : foo{5}
{

}

factoryClass::factoryClass(const int & i)
    : foo{i}
{

}

std::unique_ptr<factoryClass> factoryClass::makeFactoryClass(const int i)
{
    return std::make_unique<factoryClass>(i);
}

