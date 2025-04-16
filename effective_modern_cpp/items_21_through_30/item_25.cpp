#include <iostream>

// Item 25: Use std::move on rvalue references and std::forward on universal references

int main () 
{
    // Using std::move leaves the original object in a zombie/empty/null state
    std::string str = "hello";
    std::cout << "Original string object: " <<  str << std::endl;
    std::cout << "Transferring ownership to another string object using std::move" << std::endl;

    std::string str2 = std::move(str);
    std::cout << "Original string object: " << str << std::endl;
    std::cout << "New string object: " << str2 << std::endl;
}