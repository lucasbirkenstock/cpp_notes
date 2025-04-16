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

template<typename T>
void also_takes_rval_ref_arg(const T&& param)
{
    std::cout << "Passed function an rvalue reference! const T&& is enough to disqualify being a universal reference. No lvalue references!" << std::endl;
}

