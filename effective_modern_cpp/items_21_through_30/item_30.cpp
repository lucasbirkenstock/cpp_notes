#include "item_30.h"

// Item 30: Failure cases for perfect forwarding

int main()
{
    foo(123, "hi", 1.1);

    // Failure point 1: Braced initializers
    // This doesn't work because the type in the braces is of initializer_list, and won't be deduced
    //foo({123, "hi", 1.1});

    return 0;
}