#include <iostream>

// function prototype passing by reference using pointers
void swap(int* a, int* b);

// function prototype passing by reference without pointers
void swap(int& a, int& b);

int main()
{
    int a = 3, b = 7;
    std::cout << "Initialization >>          a: " << a << " b: " << b << std::endl; 
    //! Initialization>>           a: 3 b: 7
    swap(&a, &b);
    std::cout << "Swapped using pointers >>   a: " << a << " b: " << b << std::endl;
    //! Swapped using pointers >>   a: 7 b: 3
    swap(a, b);
    std::cout << "Swapped without pointers >> a: " << a << " b: " << b << std::endl;
    //! Swapped without pointers >> a: 3 b: 7
    return 0;
}

// function definition to swap values using pointer as parameters
void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// function definition to swap values without pointer as parameters
void swap(int& a, int& b)
{
    int temp = b;
    b = a;
    a = temp;
}
