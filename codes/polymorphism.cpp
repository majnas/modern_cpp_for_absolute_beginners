#include <iostream> 
using namespace std;
 
 /* https://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm */
class Shape 
{
    protected:
        int width, height;
      
    public:
        Shape( int a = 0, int b = 0)
        {
            width = a;
            height = b;
        }
        /*
        Virtual specifier means this function can be overridden/redefined in subsequent derived classes,
        and the appropriate version will be invoked through a polymorphic object
        */
        virtual int area() 
        {
            std::cout << "Parent class area :" << std::endl;
            return 0;
        }
};

class Rectangle: public Shape 
{
    public:
        Rectangle( int a = 0, int b = 0):Shape(a, b) { }
      
        int area () 
        { 
            std::cout << "Rectangle class area :" << std::endl;
            return (width * height); 
        }
};

class Triangle: public Shape {
    public:
        Triangle( int a = 0, int b = 0):Shape(a, b) { }
      
        int area () 
        { 
            std::cout << "Triangle class area :" << std::endl;
            return (width * height / 2); 
        }
};

// Main function for the program
int main() 
{
    Shape *shape;
    Rectangle rec(10,7);
    Triangle  tri(10,5);

    // store the address of Rectangle
    shape = &rec;
   
    // call rectangle area.
    shape->area();
    /* Output >> Rectangle class area : */

    // store the address of Triangle
    shape = &tri;
   
    // call triangle area.
    shape->area();
    /* Output >> Triangle class area : */
   
    return 0;
}
