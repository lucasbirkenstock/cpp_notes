#include "item_26.h"

/*
Item 26: Avoid overloading functions which take universal references as an argument
*/

int main() 
{
    const short num = 5;
    const std::string str = "Hello";
    const int num_int = 10;



    func(num); 
    /* Num is a short- developer may have expected this call to resolve the overloaded function with an int argument, 
    but actually resolved to the universal reference overload*/
    func(str);
    func(num_int);


    // Overloading universal reference argument function is bad because they can hijack function calls inteded for other overloads
    return 0;
}