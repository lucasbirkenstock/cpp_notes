#include <iostream> 
#include <memory>
#include "factoryClass.h"

int main() 
{
    factoryClass fc{};

    //auto fac = fc.makeFactoryClass(25);
    // std::cout << fac->getFoo() << std::endl;

    if (true)
    {
        std::cout << "creating heap object to be managed by unique ptr " << std::endl;
        auto ptr = fc.makeFactoryClass(25);
        std::cout << "object created, foo = " << ptr->getFoo() << std::endl;
        std::cout << "unique pointer about to go out of scope" << std::endl;
    }

    
};