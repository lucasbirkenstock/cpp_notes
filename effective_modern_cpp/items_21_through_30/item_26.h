#include <iostream>

template<typename T> 
void func(T&& arg) 
{
    std::cout << "Called function which takes a universal reference as an argument!" << std::endl;
}

inline void func(int integer) noexcept
{
    std::cout << "Called integer parameter function overload!" << std::endl;
}