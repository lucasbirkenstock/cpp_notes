#include <iostream>
#include <utility>
template<typename... Ts>
void foo(Ts&&... args)
{   
    (void(std::cout << "Argument passed into variadic template function: " << args << "\n"), ...);
};

template<typename... Ts> 
void fwd(Ts&&... args)
{
    foo(std::forward<Ts>(args)...);
}