#include <iostream>

//!< define namsespace NS1
namespace NS1
{
    int x = 1;
}

//!< define namsespace NS2
namespace NS2
{
    int x = 2;
    namespace NS2NESTED
    {
        int x = 3;
    }
}

int main()
{
    //!< local variable
    int x = 4;

    //!< print x in NS1, NS2, NS2NESTED and local
    std::cout << "NS1::x: " << NS1::x << std::endl; //!< Output >> NS1::x: 1 */
    std::cout << "NS2::x: " << NS2::x << std::endl; //!< Output >> NS2::x: 2 */
    std::cout << "NS2::NS2NESTED::x: " << NS2::NS2NESTED::x << std::endl; //!< Output >> NS2::NS2NESTED::x: 3 */
    std::cout << "x: " << x << std::endl; //!< Output >> x:4 */

    //!< Assign new value to variables
    NS1::x = 11;
    NS2::x = 22;
    NS2::NS2NESTED::x = 33;
    x = 44;

    //!< print x in NS1, NS2, NS2NESTED and local
    std::cout << "NS1::x: " << NS1::x << std::endl; //!< Output >> NS1::x: 11 */
    std::cout << "NS2::x: " << NS2::x << std::endl; //!< Output >> NS2::x: 22 */
    std::cout << "NS2::NS2NESTED::x: " << NS2::NS2NESTED::x << std::endl; //!< Output >> NS2::NS2NESTED::x: 33 */
    std::cout << "x: " << x << std::endl; //!< Output >> x:44 */
}