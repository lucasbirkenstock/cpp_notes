#include <iostream>
#include <vector>

template<typename T>
void func(T&& universal_reference_param)
{
    // T&& is a universal reference when used as a template parameter
}

std::string str = "auto&& is a universal reference";
auto&& universal_ref_var = str;

template<typename T>
void takes_rval_ref_arg(std::vector<T>&& param)
{
    std::cout << "Passed function an rvalue reference!" << std::endl;
}



