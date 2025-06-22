#include <iostream>
#include <vector>
#include <map>

int main() 
{
    std::vector<int> nums = {5, 50, 10, 25};

    // Using an iterator
    // First: Create an iterator object
    auto it = nums.begin();

    std::cout << "Printing all elements of the integer vector " << std::endl;

    // Loop through the iterator, access elements within the vector by dereferencing
    while (it != nums.end())
    {
        std::cout << *it << std::endl;
        // Increment the iterator, or it indefinitely accesses the first element
        ++it;
    }

    // STL map example
    std::map<std::string, int> ageMap = 
    {
        {"aaa", 15},
        {"bbb", 25},
        {"ccc", 35},
        {"ddd", 45}
    };

    auto mapIterator = ageMap.begin();

    // this can be done with a for each loop better, but wanted to try this
    while (mapIterator != ageMap.end())
    {
        std::cout << mapIterator->first << " is " << mapIterator->second << " years old. " << std::endl;
        ++mapIterator;
    }

    std::cout << "going in reverse" << std::endl;
    while (mapIterator != ageMap.begin())
    {
        // Segfault if decrement not done first. Need to move to previous VALID element first. 
        --mapIterator;
        std::cout << mapIterator->first << " is " << mapIterator->second << " years old. " << std::endl;
        
    }


    return 0;
}