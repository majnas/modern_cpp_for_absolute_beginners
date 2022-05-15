#include <iostream>

template <typename T>
void funcA(T param)
{
    std::cout << "The generic value is: " << param << std::endl;
}

//! Template specialization
template <>
void funcA(int param)
{
    std::cout << "The int value is: " << param << std::endl;
}

template <typename T, typename U>
void funcB(T t, U u)
{
    std::cout << "T: " << t  << " U: " << u << std::endl;
}

//! To define a class template member functions inside the class
template<typename T>
class MyClassA
{
    private:
        T x;
    public:
        MyClassA(T xx):x(xx){};
        T getvalue() {return this->x;};
};

//! To define a class template member functions outside the class
template<typename T>
class MyClassB
{
    private:
        T x;
    public:
        MyClassB(T xx);
        T getvalue();
};

template<typename T>
MyClassB<T>::MyClassB(T xx):x(xx){};

template<typename T>
T MyClassB<T>::getvalue(){return this->x;};

int main()
{
    funcA<int>(5);
    /* Output >> The int value is: 5 */
    
    funcA<double>(3.8);
    /* Output >> The generic value is: 3.8 */

    funcA<char>('A');
    /* Output >> The generic value is: A */

    funcA<std::string>("www.github.com/majnas");
    /* Output >> The generic value is: www.github.com/majnas */

    funcB<int, std::string>(5, "Hello");
    /* Output >> T: 5 U: Hello */

    funcB<double, char>(3.7, 'A');
    /* Output >> T: 3.7 U: A */

    MyClassA<int> o1{4};
    std::cout << "The value of x is: " << o1.getvalue() << std::endl;
    /* Output >> The value of x is: 4 */

    MyClassB<double> o2{3.7};
    std::cout << "The value of x is: " << o2.getvalue() << std::endl;
    /* Output >> The value of x is: 3.7 */
}