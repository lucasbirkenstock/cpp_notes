#include "item_24.h"

// Item 24: Distinguish universal references from rvalue references

int main() 
{
    // ***** Universal references must be of the form T&& exactly. If not in the form T&&, it is not a universal reference. .
    std::vector<int> v;
    auto&& ref_to_V = v;
    // takes_rval_ref_arg(v); This doesn't work, v is an lvalue. 
    // takes_rval_ref_arg(ref_to_V); Also doesn't work, it's passed a universal ref. 
    takes_rval_ref_arg(std::move(v)); // This works, std::move has casted v into an rvalue reference. 
    
    /*
    takes_rval_ref_arg() takes an rvalue as a parameter, std::vector<T>&& param. 
    T&& can either mean an rvalue reference or a universal refrence. 
    We pass an lvalue to the function, and the compiler generates an error. When passed an rvalue, it functions as normally
    Proves that universal references must be of form T&& only. std::vector<T>&& is not form T&&. 
    */


}

