#include <iostream>

class MyBaseClass
{
    public:
        char c;
        int x;
}

class MyDerivedClsss : public MyBaseClass
{
    // c and x also accessible here
}

int main()
{
    MyDerivedClsss obj;
    obj.c = 'A';
    obj.x = 123;

    return 0;
}


