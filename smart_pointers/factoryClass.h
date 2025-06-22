#include <iostream>
#include <memory>

class factoryClass
{
    public: 
    ~factoryClass();
    factoryClass();
    factoryClass(const int & i);
    std::unique_ptr<factoryClass> makeFactoryClass(const int i);
    inline int getFoo() {return foo;};

    private: 
    int foo;

};