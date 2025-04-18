#include <iostream>

template<typename... Ts>
void foo(Ts&&... args)
{   
    int i{1};
    ((std::cout << "Argument passed into variadic template function: " << args << "\n"), ...);
};