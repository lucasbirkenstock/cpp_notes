#include "item_30.h"

// Item 30: Failure cases for perfect forwarding

int main()
{
    foo(123, "hi", 1.1);

    // Failure point 1: Braced initializers
    // This doesn't work because the type in the braces is of initializer_list, and won't be deduced
    //foo({123, "hi", 1.1});

    // This also breaks everything. 
    //auto initList= {1,2,3};
    //fwd(initList);

    // This works: this is standard variable initialization with braces. It isn't multiple items going into a container. Braces with multiple items/containers breaks std::forward. 
    int i{5};
    fwd(i);

    // Also fine
    fwd(1,1,1,1);

    return 0;
}