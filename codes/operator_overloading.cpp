#include <iostream>

class Complex 
{
    private:
        int r;
        int i;

    public:
        // Constractors declarations
        Complex();
        Complex(int r, int i);
        Complex(const Complex& rhs);

        // Operator overloading declarations
        Complex operator++();                   // prefix operator ++
        Complex operator++(int);                // postfix operator ++
        Complex operator+(const Complex& rhs);
        Complex operator+(int r);
        Complex operator+(std::string istr);
        void print();
};

// Constractors definitions
Complex::Complex():r(0),i(0){};
Complex::Complex(int r, int i): r{r}, i{i}{};
Complex::Complex(const Complex& rhs): r{rhs.r}, i{rhs.i}{};

// Overload prefix operator ++
Complex Complex::operator++()
{
    ++this->r; // or this->r++;
    ++this->i; // or this->i++;
    return *this;
}

// Overload postfix operator ++
Complex Complex::operator++(int)
{
    Complex tmp = *this;
    this->r++;
    this->i++;
    return tmp;
}

// Overload operator + with same class
Complex Complex::operator+(const Complex& rhs)
{
    // Instantiate new Complex object using constractor
    return Complex(r + rhs.r, i + rhs.i);
}

// Overload operator + with type int!!!!
Complex Complex::operator+(int r)
{
    // Instantiate new Complex object using constractor
    return Complex(this->r + r, this->i);
}

// Overload operator + with type string
Complex Complex::operator+(std::string istr)
{
    int i = std::stoi(istr.substr(0, istr.size()-1));
    // Instantiate new Complex object using constractor
    return Complex(this->r, this->i + i);
}

void Complex::print()
{
    std::cout << this->r << std::string((this->i > 0)? "+" : "") << this->i << "i"  << std::endl;
}

int main()
{
    Complex c2(5, 6);
    c2.print();
    /* output >> 5+6i */

    ++c2;
    c2.print();
    /* output >> 6+7i */

    c2++;
    c2.print();
    /* output >> 7+8i */

    Complex c31(2, 1);
    Complex c32(3, -3);
    Complex c3 = c31 + c32; // Same as Complex c3 = c31.operator+(c32)
    c3.print(); 
    /* output >> 5-2i */

    c3 = c31 + Complex(3, -6);  // 1) operator+   2) default copy assignment
    c3.print(); 
    /* output >> 5-5i */

    Complex c4 = c31 + Complex(3, -4); // 1) operator+   2) copy constractor
    c4.print();
    // /* output >> 5-3i */

    Complex c5 = Complex(2, 7) + Complex(3, 5); // 1) operator+   2) copy constractor
    c5.print();
    // /* output >> 5+12i */

    c3 = Complex(2, -4) + 3;
    c3.print();
    // /* output >> 5-4i */

    c3 = Complex(2, -4) + "-3i";
    c3.print();
    // /* output >> 2-7i */

    Complex c6(c3);
    c6.print();
    // /* output >> 2-7i */

    return 0;
}
