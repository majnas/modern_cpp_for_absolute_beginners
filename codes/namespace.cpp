#include <iostream>

namespace NS1
{
    int x = 1;
}

namespace NS2
{
    int x = 2;
}

int main()
{
    int x = 3;

    // print x in NS1 namespace
    std::cout << "NS1::x: " << NS1::x << std::endl;

    // print x in NS2 namespace
    std::cout << "NS2::x: " << NS2::x << std::endl;

    // print local variable x
    std::cout << "x: " << x << std::endl;
}