#include <iostream>

/*
The static specifier says the object will have a static storage duration. The memory
space for static objects is allocated when the program starts and deallocated when
the program ends. Only one instance of a static object exists in the program. If a local
variable is marked as static, the space for it is allocated the first time the program control
encounters its definition and deallocated when the program exits.
*/
void func()
{
    static int var = 0; // defined only the first time, skipped every other time
    var++;
    std::cout << var << std::endl;
}

/*
We can define static class member fields. Static class members are not part of the
object. They live independently of an object of a class. We declare a static data member
inside the class and define it outside the class.
*/
class MyClass
{
    public:
        static int var; // declare a static data member
        static void func();
};

int MyClass::var = 7; // define a static data member
void MyClass::func()
{
    std::cout << "Hello World from a static member function.";
}

int main()
{
    func();
    /* Output >> 1 */
    func();
    /* Output >> 2 */
    func();
    /* Output >> 3 */

    MyClass o1;
    std::cout << "var: " << o1.var << std::endl;
    /* Output >> var: 7 */

    // changing static data member will change it in all objects
    o1.var = 3; 

    MyClass o2;
    std::cout << "var: " << o2.var << std::endl;
    /* Output >> var: 3 */

    MyClass o3;
    std::cout << "var: " << o3.var << std::endl;
    /* Output >> var: 3 */

    MyClass::func();   // call a static member function
    /* Output >> Hello World from a static member function. */

    return 0;
}