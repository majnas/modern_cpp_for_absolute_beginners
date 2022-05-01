#include <iostream>

class MyClass
{
    private:
        int a, b;
    public:
        MyClass();                              // default constractor
        MyClass(int a, int b);                  // constractor with arguments
        MyClass(const MyClass& rhs);            // copy constractor
        MyClass& operator=(const MyClass& rhs); // copy assignment same tyep
        MyClass& operator=(int a);              // copy assignment with different type!!!
        void print();
};

MyClass::MyClass(){}                                     
MyClass::MyClass(int aa, int bb):a(aa),b{bb}{}           
MyClass::MyClass(const MyClass& rhs):a(rhs.a),b(rhs.b){} 
MyClass& MyClass::operator=(const MyClass& rhs)          
{
    return *this;
}

MyClass& MyClass::operator=(int a)
{
    this->a = a;
    return *this;
}

void MyClass::print()
{
    std::cout << "a: " << this->a << " b: " << this->b << std::endl;
}

int main()
{
    // constractor with arguments
    MyClass c1(2,6);
    c1.print();
    /* output >> a: 2 b: 6   */

    // copy constractor
    MyClass c2 = c1;
    c2.print();
    /* output >> a: 2 b: 6   */
    
    // default constractor
    MyClass c3;
    c3.print();
    /* output >> a: 3213983134 b: -2135132   */

    // copy assignment same type
    c3 = c1;
    c3.print();
    /* output >> a: 3213983134 b: -2135132   */

    // copy assignment with different type!!!
    c3 = 77;
    c3.print();
    /* output >> a: 77 b: -2135132   */

    return 0;
}
