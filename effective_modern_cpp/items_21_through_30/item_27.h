#include <iostream>

class foo
{
    public:
    foo() = default;

    // Solution: use tag parameters to implement overloading. std::is_integral is the tag. 
    template<typename T>
    void funcA(T&& name)
    {
        // Evaluates if T is an integral type or not and calls the correct function overload based on that
        funcA(name, std::is_integral<typename std::remove_reference<T>::type>());
    }

    private:
    // Only called if T is not an integral type
    template<typename T>
    void funcA(T&& name, std::false_type)
    {
        std::cout << "Overload function #1 with std::false_type" << std::endl;
    }

    // Only called if T is an integral type
    template<typename T>
    void funcA(T&& name, std::true_type)
    {
        std::cout << "Overload function #2 with std::true_type" << std::endl;
    }

};


class Parent
{
    public:
    Parent() = default;
};

class Child : Parent
{
    public:
    Child() 
    : Parent()
    {

    }
};

class Bar
{
    public:
    template<typename T, typename = std::enable_if_t<!std::is_base_of<Parent, std::decay_t<T>>::value || std::is_same<Parent, std::decay_t<T>>::value >>
    void foobar(T&& arg) const
    {
        std::cout << "Entered body of template function which does not accept arguments which are children of the parent class" << std::endl;
    }
};