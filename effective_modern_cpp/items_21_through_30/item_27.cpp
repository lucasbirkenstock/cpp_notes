#include "item_27.h"

/*
Item 27 - Alternatives to overloading universal reference functions
*/

int main ()
{
    auto obj = foo();
    const int i = 5;
    const std::string str = "hello";

    std::cout << "Passing int to funcA" << std::endl;
    obj.funcA(i);

    std::cout << "Passing std::string to funcA" << std::endl;
    obj.funcA(str);


    std::cout << std::endl << std::endl;
    
    const auto p = Parent();
    const auto c = Child();
    const auto b = Bar();

    b.foobar(p); // Parent allowed
    // b.foobar(c); // Child not permitted
    b.foobar("hi"); // Unrelated types permitted
    return 0;
}