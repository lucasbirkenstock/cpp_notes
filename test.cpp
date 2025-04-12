#include <iostream>
template <typename T> 
void printType(T&& arg) noexcept
{
    if (std::is_lvalue_reference<decltype(arg)>::value)
    {
        std::cout << "I'm an lvalue reference!" << std::endl;
    } 
    else if (std::is_rvalue_reference<decltype(arg)>::value)
    {
        std::cout << "I'm an rvalue reference!" << std::endl;
    }
    else 
    {
        std::cout << "I'm neither" << std::endl;
    }
}

int main()
{
    int a = 5;
    printType(a);
    std::cout << "Applying std::move" << std::endl;
    printType(std::move(a));
    return 0;
}


